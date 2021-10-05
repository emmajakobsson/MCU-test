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

    configure_i2c_master();
    
    while(1){
        read_master_imu(&data);
        printf("Count: %d\n", count);
        for(i = 0; i < 1; i++){
            printf("Sensor: %08x\n", data); //02x hhn
        }
        count++;
        vTaskDelay(100);
    }
}
