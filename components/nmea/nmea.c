/*#include "nmea.h"

#define NMEA_MESSAGES "RMC|GLL|GGA"


int match(char * buf){
    regex_t re;

    if(regcomp(&re, NMEA_MESSAGES, REG_EXTENDED) != 0){
        regfree(&re);
        return 0;
    }
        
    if(regexec(&re, s_buf, (size_t) 0, NULL, 0) != 0){
        regfree(&re);
        return 0;
    }
    regfree(&re);
    return 1;
    
<<<<<<< Updated upstream
}
=======
}

int8_t length(uint8_t * arr){
    return sizeof(*arr)/sizeof(arr[0]);
}*/
>>>>>>> Stashed changes
