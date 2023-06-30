#include "../tasks/blinkSlowTask.h"


BlinkSlowTask :: BlinkSlowTask(uint8_t taskPriority) : Task(0, taskPriority){
}

BlinkSlowTask :: BlinkSlowTask(uint8_t taskPriority, Actuator *actuatorService) : Task(0, taskPriority){
    this->service = actuatorService;
}

BlinkSlowTask :: BlinkSlowTask(uint8_t taskID, uint8_t taskPriority, Actuator *actuatorService) : Task(taskID, taskPriority){
    this->service = actuatorService;
}

void BlinkSlowTask :: runTask(){

    Serial.println("\nRunning blinkSlowTask...");
    GenericActuator *pChild =  (GenericActuator *) service;
    pChild->blink(5000);
}
    
BlinkSlowTask :: ~BlinkSlowTask(){ 
}