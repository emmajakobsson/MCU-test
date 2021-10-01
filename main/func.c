#include "func.h"

void configure_sensor(void){
    //reset pins
    gpio_reset_pin(ADC1_CHANNEL_5);
    /* Set the GPIO as a push/pull output */
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_5,ADC_ATTEN_6db);
}

void configure_i2c(void){
    i2c_config_t conf = { 
                        .mode = ,
                        .sda_io_num = ,
                        .scl_io_num = ,
                        .sda_pullup_en = ,
                        .scl_pullup_en = ,
                        .clk_speed = };
    
    
}