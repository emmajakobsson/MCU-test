#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/adc.h"
#include "driver/i2c.h"
#include "malloc.h"

#define I2C_MASTER_FREQ_HZ 400000
#define I2C_MASTER_NUM 0
#define I2C_MASTER_TX_BUF_DISABLE 0
#define I2C_MASTER_RX_BUF_DISABLE 0
#define I2C_MASTER_TIMEOUT_MS 1000
#define SLAVE_ADDR 0x6B //1101011b //0x42 //66

#ifndef HEADER_FILE
#define HEADER_FILE

void configure_sensor(void);
void configure_i2c_master(void);
void read_master_imu(uint8_t *data);

#endif