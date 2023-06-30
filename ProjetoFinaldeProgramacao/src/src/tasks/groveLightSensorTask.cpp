#include "../tasks/groveLightSensorTask.h"

GroveLightSensorTask :: GroveLightSensorTask(uint8_t taskPriority, Sensor *sensorService) : Task(0, taskPriority){
    this->service = sensorService;
}

GroveLightSensorTask :: GroveLightSensorTask(uint8_t taskID, uint8_t taskPriority, Sensor *sensorService) : Task(taskID, taskPriority){
    this->service = sensorService;
}

void GroveLightSensorTask :: runTask(){
    uint8_t bytes[4];
    memset(bytes, 0, sizeof(bytes));

    if(!service->isInit())
        service->init();

    bool readOk = service->readSensor(bytes, sizeof(bytes));

    int32_t light;
    memcpy(&light, &bytes, 4); 

    if (readOk){
        Serial.print("The Light value is: ");
        Serial.println(light);
    }
}
    
GroveLightSensorTask :: ~GroveLightSensorTask(){ 

}
