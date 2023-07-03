#ifndef ENERGY_MANAGER_H
#define ENERGY_MANAGER_H


#include <stdint.h>
#include <Arduino.h>


class EnergyManager {

private:
    
    float lowVoltageThreshold;
    float autoMonitorVoltage;
    uint32_t autoMonitorInterval;

public:

    EnergyManager();
    EnergyManager(float lowVoltage);
    EnergyManager(float voltage, uint32_t interval);

    float getVoltage();
    void setLowVoltage(float lowVoltage);

    void setAutoMonitor(float voltage, uint32_t interval);
    void startAutoMonitor();
    void stopAutoMonitor();

    virtual void onAutoMonitorEventRun();

    virtual ~EnergyManager();

};

#endif /*ENERGY_MANAGER_H*/
