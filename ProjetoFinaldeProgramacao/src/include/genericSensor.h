//#include <iostream>

#include <stdint.h>
#include <string.h>

#include "./sensor.h"

class GenericSensor : public Sensor {

private:
    
public:

    /**
    * GenericSensor constructor.
    *
    */
    GenericSensor();

    /**
    * A  function to read a sensor value.
    *
    * @param bytes array to store read values
    * @param numBytes size of the read values
    * @return bool
    */
    bool readSensor(uint8_t* bytes, uint8_t numBytes);

    
    /**
    * GenericSensor destructor.
    *
    */
    ~GenericSensor();
};
