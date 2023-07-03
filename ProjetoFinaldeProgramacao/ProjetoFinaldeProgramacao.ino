#define MAX_TASKS 10

#include "./src/include/scheduler.h"
#include "./src/include/energyManager.h"

//#include "./src/include/radioTask.h"
#include "./src/src/tasks/blinkSlowTask.h"
#include "./src/src/tasks/blinkFastTask.h"
#include "./src/src/tasks/groveTempHumiProSensorTask.h"
#include "./src/src/tasks/groveLightSensorTask.h"

#include "./src/src/sensors/groveTempHumiProSensor.h"
#include "./src/src/sensors/groveLightSensor.h"
//#include "./src/radios/ESBRadio.h"

#include "./src/include/genericActuator.h"


/* Components
*/

GroveTempHumiProSensor s1 = GroveTempHumiProSensor(2);
GroveLightSensor s2 = GroveLightSensor();

//ESBRadio r1 = ESBRadio();

GenericActuator led =  GenericActuator(13);
GenericActuator buzzer =  GenericActuator(7);



/* Tasks
*/
GroveTempHumiProSensorTask t1 = GroveTempHumiProSensorTask(1, &s1);
GroveLightSensorTask t2 = GroveLightSensorTask(1, &s2);

//RadioTask t3 = RadioTask(3, &r1);

BlinkFastTask t4 = BlinkFastTask(1, &led);
BlinkSlowTask t5 = BlinkSlowTask(2, &led);
BlinkFastTask t6 = BlinkFastTask(7, &buzzer);

Scheduler sch;

void setup() {
   
    //std::cout<<"Iniciou codigo"<< std::endl;
    Serial.println("Node started!");
    delay(2000);
    
    Serial.begin(9600);

    sch.addTask(&t6);    
    sch.addTask(&t1);
    sch.addTask(&t2);
    //sch.addTask(&t3);
    sch.addTask(&t4);
    sch.addTask(&t5);
    
    int cycle = 1;

}


void loop() {
  Serial.println("\nBeginning tasks execution...");
  sch.procTasks();
  Serial.println("\nAll tasks executed");
  
  delay(3000);
}
