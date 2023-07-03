#ifndef GENERIC_ACTUATOR_H
#define GENERIC_ACTUATOR_H

#include <stdint.h>
#include <string.h>

#include "./actuator.h"

class GenericActuator : public Actuator {

private:
  
    uint8_t pin;  

public:
   /**
    * GenericActuator constructor.
    *
    */
    GenericActuator(uint8_t pin);


    /**
    * A function to turn on a generic actuator.
    *
    * @return void
    */
    void turnOn();

    /**
    * A function to turn on a generic actuator.
    *
    * @return void
    */
    void turnOff();

    /**
    * A function to toggle on and off 2 times a generic actuator.
    *
    * @return void
    */
    void blink(uint16_t interval);


    /**
    * GenericActuator destructor.
    *
    */
    ~GenericActuator();
};
#endif /* GENERIC_ACTUATOR_H */