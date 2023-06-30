#ifndef BLINK_FAST_TASK_H
#define BLINK_FAST_TASK_H


#include <stdint.h>
#include <string.h>
#include "../../include/task.h"
#include "../../include/actuator.h"
#include "../../include/genericActuator.h"


class BlinkFastTask : public Task {

private:
    
    Actuator *service = nullptr;

public:
    
    BlinkFastTask(uint8_t taskPriority);

    BlinkFastTask(uint8_t taskPriority, Actuator *actuatorService);
    
    BlinkFastTask(uint8_t taskID, uint8_t taskPriority, Actuator *actuatorService);

    void runTask();
       
    ~BlinkFastTask();
};

#endif /*BLINK_FAST_TASK_H*/