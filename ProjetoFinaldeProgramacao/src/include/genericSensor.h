//#include <iostream>

#include <stdint.h>
#include <string.h>

#include "./sensor.h"

class GenericSensor : public Sensor {

private:
    
public:
    GenericSensor();
    void getSensorValue();
    bool readSensor(uint8_t* bytes, uint8_t numBytes);
};
