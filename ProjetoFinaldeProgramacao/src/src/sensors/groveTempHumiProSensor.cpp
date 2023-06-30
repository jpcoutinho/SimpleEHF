//#include <iostream>

#include <stdint.h>
#include <string.h>

#include "../sensors/groveTempHumiProSensor.h"



GroveTempHumiProSensor :: GroveTempHumiProSensor(uint8_t sensorPin){
    this->sensorPin = sensorPin;
    dht = DHT(sensorPin, DHTTYPE);
    //dht = &DHT(sensorPin, DHTTYPE);

    Wire.begin();
    dht.begin();
};

void GroveTempHumiProSensor :: getSensorValue(){
}

/** Common  interface to get temp&humi value.support all DHT device.
    @return 0 for calibrated failed, 1 for succeed.
**/
boolean GroveTempHumiProSensor :: readSensor(uint8_t* bytes, uint8_t numBytes){

    float temp_hum_val[2] = {0};

    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    if (dht.readTempAndHumidity(temp_hum_val)) {
        return false;
    }

    memcpy(bytes, &temp_hum_val, numBytes);
    return true;
}    

