#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "driver/i2c.h"

#ifndef HEADER_FILE
#define HEADER_FILE

void configure_sensor(void);
void configure_i2c(void);

#endif