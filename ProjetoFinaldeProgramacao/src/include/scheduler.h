#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>
#include <string.h>
#include "./task.h"
#include "./energyManager.h"
#include "./utils.h"


#ifndef MAX_TASKS
    #define MAX_TASKS 5
#endif


/**
 * Implementation of a trace facility for LSST
 *
 * Tracing is controlled on a per "component" basis, where a "component" is a
 * name of the form aaa.bbb.ccc where aaa is the Most significant part; for
 * example, the utilities library might be called "utils", the doubly-linked
 * list "utils.dlist", and the code to destroy a list "utils.dlist.del"
 *
 */
class Scheduler {

private:

    uint8_t tasksCount;
    Task* taskList[MAX_TASKS];
    EnergyManager* energyManager = nullptr;

    /**
    * A function to sort tasks added to the Scheduler by priority.
    *
    * @return void
    */
    void sortTaskList();

   

public:
    /**
    * Scheduler constructor.
    *
    */
    Scheduler();

    /**
    * Scheduler constructor.
    *
    * @param energyManager a pointer to an EnergyManager instance
    */
    Scheduler(EnergyManager* energyManager);


    /**
    * Adds a task to the Scheduler.
    *
    * @param task a pointer to a task instance
    * @return true if task was added successfully, false if was not added 
    */
    bool addTask(Task* task);
    
    
    /**
    * Removes a task from the Scheduler.
    *
    * @param taskID the ID of the task that we want to remove
    * @return true if task was removed successfully, false if wasn't 
    */
    bool removeTask(uint8_t taskID);


    /**
    * A function to process tasks in the scheduler.
    *
    */
    void procTasks();

};

#endif /*SCHEDULER_H*/