#include "../../include/genericActuator.h"

GenericActuator :: GenericActuator(uint8_t pin){
    this->pin = pin;
    pinMode(pin, OUTPUT);
};

void GenericActuator :: turnOn(){
    digitalWrite(pin, HIGH);
}

void GenericActuator :: turnOff(){
    digitalWrite(pin, LOW);
}

void GenericActuator :: blink(uint16_t interval){
    
    Serial.print("Chamou toggle com ");
    Serial.print(interval);
    Serial.println(" de intervalo");

    Serial.println("Acendeu");
    digitalWrite(pin, HIGH);
    delay(interval);
    Serial.println("Apagou");
    digitalWrite(pin, LOW);
    delay(1000);
    Serial.println("Acendeu");
    digitalWrite(pin, HIGH);
    delay(interval);
    Serial.println("Apagou");
    digitalWrite(pin, LOW);
    delay(1000);
}

GenericActuator :: ~GenericActuator(){  
} 