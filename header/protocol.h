#include "string.h"
#include <stdio.h>

#include "driver/gpio.h"
#include "driver/adc.h"
#include "driver/i2c.h"
#include "driver/uart.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//I2C
#define I2C_MASTER_FREQ_HZ 400000 
#define I2C_MASTER_NUM 0
#define I2C_MASTER_TX_BUF_DISABLE 0
#define I2C_MASTER_RX_BUF_DISABLE 0
#define I2C_MASTER_TIMEOUT_MS 1000
#define SLAVE_ADDR 0x42 

//UART
#define TX_PIN 1
#define RX_PIN 3

#ifndef HEADER_FILE
#define HEADER_FILE

void configure_adc(void);
void configure_i2c_master(void);
void configure_uart(void);

#endif