//#include <iostream>

#include <stdint.h>
#include <string.h>

#include "../../include/sensor.h"

#include "DHT.h"
#define DHTTYPE DHT22   // DHT 22  (AM2302)

class GroveTempHumiProSensor : public Sensor {

private:
    
    uint8_t sensorPin;
    DHT dht = DHT(DHT22);
    //DHT* dht = nullptr;

public:
    GroveTempHumiProSensor(uint8_t sensorPin);

    void getSensorValue();
    
    /** Common  interface to get temp&humi value.support all DHT device.
        @return 0 for calibrated failed, 1 for succeed.
     **/
    boolean readSensor(uint8_t* bytes, uint8_t numBytes);   
};
