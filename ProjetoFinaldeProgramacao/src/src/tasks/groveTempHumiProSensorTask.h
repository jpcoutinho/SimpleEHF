#ifndef GROOVE_TEMP_HUMI_PRO_SENSOR_TASK_H
#define GROOVE_TEMP_HUMI_PRO_SENSOR_TASK_H


#include <stdint.h>
#include <string.h>
#include "../../include/task.h"
#include "../../include/sensor.h"

class GroveTempHumiProSensorTask : public Task {

private:
    
    Sensor *service = nullptr;

public:
    GroveTempHumiProSensorTask(uint8_t taskPriority, Sensor *sensorService);
    
    GroveTempHumiProSensorTask(uint8_t taskID, uint8_t taskPriority, Sensor *sensorService);

    void runTask();
    
    ~GroveTempHumiProSensorTask();
};

#endif /*GROOVE_TEMP_HUMI_PRO_SENSOR_TASK_H*/