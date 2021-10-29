#include "nmea.h"

int match(char * buf, char * pattern, regmatch_t * pmatch){


regex_t    preg;

int        rc;
size_t     nmatch = 2;


if (0 != (rc = regcomp(&preg, pattern, REG_EXTENDED))) {
    printf("regcomp() failed, returning nonzero (%d)\n", rc);
    exit(EXIT_FAILURE);
}

if (0 != (rc = regexec(&preg, buf, nmatch, pmatch, 0))) {
    printf("Failed to match '%s' with '%s',returning %d.\n",
            buf, pattern, rc);
}

regfree(&preg);
return 1;

}

int parse(char * buf, char * pattern){

    regmatch_t pmatch[2];
    if(!match(string, pattern, pmatch)){
        return 0;
    }


}



/*int match(char * buf, char * rexp){

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
}*/

