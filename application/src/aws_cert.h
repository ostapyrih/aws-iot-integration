#ifndef _AWS_CERT_H_
#define _AWS_CERT_H_

#define ROOT_CA_FILENAME                                                   \
    "-----BEGIN CERTIFICATE-----\r\n"                                      \
    "MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF\r\n" \
    "ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6\r\n" \
    "b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL\r\n" \
    "MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv\r\n" \
    "b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj\r\n" \
    "ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM\r\n" \
    "9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw\r\n" \
    "IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6\r\n" \
    "VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L\r\n" \
    "93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm\r\n" \
    "jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC\r\n" \
    "AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA\r\n" \
    "A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI\r\n" \
    "U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs\r\n" \
    "N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv\r\n" \
    "o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU\r\n" \
    "5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy\r\n" \
    "rqXRfboQnoZsG4q5WTP468SQvvG5\r\n" \
    "-----END CERTIFICATE-----\r\n"


#define CERTIFICATE_FILENAME                                               \
    "-----BEGIN CERTIFICATE-----\r\n"                                      \
    "MIIDWTCCAkGgAwIBAgIUPFSXvkW6MYnvQAjWkXAnM2wVikcwDQYJKoZIhvcNAQEL\r\n" \
    "BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g\r\n" \
    "SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTIzMDIyMzE3MjYy\r\n" \
    "NloXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0\r\n" \
    "ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALCQAOfmjXq5IGVN8Z3D\r\n" \
    "bVmljnHINTIAnrNyNIqmF9lcbGtV8MJKKWZ9nXacAFp23vhna/FKe3eX7aYs5EvB\r\n" \
    "ROsbno/fWb9I8tBW0gcl9TKNC5OAtA1qoymocQY8UU6a9R7vh2Wtb7jYlABrbGrw\r\n" \
    "AA3rn54fYHMEoTHi+Cyrwho5lQZnR5ZAP7EMi461BnIGtM3raw4o8Jf2wFbcZPTu\r\n" \
    "4X3vmX+EhqiRCbpootYyJbPgY7HCb1+3wDvk7A6Ka4ej4t7PaZTT+NtODaKx8XCr\r\n" \
    "QOBvygQGwbd5feP0QJGkMoslMRrUrdOP3KXRUJJkWEEAqGaYnIA4y138Md+sSog8\r\n" \
    "2DECAwEAAaNgMF4wHwYDVR0jBBgwFoAUoradL6ZG/ZnM2Cc9RILQDOZEVHIwHQYD\r\n" \
    "VR0OBBYEFDiT2hyWq6c4Wa89yZano8aVfddFMAwGA1UdEwEB/wQCMAAwDgYDVR0P\r\n" \
    "AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQCwUzwxQ0npY3eQKi9uvtzyRjEy\r\n" \
    "EgQ9hUTywgL0madOeq1He78XSl7YiSyy8Sw6n9seSlWL9VuSP+PLYMktreZQub5k\r\n" \
    "eWMIl5dmRk6ntxI8jAxxIEKEBoa6eQW/Qj2fEWtG+5N3Io4b0BursZZBuknp3Fsl\r\n" \
    "llicHrx1gMj+FO2TTUcUQxHj55eS5bZgf2YvN46a466d5XFiv3DwERbpgXVFsjPa\r\n" \
    "eueD5OcuK0+exIGIiCpDtVzET09tPaik7DD6Qeenw2IUPsI1k0qyHeMJ3+UVSWdp\r\n" \
    "kYBUCDyTQx5T8doJQ+8fst7bwc1/VEtCK+/GWKWnq8LAUi4tqChYX36tqnmo\r\n" \
    "-----END CERTIFICATE-----\r\n"

#define PRIVATE_KEY_FILENAME                                               \
    "-----BEGIN RSA PRIVATE KEY-----\r\n"                                  \
    "MIIEogIBAAKCAQEAsJAA5+aNerkgZU3xncNtWaWOccg1MgCes3I0iqYX2Vxsa1Xw\r\n" \
    "wkopZn2ddpwAWnbe+Gdr8Up7d5ftpizkS8FE6xuej99Zv0jy0FbSByX1Mo0Lk4C0\r\n" \
    "DWqjKahxBjxRTpr1Hu+HZa1vuNiUAGtsavAADeufnh9gcwShMeL4LKvCGjmVBmdH\r\n" \
    "lkA/sQyLjrUGcga0zetrDijwl/bAVtxk9O7hfe+Zf4SGqJEJumii1jIls+BjscJv\r\n" \
    "X7fAO+TsDoprh6Pi3s9plNP4204NorHxcKtA4G/KBAbBt3l94/RAkaQyiyUxGtSt\r\n" \
    "04/cpdFQkmRYQQCoZpicgDjLXfwx36xKiDzYMQIDAQABAoIBACEG3tSCIOba6D9q\r\n" \
    "5A5Rtwu01z9bZu/yg70nWMKyrPVgv3sYeU+ula3xQ1ojdkF1yOGIXv2kpBHL3o1e\r\n" \
    "ClpNTbn40aEx81S/rYPhKapipEoPbiHqSkPUNa8eLf4vnDnq7H0b6yTO234lLRIj\r\n" \
    "BgW+3RO9hn8KeX0qWYi+XxPkEQvceAUNAXQeoh1o4hGy9UEPLr6o3a+oPvqgQqsy\r\n" \
    "BSC4xw7JJ9NUCEMGKe8PSItdnVTkr4Hd0XpkpW1FCu1Z/ivYxLh7pNvAB9oW/I1Q\r\n" \
    "b9SSGX1Tv2x4fjTVTixWNPbdGghpq8Rz0yCQeF5FubvcNhEzbpxq+JEQyoTFtIxi\r\n" \
    "zrXrF+0CgYEA1TkZodv3KKiUg3u98h2F/24rPVqZnNls1RjTzAhTOCjSoy4Vv2Kv\r\n" \
    "pP4xQzBvlVBeIB8MDyfFfZIjBVV+L4trDPTshBC9UIeWB9u5f2reoyog4i7hpuQx\r\n" \
    "8ZVTeB0y+jN35prlu1SR4KicxrYbf0ayJB3TXD5UoF5IUZn0/opA/WcCgYEA0/wP\r\n" \
    "F+lFA1GpmMyhxl/6pWxJ1FrKDoANjojs1m3PjzJReB1FWxmPAzAW43dFoTBIjpJp\r\n" \
    "yscyz/TndwjM2Dt6CkgvQdRtHq/rQU6qfNGddjwuhZig/LoFjxI06wOcsynN0obK\r\n" \
    "mXHIJn2W7/GAoGXs36DB+QapJDiaZH/IezFL5qcCgYBRaxFXlgfltaGoJ1sblZxy\r\n" \
    "Md4++laH5xpAsM9HLLKiUixEdTeGsidByHKFJnylNmAKwfA35UbrMR9ATSn2+7Sv\r\n" \
    "6OJbd4zisDNg4s0NU4CaK18NHzu5H4/WoN+TkQrDMV4KZ4Frq9pcP+ZFloofap5h\r\n" \
    "XiY0JfTom7ffuPstKxuv5wKBgD4bbkyiIn8bcOX8pjUZr7TBqkvWIbbn25D0Gvek\r\n" \
    "Cpi4tFfNs6FCNr1HXJ1eN39HRyrGSMqJXCDDbwFYCbQckN/sUDQoSaQhBHsI0jhp\r\n" \
    "rYmTjknD8v64faJyQiDM2R9A0zWoGjmktXBZgVxhVD8qPaEzV0FfqzSahNmG+rTl\r\n" \
    "N4inAoGAcWfAwipqdPNkEKpL3ZsYznmFnw/Nfg0qCrANgGIUo4rhZqdgSgQA9wya\r\n" \
    "ayD1VbBPcGGthlgj4FahBaRX+aCVbHQMpENwcx1lifLtrFA6hruwY30Udr+tZYic\r\n" \
    "7DaOUc+JR4BdU1tfhO5V9HqxT4r6tnZoIUMp559xRGjSKE7qdfM=\r\n" \
    "-----END RSA PRIVATE KEY-----\r\n"

#define MQTT_HOST "a1s09sne730oa0-ats.iot.us-west-2.amazonaws.com"
#define MQTT_PORT 443
#define MQTT_CLIENT_ID "iotconsole-1fdacc64-10ac-4b49-a766-87c16f8886f3"
#define MY_THING_NAME "garage_door"

#define SUBTOPIC "$aws/things/garage_door/pulse"

#endif
