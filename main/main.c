#include "func.h"

void app_main(void)
{
    //int data = -2;

    //configure_sensor();

    /*while(1){
        data = adc1_get_raw(ADC1_CHANNEL_5);
        printf("Sensor reading: %d\n",data);
        vTaskDelay(100);
    }*/
    uint8_t data;

    //configure i2c master
    configure_i2c_master();
    //configure IMU/sensor
    write_slave_reg();
    
    while(1){
        //read from device
        read_master_imu(&data);
        //print values
        printf("Sensor: %d\n", data); //02x hhn
        vTaskDelay(100);
    }
}
