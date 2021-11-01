#include "nmea.h"
#include "protocol.h"
#include "main.h"

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
    int i = 0;
    //int res = 0;
    float lon = 0;
    float lat = 0;

    i2c_driver_delete(I2C_MASTER_NUM);
    configure_i2c_master();

    //esp_err_t error;

    while(1){
        //read data from the sensor
        i2c_master_write_read_device(I2C_MASTER_NUM, SLAVE_ADDR, &reg_addr, 1, data, sizeof(data), I2C_MASTER_TIMEOUT_MS/portTICK_RATE_MS);
        //printf("ERROR: %d\n",error);

        i = 0;
        while(data[i] != 42){
            msg[i] = (char)data[i];
            i++;
        }
        //msg[i-1] = '\n';
        //msg[i] = '*';

        //res = match(msg,NMEA_MESSAGES);
        if(!getPos(msg, &lon, &lat)){
            printf("Getpos failed\n");
        }
        printf("Long: %.4f : Lat: %.4f\n", lon, lat);
        //printf("\nmatch: %d\n", res);

        //print the data from the buffer
        /*if(res == 1){
            i = 0;
            while(data[i] != 42){
                printf("%c", (char)data[i]);
                i++;
            }
            printf("\n");
        }*/

        //res = 0;
        //reset the buffer with values
        //memset(data,INIT,sizeof(uint8_t));
        //memset(msg,'^',82);
        vTaskDelay(50);
    }
    return 0;
}
