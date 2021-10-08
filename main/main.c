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
    int iter = 0;

    //configure i2c master
    configure_i2c_master();
    //configure IMU/sensor
    //configure_imu();
    
    while(1){
        //read from device
        read_master_imu(&data);
        //print values
        //printf("\e[1;1H\e[2J"); //clear terminal, keep print to one line
        //printf("iteration: %d\n", iter);
        if(data == 36){
            printf("Start transmisson\n");
            while(data != (13 || 10)){
                if(data == (240)){
                    printf("yay\n");
                }
                printf("Sensor: %c\n", (char)data); //02x hhn
                vTaskDelay(100);
                read_master_imu(&data);
            }
        }
        iter++;
    }
}
