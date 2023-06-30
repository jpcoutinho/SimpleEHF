//#include <iostream>

#include <stdint.h>
#include <string.h>

#include "../../include/genericSensor.h"

GenericSensor :: GenericSensor(){
}

void GenericSensor :: getSensorValue(){
}
    
bool GenericSensor :: readSensor(uint8_t* bytes, uint8_t numBytes){
    uint32_t aux = 101010;
    memcpy(bytes, &aux, numBytes); 

    return true;
}
    
