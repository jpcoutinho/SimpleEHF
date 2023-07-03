#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <stdint.h>
#include <Arduino.h>

class Actuator {

private:
    
    
public:

    /**
    * Actuator constructor.
    *
    */
    Actuator();

    /**
    * A virtual function to turn on an actuator.
    *
    * Override this function in an derived class to change is comportament
    *
    * @return void
    */
    virtual void turnOn();

  /**
    * A virtual function to turn off an actuator.
    *
    * Override this function in an derived class to change its behavior
    *
    * @return void
    */
    virtual void turnOff();

        
    /**
    * Actuator destructor.
    *
    */
    virtual ~Actuator();
};

#endif /**/
