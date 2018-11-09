## Local build configuration
## Parameters configured here will override default and ENV values.
## Uncomment and change examples:

## Add your source directories here separated by space
#MODULES = app
# EXTRA_INCDIR = include

## ESP_HOME sets the path where ESP tools and SDK are located.
#ESP_HOME = /opt/esp-open-sdk

## SMING_HOME sets the path where Sming framework is located.
#SMING_HOME = /opt/Sming/Sming

## COM port parameter is reqruied to flash firmware correctly.
# COM_PORT = /dev/tty.usbserial
#COM_PORT = /dev/ttyUSB0

## Com port speed
COM_SPEED	= 115200

## Configure flash parameters (for ESP12-E and other new boards):
# SPI_MODE: qio, qout, dio, dout

## SPIFFS options
DISABLE_SPIFFS = 1

