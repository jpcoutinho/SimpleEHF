//#include <iostream>

#include <stdint.h>
#include <string.h>

#include "../sensors/groveLightSensor.h"


GroveLightSensor :: GroveLightSensor(){
    Wire.begin();
};

void GroveLightSensor ::  getSensorValue(){
    // std::cout <<"Leu sensor de temperatura" << std::endl;
}

void GroveLightSensor :: init(){
    TSL2561.init();
    initialized = true;
}

bool GroveLightSensor :: isInit(){
    return initialized;
}

/** Common  interface to get temp&humi value.support all DHT device.
    @return 0 for calibrated failed, 1 for succeed.
    **/
bool GroveLightSensor :: readSensor(uint8_t* bytes, uint8_t numBytes){

    int32_t lightValue = TSL2561.readVisibleLux();

    memcpy(bytes, &lightValue, numBytes);
    return true;
}    

