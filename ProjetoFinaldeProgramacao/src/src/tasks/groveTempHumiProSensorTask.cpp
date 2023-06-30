#include "../tasks/groveTempHumiProSensorTask.h"

GroveTempHumiProSensorTask :: GroveTempHumiProSensorTask(uint8_t taskPriority, Sensor *sensorService) : Task(0, taskPriority){
    this->service = sensorService;
}

GroveTempHumiProSensorTask :: GroveTempHumiProSensorTask(uint8_t taskID, uint8_t taskPriority, Sensor *sensorService) : Task(taskID, taskPriority){
    this->service = sensorService;
}

void GroveTempHumiProSensorTask :: runTask(){
    uint8_t bytes[8];
    memset(bytes, 0, sizeof(bytes));

    bool readOk = service->readSensor(bytes, sizeof(bytes));

    float f1, f2;
    memcpy(&f1, &bytes, 4);
    memcpy(&f2, &bytes[4], 4);
    
    if (readOk){
        Serial.print("Humidity: ");
        Serial.print(f1);
        Serial.print(" %\t");
        Serial.print("Temperature: ");
        Serial.print(f2);
        Serial.println(" *C");
    }
    else{
        Serial.println("Failed to get temperature and humidity value.");
    }  
}
    
GroveTempHumiProSensorTask :: ~GroveTempHumiProSensorTask(){ 

}
