#include "func.h"

//configure adc sensor reading
void configure_sensor(void){
    //reset pins
    gpio_reset_pin(ADC1_CHANNEL_5);
    /* Set the GPIO as a push/pull output */
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_5,ADC_ATTEN_6db);
}

//configure i2c
void configure_i2c(void){
    i2c_config_t conf = { 
                        .mode = I2C_MODE_MASTER,
                        .sda_io_num = 21, //I2C_NUM_0
                        .scl_io_num = 22,
                        .sda_pullup_en = GPIO_PULLUP_ENABLE,
                        .scl_pullup_en = GPIO_PULLUP_ENABLE,
                        .master.clk_speed = I2C_MASTER_FREQ_HZ};

    i2c_param_config(I2C_MASTER_NUM,&conf);
    i2c_driver_install(I2C_MASTER_NUM, conf.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
}

//read
uint8_t read_imu(uint8_t data){
    i2c_master_read_from_device(I2C_MASTER_NUM, (uint8_t)1101010, &data, 1, I2C_MASTER_TIMEOUT_MS/portTICK_RATE_MS);
    return data;
}