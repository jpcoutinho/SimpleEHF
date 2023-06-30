# Simple Energy Harvesting Framework - SimpleEHF
A simple framework for energy harvesting applications on Arduino

# Introduction

SimpleEHF is a framework to help programers develop energy harvesting applications on Arduino. Written in C++, SimpleEHF focuses on ease of use and includes a non-preemptive priority based scheduler, ideal for task-based energy harvesting applications.

To guarantee easy extensibility, SimpleEHF offers a set of extension points to commom hardware components present in energy harvesting devices. The following list gives an overview of the available hardware interfaces, to each of which you may add your own extension. To facilitate your life, SimpleEHF ships with a set of interfaces commonly used by these hardware components: 

The Sensors interface describes common sensor interactions. A generic sensor implementation is provided as an example.

The Actuator interface defines common actuators actions. A generic actuator implementation is provided as an example.

The Radio interface defines common radio interactions


# Installation

To use SimpleEHF is actually quite easy. After downloading this repository, unpack the compressed folder to your favorite location to work from. Depending on the IDE you are using, the following steps may differ. We will only describe the general settings you need to achieve with Arduino IDE. 

##Setup in Arduino IDE
 To setup SimpleEHF for Arduino IDE, you need to create a new sketch in Arduino IDE and move the unzipped SimpleEHF folder to the sketch folder. 
 
    1. Start Arduino IDE, and create a new sketch ('File' -> 'New') 
    2. Save your sketch with a name of your choice ('File' -> 'Save as...') 
    3. Unpack the repository folder to the desired location
    4. Copy or move the src folder in the root of the unpacked repo folder to the Arduino sketch folder
    5. Done! You are ready to develop incredible applications


# Usage

Once SimpleEHF is installed, you should import the disired classes of the framework to your code and instantiate then. An application commonly consists of one instance of scheduler, multiple instances of components and multiple instances of 


Instanciar o scheduler

Criar os componentes

Criar as tasks

Adicionar as tasks ao scheduler



Allows multiple tasks to run at the same time, without interrupting each other. For Arduino sam and samd architectures only (Due, Zero...).
The Scheduler library enables the Arduino to run multiple functions at the same time. This allows tasks to happen without interrupting each other.This is a cooperative scheduler in that the CPU switches from one task to another. The library includes methods for passing control between tasks. 


**mobilityDrones-omnetpp.ini** 

```
# Scene's coordinates
*.coordinateSystem.sceneLongitude = -47.926634deg
*.coordinateSystem.sceneLatitude = -15.840075deg
*.coordinateSystem.sceneHeading = 90deg

```

# Project Structure
## Diagrams
**Project Structure Diagram**
![Project structure diagram](assets/structure_diagram.png)


SimpleEHF offers a series of interfaces that control commom energy harvesting devices hardware. Our objective was to create a module that was capable of simulating a very simple UAV mobility model and could react to network events. This setup allows support for a wide array of possible UAV coordination protocols.

* **MobilityCommand.msg**
```C++
// Commands that the mobility module should be capable of carrying out
enum MobilityCommandType {
    // Makes the UAV reverse on its course
    // No params
    REVERSE=0; 
    
    // Makes the UAV travel to a specific waypoint, following the tour pack
    // Param 1: Waypoint index
    GOTO_WAYPOINT=1;
    
    // Makes the UAV go to a specific coordinate and orient itself so it can continue the tour afterwards
    // Param 1: x component of the coord
    // Param 2: y component of the coord
    // Param 3: z component of the coord
    // Param 4: Next waypoint (Waypoint the UAV should go to after reaching the target)
    // Param 5: Last waypoint (Waypoint the UAV used to reach the coords)
    GOTO_COORDS=2;
}

// Message declaration containing the command Id and its parameters 
message MobilityCommand {
    MobilityCommandType commandType;
    double param1=-1;
    double param2=-1;
    double param3=-1;
    double param4=-1;
    double param5=-1;
}
```

# Development

## Creating a new task



## Developing your own component

### 1. Sensors
### 2. Actuators
### 3. Radio

**SimpleMessage.msg**
```C++
// communication/messages/network/SimpleMessage.msg

// Network messages need to extend from the FieldsChunk class or other chunk classes
import inet.common.packet.chunk.Chunk;

namespace inet;

enum SenderType
{
  DRONE = 0;
  SENSOR = 1;
  GROUND_STATION = 2;
}

class SimpleMessage extends FieldsChunk
{
    chunkLength = B(7); // Fixed chunk length
    SenderType senderType;
    int content;
}
```

Our protocols will use this message definition to communicate with eachother. Next let's define our UAV's protocol. All it needs to do is contantly emit messages with it's current data load, listen to messages from sensors to load more data and listen to messages from the groundStation to unload. The only parameter we are defining is the timeoutDuration, we will not override the default value but it is good to have the option to increase or decrease the UAV's timeout. This timeout will be activated to prevent over-communication with the sensors and ground station.
