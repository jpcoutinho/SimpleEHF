#ifndef TASK_H
#define TASK_H


#include <stdint.h>
#include <Arduino.h>


class Task {

private:
    
    uint8_t id;
    uint8_t priority;

public:

    Task();
    Task(uint8_t taskID, uint8_t priority);

    uint8_t getTaskPriority();
    void setTaskPriority(uint8_t newPriority);
    uint8_t getTaskID();
    void setTaskID(uint8_t newID);
    virtual void runTask() = 0;
    virtual ~Task();

};

#endif /*TASK_H*/
