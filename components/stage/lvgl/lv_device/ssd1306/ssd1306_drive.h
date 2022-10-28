/**
 * @file oled_drive.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-10-27
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef SSD1306_DRIVE_H
#define SSD1306_DRIVE_H
#include <hosal_i2c.h>
#include <bl_gpio.h>


#define OLED_IIC_SCL 12
#define OLED_IIC_SDA 3

 //Set display direction
 //LV_DISPLAY_ORIENTATION_LANDSCAPE :normal
 // LV_DISPLAY_ORIENTATION_LANDSCAPE_INVERTED: inversion
#define LV_DISPLAY_ORIENTATION_LANDSCAPE 
// #define LV_DISPLAY_ORIENTATION_LANDSCAPE_INVERTED

//Set color display
// LV_INVERT_COLORS:Negative display
// #define LV_INVERT_COLORS

hosal_i2c_dev_t* oled_i2c_driver_init(int oled_scl, int oled_sda);
void oled_drive_set_pixels(uint8_t x, uint8_t y, char color_p);
int oled_refresh_screen(void);
int oled_drive_sleep(void);
int oled_drive_awaken(void);
#endif