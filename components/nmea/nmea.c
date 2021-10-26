#include "nmea.h"


int match(char * buf, char * rexp){

    regex_t re;

    if(regcomp(&re, rexp, REG_EXTENDED) != 0){
        regfree(&re);
        return 0;
    }
        
    if(regexec(&re, buf, (size_t) 0, NULL, 0) != 0){
        regfree(&re);
        return 0;
    }
    regfree(&re);

    return 1; 
}

