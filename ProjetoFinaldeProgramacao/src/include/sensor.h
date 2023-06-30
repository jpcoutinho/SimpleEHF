#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>

class Sensor {

private:
    

public:

    Sensor();

    virtual void init();
    virtual bool isInit();
    virtual bool readSensor(uint8_t* bytes, uint8_t numBytes);
    virtual ~Sensor();
    
};

#endif /**/
