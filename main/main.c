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
    uint8_t data[82] = {-2}; //82 highest value
    //int flag = 0;

    configure_i2c_master();
    
    while(1){

        //read data from the sensor
        i2c_master_write_read_device(I2C_MASTER_NUM, SLAVE_ADDR, &reg_addr, 1, data, sizeof(data), I2C_MASTER_TIMEOUT_MS/portTICK_RATE_MS);

        //print the data from the buffer
        for(int j = 0; j < 82; j++){
            printf("%c", (char)data[j]); //02x hhn
        }

        //filtering of messages
        /*for(int i = 0; i < 10; i++){
            if(data[i] == 71 && data[i + 1] == 76 && data[i + 2] == 76){
                flag = 1;
                break;
            }
        }

        if(flag == 1){
            for(int j = 0; j < 50; j++){
                printf("%c", (char)data[j]); //02x hhn
            }
            printf("\n");
        }

        flag = 0;*/
        //reset the buffer with values
        memset(data,94,sizeof(uint8_t));
        //vTaskDelay(100);
    }
}
