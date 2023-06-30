
#include "../tasks/blinkFastTask.h"


BlinkFastTask :: BlinkFastTask(uint8_t taskPriority) : Task(0, taskPriority){
}

BlinkFastTask :: BlinkFastTask(uint8_t taskPriority, Actuator *actuatorService) : Task(0, taskPriority){
    this->service = actuatorService;
}

BlinkFastTask :: BlinkFastTask(uint8_t taskID, uint8_t taskPriority, Actuator *actuatorService) : Task(taskID, taskPriority){
    this->service = actuatorService;
}

void BlinkFastTask :: runTask(){

    Serial.println("\nRunning blinkFastTask...");
    GenericActuator *pChild =  (GenericActuator *) service;
    pChild->blink(500);
}
    
BlinkFastTask :: ~BlinkFastTask(){ 
}
