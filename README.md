# Simple Energy Harvesting Framework - SimpleEHF
A simple framework for energy harvesting applications on Arduino

# Introduction

SimpleEHF is a framework to help programers develop energy harvesting applications on Arduino. Written in C++, SimpleEHF focuses on ease of use and includes an energy management module and a non-preemptive priority based scheduler, ideal for task-based energy harvesting applications.

To guarantee easy extensibility, SimpleEHF offers a set of extension points to commom hardware components present in energy harvesting devices. The following list gives an overview of the available hardware interfaces, to each of which you may add your own extension. To facilitate your life, SimpleEHF ships with a set of interfaces commonly used by these hardware components: 

The Sensors interface describes common sensor interactions. A generic sensor implementation is provided as an example.

The Actuator interface defines common actuators actions. A generic actuator implementation is provided as an example.

The Radio interface defines common radio interactions


# Installation

To use SimpleEHF is actually quite easy. After downloading this repository, unpack the compressed folder to your favorite location to work from. Depending on the IDE you are using, the following steps may differ. We will only describe the general settings you need to achieve with Arduino IDE. The Simple Energy Harvesting Framework (SimpleEHF) caters to a diverse range of users and use cases. Some potential users and use cases include:

•	Researchers and students: Conducting experiments and studies related to intermittent computing and energy harvesting.
•	IoT Developers: Building energy-efficient IoT applications that rely on intermittent power sources.
•	Hobbyists and Tinkerers: Exploring innovative projects with limited electronics knowledge but a desire to harness energy efficiently.

## Setup in Arduino IDE
 To setup SimpleEHF for Arduino IDE, you need to create a new sketch in Arduino IDE and move the unzipped SimpleEHF folder to the sketch folder. 
 
    1. Start Arduino IDE, and create a new sketch ('File' -> 'New') 
    2. Save your sketch with a name of your choice ('File' -> 'Save as...') 
    3. Unpack the repository folder to the desired location
    4. Copy or move the src folder in the root of the unpacked repo folder to the Arduino sketch folder
    5. Done! You are ready to develop incredible applications

In the example folder you can find an application ready to run on Grove kits. You will need to install the required third party libraries through Arduino IDE though. The example is a good source of information on how to utilize the framework for a real application.  

# Usage


Once SimpleEHF is installed, you should import the disired classes of the framework to your code and instantiate then. A common application consists of one instance of Scheduler, multiple instances of components, multiple instaces of tasks and one instance of Energy Management.

To initialize the framework in your project for a common aplication, follow these steps:

    1. Import the necessary classes from the SimpleEHF framework.
    2. Create an instance of the Scheduler class to manage task scheduling.	
    3. Initialize the extended Sensor, Actuator and Radio classes as per your project requirements.
    4. Initialize the EnergyManager class as per your project requirements.
    5. Create new tasks and add them to the scheduler
    6. Initialize the scheduler


# Development

## Creating a new task

To create a task in the SimpleEHF framework, follow these steps:

    1. Define a new class that extends the Task class.
    2. Implement the required methods and logic for your specific task. You must write all your logic in the method runTask() 
    3. Instantiate the created class
    4. Set the priority and dependencies of the task as needed through the method setPriority().


## Executing Tasks

To execute tasks using the SimpleEHF framework, follow these steps:

    1. Add the tasks to the Scheduler using the method addTask().
    2. Initialize the scheduler by calling the method procTasks();
    3. The Scheduler will execute the tasks based on their priorities and available energy.


## Removing Tasks

To remove tasks from the scheduler at runtime using the SimpleEHF framework, follow these steps:

    1. Remove the task of Scheduler using the method removeTask().
    2. The Scheduler will not execute the task anymore



## Developing your own component

### Sensors

To integrate a sensor into your project, follow these steps:

    1. Define a new class that extends the Sensor class or use the provided GenericSensor class.
    2. Implement the necessary methods to read data from the sensor.
    3. Use the sensor data within your tasks or for energy management purposes.


### Actuators

To integrate an actuator into your project, follow these steps:

    1. Define a new class that extends the Actuator class or use the provided GenericActuator class.
    2. Implement the required methods to control the actuator.
    3. Use the actuator within your tasks or for energy management decisions.


### Radio

To integrate a radio module into your project, follow these steps:

    1. Define a new class that extends the Radio class or use the provided GenericRadio class.
    2. Implement the necessary methods to send and receive data using the radio module.
    3. Utilize the radio module for communication purposes within your tasks.


## Energy Manager

The SimpleEHF framework provides energy management capabilities to optimize energy usage in your project. Use the following steps to utilize this feature:

    1. Create an instance of the EnergyManager class.
    2. Set the low voltage threshold of the system by calling the method SetLowVoltage().
    3. Use the method getLowVoltage() to make informed decisions within your tasks. 

You can also use the method setAutoMonitor() to configure a monitor that observes a user specified voltage periodically. When the voltage in the energy buffer equals the specified voltage, the auto monitor method calls the method onAutoMonitorEventRun(), which contains user logic to react to voltage events.   

