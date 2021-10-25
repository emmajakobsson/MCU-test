#include "nmea.h"

#define NMEA_MESSAGES "RMC|GLL|GGA"


uint8_t * sub_buf(uint8_t * buf){


    uint8_t tmp[THRESHHOLD] = {INIT};

    for (int i = 0; i < THRESHHOLD; i++){

        tmp[i] = buf[i];

    }

    return &(*tmp);
}

int8_t checkValidMsg(uint8_t data){
    regex_t re;
    uint8_t res;

    res = regcomp(&re, NMEA_MESSAGES, REG_EXTENDED|REG_NOSUB);
    if(res == 0){
        return 1;
    }
    else{
        return 0;
    }
    
}

int8_t length(uint8_t * arr){
    return sizeof(*arr)/sizeof(arr[0]);
}