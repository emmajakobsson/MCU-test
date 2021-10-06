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
    int i = 0;
    int count = 0;

    //configure i2c master
    configure_i2c_master();
    //configure IMU/sensor
    write_slave_reg();
    
    while(1){
        //read from device
        read_master_imu(&data);
        //print values
        printf("Count: %d\n", count);
        for(i = 0; i < 1; i++){
            printf("Sensor: %d\n", data); //02x hhn
        }
        count++;
        vTaskDelay(100);
    }
}
