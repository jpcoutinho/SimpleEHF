#include <stdint.h>
#include "../../include/sensor.h"

Sensor :: Sensor(){ 
}


void Sensor :: init(){
}

bool Sensor :: isInit(){
        return false;
}


bool Sensor :: readSensor(uint8_t* bytes, uint8_t numBytes){
        return false;
}

Sensor :: ~Sensor(){  
} 