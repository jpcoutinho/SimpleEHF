#ifndef ESB_RADIO_H
#define ESB_RADIO_H

#include <stdint.h>
//#include <iostream>
#include "../radios/radio.h"

class ESBRadio : public Radio{

private:
    
    

public:
    ESBRadio(){
        
    };

    void sendPacket(uint8_t* bytes, uint8_t numBytes) {
        //std::cout << "ESB enviou packet: default" << std::endl;
        
        //radio.write(bytes, numBytes); //ENVIA AO RECEPTOR A MENSAGEM
    }
};

#endif /*ESB_RADIO_H*/