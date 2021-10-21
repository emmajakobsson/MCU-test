#include "NMEA.h"

string NMEA_messages[3] = {"GGA","GLL","RMC"};

int validMessage(string data){
    int size = 0;
    size = sizeof(NMEA_messages)/sizeof(NMEA_messages[0]);

    for(int i = 0; i < size; i++){
        if (data.find(NMEA_messages[i]) != string::npos)
            return 1;
        }
    return 0;
}

void NMEA_print(string data){

    if(validMessage(data))
        std << data;

}

