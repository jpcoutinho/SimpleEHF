#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>
#include <string.h>
#include "./task.h"
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
   

public:
    Scheduler();

    bool addTask(Task* task);
    bool removeTask(uint8_t taskID);
    void sortTaskList();
    void procTasks();

};

#endif /*SCHEDULER_H*/