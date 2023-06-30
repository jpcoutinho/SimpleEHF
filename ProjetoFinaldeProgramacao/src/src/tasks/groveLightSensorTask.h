#ifndef GROOVE_LIGHT_SENSOR_TASK_H
#define GROOVE_LIGHT_SENSOR_TASK_H


#include <stdint.h>
#include <string.h>
#include "../../include/task.h"
#include "../../include/sensor.h"

class GroveLightSensorTask : public Task {

private:
    
    Sensor *service = nullptr;

public:
    GroveLightSensorTask(uint8_t taskPriority, Sensor *sensorService);
    
    GroveLightSensorTask(uint8_t taskID, uint8_t taskPriority, Sensor *sensorService);

    void runTask();
       
    ~GroveLightSensorTask();
};

#endif /*GROOVE_LIGHT_SENSOR_TASK_H*/