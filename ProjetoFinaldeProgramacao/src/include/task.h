#ifndef TASK_H
#define TASK_H


#include <stdint.h>
#include <Arduino.h>


class Task {

private:
    
    uint8_t id;
    uint8_t priority;

public:

    /**
    * Task constructor.
    *
    */
    Task();

    /**
    * Task constructor.
    *
    * @param taskID the task ID to the scheduler
    * @param priority the task execution priority
    */
    Task(uint8_t taskID, uint8_t priority);




    /**
    * Gets a task priority.
    *
    * @return priority
    */
    uint8_t getTaskPriority();

    /**
    * Sets a task ID.
    *
    * @param newPriority the new priority to be attribuited do the task
    * @return void
    */
    void setTaskPriority(uint8_t newPriority);


    /**
    * Gets a task ID.
    *
    * @return taskID
    */
    uint8_t getTaskID();


    /**
    * Sets a task ID.
    *
    * @param newID the new ID to be attribuited do the task
    * @return void
    */
    void setTaskID(uint8_t newID);


    /**
    * A pure virtual function to run the task.
    *
    *  This function must be implemented on the derived class since its contains the task logic
    *
    * @return void
    */
    virtual void runTask() = 0;


    /**
    * Task destructor.
    *
    */
    virtual ~Task();

};

#endif /*TASK_H*/
