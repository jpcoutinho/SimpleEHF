#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>

class Sensor {

private:
    

public:

    /**
    * Sensor constructor.
    *
    */
    Sensor();


    virtual void init();

    virtual bool isInit();
    

    /**
    * A virtual function to read a sensor value.
    *
    * @param bytes array to store read values
    * @param numBytes size of the read values
    * @return bool
    */
    virtual bool readSensor(uint8_t* bytes, uint8_t numBytes);


    
    /**
    * Sensor destructor.
    *
    */
    virtual ~Sensor();
    
};

#endif /**/
