#include "../../include/scheduler.h"

Scheduler :: Scheduler(){
    this->tasksCount = 0;
}

Scheduler :: Scheduler(EnergyManager* energyManager){
    this->tasksCount = 0;
    this->energyManager = energyManager;
}


bool Scheduler :: addTask(Task* task){
    
    if (tasksCount >= MAX_TASKS){
        //Esgotou o limite maximo de tasks no sistema. Nao foi possivel adicionar a nova task
        return false;
    }
    
    if(task->getTaskID() == 0){
        task->setTaskID(tasksCount+1);
    }
    
    this->taskList[tasksCount] = task;
    
    //int al = sizeof(arr)/sizeof(arr[0]); //length calculation
    this->tasksCount++;
    
    #if DEBUG
    std::cout << "Task " << (int)tasksCount << " adicionada! ID: "<< (int)task->getTaskID() << std::endl;
    #endif

    return true;
}

bool Scheduler :: removeTask(uint8_t taskID){
    //Pensar no comportamento do removeTask:
    //Queremos desalocar a task? E se a task for recorrente?
    
    int n = sizeof(taskList) / sizeof(taskList[0]);
    
    int result = binarySearch(taskList, 0, n-1, (int)taskID);
    
    if (result == -1) {
        return false;
    } 

    tasksCount--;
    taskList[result] = nullptr;
        
    if(result+1 == MAX_TASKS){
            
    }
    else{
        memmove(&taskList[result], &taskList[result+1], (MAX_TASKS-result+1) * sizeof(taskList[0])); 
    }

    return true;
}

/**
* Sum numbers in a vector.
*
* @param values Container whose values are summed.
* @return sum of `values`, or 0.0 if `values` is empty.
*/
void Scheduler :: sortTaskList(){
    insertionSort(taskList, tasksCount);
}

void Scheduler :: procTasks(){
    sortTaskList();

    int taskOrder[tasksCount];

    for(int i = 0; i < tasksCount; i++){
        taskOrder[i] = taskList[i]->getTaskID(); 
        taskList[i]->runTask();
    }

    Serial.println("\nTasks executed in the following order: ");

    for(int i = 0; i < tasksCount; i++){
        Serial.print(taskOrder[i]);
        Serial.print(" ");
    }
        Serial.println(""); 
}