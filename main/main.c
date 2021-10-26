#include "nmea.h"
#include "protocol.h"

int app_main(void)
{
    /*while(1){
        data = adc1_get_raw(ADC1_CHANNEL_5);
        printf("Sensor reading: %d\n",data);
        vTaskDelay(100);
    }*/

    uint8_t reg_addr = 0xFF; //output register
    uint8_t data[82] = {INIT};
    printf("\nHEAP: %d\n", xPortGetFreeHeapSize());
    char * msg = calloc(82,1);

    configure_i2c_master();
    int res = 2;
    while(1){
        //read data from the sensor
        i2c_master_write_read_device(I2C_MASTER_NUM, SLAVE_ADDR, &reg_addr, 1, data, sizeof(data), I2C_MASTER_TIMEOUT_MS/portTICK_RATE_MS);

        int i = 0;
        while(data[i] != 42){
            msg[i] = (char)data[i];
            i++;
        }
        /*for(int i = 0; i < 82; i++){
            
        }*/
        res = match(msg,NMEA_MESSAGES);
        printf("\nmatch: %d\n", res);
        //print the data from the buffer
        if(res == 1){
            i = 0;
            while(msg[i] != '*'){
                printf("%c", msg[i]);
                i++;
            }
        }

        //reset the buffer with values
        memset(data,INIT,sizeof(uint8_t));
        //memset(msg,'^',82);
        vTaskDelay(50);
    }
    return 0;
}
