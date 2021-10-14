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
    uint8_t reg_addr = 0xFF; //output register 0x24
    uint8_t data[50] = {-2}; //82 highest value
    int flag = 0;

    configure_i2c_master();
    
    while(1){
        i2c_master_write_read_device(I2C_MASTER_NUM, SLAVE_ADDR, &reg_addr, 1, data, sizeof(data), I2C_MASTER_TIMEOUT_MS/portTICK_RATE_MS);

        for(int i = 0; i < 10; i++){
            if(data[i] == 71 && data[i + 1] == 76 && data[i + 2] == 76){
                flag = 1;
                break;
            }
        }

        for(int j = 0; j < 50; j++){
            if(flag == 1)
                printf("%c", (char)data[j]); //02x hhn
        }

        if(flag == 1){
            printf("\n");
        }

        flag = 0;
        memset(data,-2,sizeof(uint8_t));
        //vTaskDelay(100);
    }
}
