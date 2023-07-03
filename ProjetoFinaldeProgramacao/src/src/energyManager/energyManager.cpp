#include "../../include/energyManager.h"

EnergyManager :: EnergyManager(){
}

EnergyManager :: EnergyManager(float lowVoltage){
    this->lowVoltageThreshold = lowVoltage;
}


EnergyManager :: EnergyManager(float voltage, uint32_t interval){
    this->autoMonitorVoltage = voltage;
    this->autoMonitorInterval = interval;
}



float EnergyManager ::  getVoltage(){
    voltage = analogRead(A0);

    voltage = voltage * 5.0/1023;

    return voltage;
}

void EnergyManager :: setLowVoltage(float lowVoltage){
    this->lowVoltageThreshold = lowVoltage;
}



void EnergyManager :: setAutoMonitor(float voltage, uint32_t interval){
    
}


void EnergyManager :: startAutoMonitor(){

}

void EnergyManager :: stopAutoMonitor(){

}

void EnergyManager :: onAutoMonitorEventRun(){

}


EnergyManager :: ~EnergyManager(){ 
} 


