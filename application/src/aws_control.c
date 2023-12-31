#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#include <FreeRTOS.h>
#include <task.h>

#include <vfs.h>
#include <fs/vfs_romfs.h>

#include "aws_iot_config.h"
#include "aws_iot_log.h"
#include "aws_iot_version.h"
#include "aws_iot_mqtt_client_interface.h"
#include "aws_iot_shadow_interface.h"
#include "aws_cert.h"
#include "blog.h"
#include <bl_gpio.h>

#define GPIO_LED_PIN 3

static void disconnectCallbackHandler(AWS_IoT_Client* pClient, void* data) {
	blog_info("MQTT Disconnect");
	IoT_Error_t rc = FAILURE;

	if (NULL == pClient) {
		return;
	}

	if (aws_iot_is_autoreconnect_enabled(pClient)) {
		blog_info("Auto Reconnect is enabled, Reconnecting attempt will start now");
	}
	else {
		blog_info("Auto Reconnect not enabled. Starting manual reconnect...");
		rc = aws_iot_mqtt_attempt_reconnect(pClient);
		if (NETWORK_RECONNECTED == rc) {
			blog_info("Manual Reconnect Successful");
		}
		else {
			blog_error("Manual Reconnect Failed - %d", rc);
		}
	}
}


static void iot_subscribe_callback_handler(AWS_IoT_Client* pClient, char* topicName, uint16_t topicNameLen,
									IoT_Publish_Message_Params* params, void* pData) {
	blog_info("Subscribe callback");
	if (*(char *)params->payload == '1') {
		blog_info("Enabling Led");
        bl_gpio_output_set(GPIO_LED_PIN, 1);
		vTaskDelay(250);
        bl_gpio_output_set(GPIO_LED_PIN, 0);
	}
	blog_info("%.*s\t%.*s", topicNameLen, topicName, (int)params->payloadLen, (char*)params->payload);
}

void aws_iot_control(void* arg)
{
	bl_gpio_enable_output(GPIO_LED_PIN, 0, 0);
	IoT_Error_t rc = FAILURE;

	AWS_IoT_Client client;
	IoT_Client_Init_Params mqttInitParams = iotClientInitParamsDefault;
	IoT_Client_Connect_Params connectParams = iotClientConnectParamsDefault;

	blog_info("\nAWS IoT SDK Version %d.%d.%d-%s", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, VERSION_TAG);

	mqttInitParams.enableAutoReconnect = false;
	mqttInitParams.pHostURL = MQTT_HOST;
	mqttInitParams.port = MQTT_PORT;
	mqttInitParams.pRootCALocation = ROOT_CA_FILENAME;
	mqttInitParams.pDeviceCertLocation = CERTIFICATE_FILENAME;
	mqttInitParams.pDevicePrivateKeyLocation = PRIVATE_KEY_FILENAME;
	mqttInitParams.mqttCommandTimeout_ms = 20000;
	mqttInitParams.tlsHandshakeTimeout_ms = 5000;
	mqttInitParams.isSSLHostnameVerify = true;
	mqttInitParams.disconnectHandler = disconnectCallbackHandler;
	mqttInitParams.disconnectHandlerData = NULL;

	rc = aws_iot_mqtt_init(&client, &mqttInitParams);
	if (SUCCESS != rc) {
		blog_info("-------------------aws_iot_mqtt_init returned error : %d ", rc);
		goto exit;
	}

	connectParams.keepAliveIntervalInSec = 600;
	connectParams.isCleanSession = true;
	connectParams.MQTTVersion = MQTT_3_1_1;
	connectParams.pClientID = MQTT_CLIENT_ID;
	connectParams.clientIDLen = (uint16_t)strlen(MQTT_CLIENT_ID);
	connectParams.isWillMsgPresent = false;

	blog_info("Connecting...");
	rc = aws_iot_mqtt_connect(&client, &connectParams);
	if (SUCCESS != rc) {
		blog_error("Error(%d) connecting to %s:%d ", rc, mqttInitParams.pHostURL, mqttInitParams.port);
		goto exit;
	}
	/*
	 * Enable Auto Reconnect functionality. Minimum and Maximum time of Exponential backoff are set in aws_iot_config.h
	 *	#AWS_IOT_MQTT_MIN_RECONNECT_WAIT_INTERVAL
	 *	#AWS_IOT_MQTT_MAX_RECONNECT_WAIT_INTERVAL
	 */
	rc = aws_iot_mqtt_autoreconnect_set_status(&client, true);
	if (SUCCESS != rc) {
		blog_error("Unable to set Auto Reconnect to true - %d", rc);
		goto exit;
	}

	blog_info("Connect ok!!!, start Subscribing Topic=[%s]...", SUBTOPIC);
	rc = aws_iot_mqtt_subscribe(&client, SUBTOPIC, strlen(SUBTOPIC), QOS1, iot_subscribe_callback_handler, NULL);
	if (SUCCESS != rc) {
		blog_error("Error subscribing : %d , topic=[%s]", rc, SUBTOPIC);
		goto exit;
	}

	while ((NETWORK_ATTEMPTING_RECONNECT == rc || NETWORK_RECONNECTED == rc || SUCCESS == rc)) {
		//Max time the yield function will wait for read messages
		rc = aws_iot_mqtt_yield(&client, 100);
		if (NETWORK_ATTEMPTING_RECONNECT == rc) {
			// If the client is attempting to reconnect we will skip the rest of the loop.
			continue;
		}
		vTaskDelay(1000);
	}
exit:
	blog_info("\ntest task exit ");
	if (SUCCESS != rc) {
		blog_error("An error occurred in the loop %d", rc);
	}
	aws_iot_mqtt_yield(&client, 100);
	aws_iot_mqtt_disconnect(&client);
	aws_iot_mqtt_free(&client);
	vTaskDelete(NULL);
}

