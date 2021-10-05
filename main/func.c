#include "func.h"

//configure adc sensor reading
void configure_sensor(void){
    //reset pins
    gpio_reset_pin(ADC1_CHANNEL_5);
    /* Set the GPIO as a push/pull output */
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_5,ADC_ATTEN_6db);
}

//configure i2c master
void configure_i2c_master(void){
    i2c_config_t conf = { 
                        .mode = I2C_MODE_MASTER,
                        .sda_io_num = 21,
                        .scl_io_num = 22,
                        .sda_pullup_en = GPIO_PULLUP_ENABLE,
                        .scl_pullup_en = GPIO_PULLUP_ENABLE,
                        .master.clk_speed = I2C_MASTER_FREQ_HZ};

    i2c_param_config(I2C_MASTER_NUM,&conf);
    i2c_driver_install(I2C_MASTER_NUM, conf.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
}

//read i2c master
void read_master_imu(uint8_t *data){
    // uint8_t *temp;
    // temp = malloc(40);

    //i2c_master_write_to_device();
    uint8_t reg_addr = 0x0B; //0x0F

    //i2c_master_read_from_device(I2C_MASTER_NUM, SLAVE_ADDR, data, 512, I2C_MASTER_TIMEOUT_MS/portTICK_RATE_MS);

    i2c_master_write_read_device(I2C_MASTER_NUM, SLAVE_ADDR, &reg_addr, 1, data, 4, I2C_MASTER_TIMEOUT_MS/portTICK_RATE_MS);

    // printf("%u", temp[0]);
    // *data = *temp;
}
