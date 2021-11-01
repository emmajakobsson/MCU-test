#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <regex.h>

#define NMEA_MESSAGES "RMC|GLL|GGA"

#ifndef HEADER_NMEA
#define HEADER_NMEA

int match(char * buf, char * pattern, regmatch_t * pmatch);

#endif