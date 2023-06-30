#ifndef BLINK_SLOW_TASK_H
#define BLINK_SLOW_TASK_H


#include "../../include/task.h"
#include "../../include/actuator.h"
#include "../../include/genericActuator.h"


class BlinkSlowTask : public Task {

private:
    
    Actuator *service = nullptr;

public:
    
    BlinkSlowTask(uint8_t taskPriority);

    BlinkSlowTask(uint8_t taskPriority, Actuator *actuatorService);
    
    BlinkSlowTask(uint8_t taskID, uint8_t taskPriority, Actuator *actuatorService);

    void runTask();
       
    ~BlinkSlowTask();
};

#endif /*BLINK_SLOW_TASK_H*/