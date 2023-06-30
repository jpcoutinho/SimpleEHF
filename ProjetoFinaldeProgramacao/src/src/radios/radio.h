#ifndef RADIO_H
#define RADIO_H

//#include <iostream>
#include <stdint.h>

class Radio {

private:
    
    
public:
    Radio(){
        
    };


    virtual void sendPacket(uint8_t* bytes, uint8_t numBytes) = 0;
   
    
    virtual ~Radio(){ 
       //std::cout << "Destructing base\n"; 
    } 
};

#endif /*RADIO_H*/