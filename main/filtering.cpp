#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <string.h>

using namespace std;
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

int main(){


string data;
int res = 0;
data = "$GMC,34,23,64,25,55";
res = validMessage(data);
cout << res << "\n";
data = "$GLL,76,54,89,65,23,22,7777,87";
res = validMessage(data);
cout << res << "\n";

}



//GGA
//GLL
//RMC