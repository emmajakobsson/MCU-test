#include "NMEA.h"

const char * NMEA_messages[3] = {"GGA","GLL","RMC"};

int8_t sub_buf(uint8_t buf){

    size_buf = sizeof(buf)/sizeof(buf[0]);

    if (size_buf < THRESHHOLD){
        uint_8 tmp[size_buf] = {INIT};
        tmp = buf;
    } 
    else{
        uint8_t tmp[THRESHHOLD] = {INIT}
        for int i = 0; i < THRESHHOLD; i++){
            tmp[i] = buf[i];
        }
    }

    return 0;
}

int8_t checkValidMsg(uint8_t data){

    reget_t re;
    uint8_t res;

    res = regcomp(&re, "RMC|GLL|GGA")

}

int8_t length(uint8_t arr){

    return sizeof(arr)/sizeof(arr[0]);

}


