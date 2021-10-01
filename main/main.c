#include "func.h"

void app_main(void)
{
    int data = -2;

    configure_sensor();

    while(1){
        data = adc1_get_raw(ADC1_CHANNEL_5);
        printf("Sensor reading: %d\n",data);
        vTaskDelay(100);
    }
}
