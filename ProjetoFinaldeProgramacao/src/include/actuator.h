#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <stdint.h>
#include <Arduino.h>

class Actuator {

private:
    
    
public:
    Actuator();

    virtual void turnOn();
    virtual void turnOff();
    virtual ~Actuator();
};

#endif /**/
