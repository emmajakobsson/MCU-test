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
    uint8_t data = -3;

    printf("Hejhej\n");
    configure_i2c();
    data = read_imu(data);
    //printf("Sensor: %u\n",data);
    //vTaskDelay(100);
    i2c_driver_delete(I2C_MASTER_NUM);
    while(1){
        
        //data = read_imu(data);

        
        //printf("Sensor: %u\n",data);

        
    }

}
