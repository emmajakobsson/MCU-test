#include "nmea.h"

#define NMEA_MESSAGES "RMC|GLL|GGA"


uint8_t * sub_buf(uint8_t * buf){


    uint8_t tmp[THRESHHOLD] = {INIT};

    for (int i = 0; i < THRESHHOLD; i++){

        tmp[i] = buf[i];

    }

    return &(*buf);
}

int8_t checkValidMsg(uint8_t * s_buf){
    regex_t re;

    char_buf = (char)s_buf;
    if(regcomp(&re, NMEA_MESSAGES, REG_EXTENDED|REG_NOSUB) != 0){
        return 0;
    }
        
    if(regexec(&re, , REG_EXTENDED|REG_NOSUB) != 0){
        return 0;
    }


    
}

int8_t length(uint8_t * arr){
    return sizeof(*arr)/sizeof(arr[0]);
}