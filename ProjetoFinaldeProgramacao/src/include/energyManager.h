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

    /**
    * EnergyManager constructor.
    *
    */
    EnergyManager();
    
    /**
    * EnergyManager constructor.
    *
    * @param lowVoltage a voltage level threshold
    */
    EnergyManager(float lowVoltage);
    
    /**
    * EnergyManager constructor.
    *
    * @param voltage a voltage level threshold
    * @param inteval period in which auto monitor will measure energy buffer level.
    */
    EnergyManager(float voltage, uint32_t interval);


    /**
    * Get actual energy buffer level.
    *
    *
    * @return void
    */
    float getVoltage();

    /**
    * Set low level voltage threshold.
    *
    * Set the voltage level that will stop scheduler tasks execution. 
    *
    * @param lowVoltage a voltage level threshold
    * @return void
    */
    void setLowVoltage(float lowVoltage);

    /**
    * Set the basic params of auto monitor.
    *
    * Set a voltage level that will trigger auto monitor event. Also set a interval in which auto monitor will get energy buffer level.
    * Lesser intervals means more energy drained from the energy buffer.  
    *
    * @param voltage a voltage level threshold
    * @param inteval period in which auto monitor will measure energy buffer level.
    * @return void
    */
    void setAutoMonitor(float voltage, uint32_t interval);

    /**
    * Start voltage level monitoring - auto monitor.
    *
    * @return void
    */
    void startAutoMonitor();

    /**
    * Stop voltage level monitoring - auto monitor.
    *
    * @return void
    */
    void stopAutoMonitor();


    /**
    * A virtual function that runs when auto monitor event is triggered.
    *
    * Override this function in an derived class to change its behavior
    *
    * @return void
    */
    virtual void onAutoMonitorEventRun();

    /**
    * EnergyManager destructor.
    *
    */
    virtual ~EnergyManager();

};

#endif /*ENERGY_MANAGER_H*/
