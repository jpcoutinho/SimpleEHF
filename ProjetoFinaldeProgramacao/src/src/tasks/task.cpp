#include "../../include/task.h"

Task :: Task(){
}

Task ::  Task(uint8_t taskID, uint8_t priority){

this->priority = priority;
this->id = taskID;
}

uint8_t Task ::  getTaskPriority(){
    return this->priority;
}

void Task :: setTaskPriority(uint8_t newPriority){
    this->priority = newPriority;
}

uint8_t Task :: getTaskID(){
    return this->id;
}

void Task :: setTaskID(uint8_t newID){
    this->id = newID;
}

Task :: ~Task(){ 
} 


