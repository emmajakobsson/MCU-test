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
    char * msg = calloc(82,1);

    configure_i2c_master();

    while(1){
        //read data from the sensor
        i2c_master_write_read_device(I2C_MASTER_NUM, SLAVE_ADDR, &reg_addr, 1, data, sizeof(data), I2C_MASTER_TIMEOUT_MS/portTICK_RATE_MS);
        for(int i = 0; i < 82; i++){
            msg[i] = (char)data[i];
        }
        //print the data from the buffer
        if(match((char*)data,NMEA_MESSAGES)){

            for(int j = 0; j < 82; j++){
                printf("%c", (char)data[j]);
            }
            
        }

        //reset the buffer with values
        memset(data,INIT,sizeof(uint8_t));
        vTaskDelay(50);

        return 0;
    }
}
