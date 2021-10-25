#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <string.h>
#include <regex.h>

#define THRESHHOLD 10
#define INIT 94 //The ASCII sign ^, because it is not present in any NMEA messages.

#ifndef HEADER_FILE
#define HEADER_FILE

int8_t sub_buf(uint8_t buf);

#endif