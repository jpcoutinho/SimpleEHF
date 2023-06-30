#include <stdint.h>
#include <string.h>

#include "../../include/sensor.h"

#include <Wire.h>
#include <Digital_Light_TSL2561.h>

class GroveLightSensor : public Sensor {

private:

    bool initialized = false;
    
public:
    GroveLightSensor();

    void getSensorValue();

    void init();

    bool isInit();

    /** Common  interface to get temp&humi value.support all DHT device.
        @return 0 for calibrated failed, 1 for succeed.
     **/
    boolean readSensor(uint8_t* bytes, uint8_t numBytes);   
};
