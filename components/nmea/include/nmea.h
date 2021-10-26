#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>


#define THRESHHOLD 10
#define NMEA_MESSAGES "RMC|GLL|GGA"
#define INIT 94

#ifndef HEADER_NMEA
#define HEADER_NMEA


int match(char * buf, char * rexp);

#endif