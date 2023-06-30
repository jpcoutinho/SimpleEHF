#ifndef GENERIC_ACTUATOR_H
#define GENERIC_ACTUATOR_H

#include <stdint.h>
#include <string.h>

#include "./actuator.h"

class GenericActuator : public Actuator {

private:
  
    uint8_t pin;  

public:
    GenericActuator(uint8_t pin);

    void turnOn();
    void turnOff();
    void blink(uint16_t interval);

    ~GenericActuator();
};
#endif /* GENERIC_ACTUATOR_H */