# SimpleEHF
A simple framework for energy harvesting applications on Arduino

# Gradys Simulations
Simulations from Project GrADyS on OMNET++ and INET framework

# Introduction

# Installation

### 1. Virtualization
[this link](https://drive.google.com/file/d/1IlgWMdPeYZH246wYP_pVjzWEvD9X_tZH/view?usp=sharing) 
### 2. Local Installation

# Usage
**mobilityDrones-omnetpp.ini** 

```
# Scene's coordinates
*.coordinateSystem.sceneLongitude = -47.926634deg
*.coordinateSystem.sceneLatitude = -15.840075deg
*.coordinateSystem.sceneHeading = 90deg

```



**Example of a waypoint file:**
```

```

# Project Structure
## Diagrams
**Project Structure Diagram**
![Project structure diagram](assets/structure_diagram.png)

**Project Message Diagram**
![Project message diagram](assets/message_diagram.png)

INET offers a series of modules that control node mobility. Our objective was to create a module that was capable of simulating a very simple UAV mobility model and could react to network events. This setup allows support for a wide array of possible UAV coordination protocols.

The described requirement was achieved with three modules, one resposible for communication between UAVs (communication), one for controlling the node's movement (mobility) and the last to manage the interaction between the last two (protocol). The behaviour and implementation of these modules is detailed further below. They were made in such a way that the messages exchanged between them are sufficiently generic to allow the creation of a new protocol by creating a new protocol module, with no changes to the other ones by levaraging these generic messages to carry out different procedures. The messages exchanged between them are explained further bellow and are contained on *.msg* files like **MobilityCommand.msg**, **Telemetry.msg** and **CommunicationCommand.msg**.

These three modules are loaded in a *.ned* file. In OMNeT++ *.ned* files define modules that can use other modules forming a module tree. These modules can be simple (the leaves of the module tree) or a compound module that connects simple modules or other compound modules with gates. A network is a special kind of compound module that can be run as a simulation. 

The compound module that represents our UAVs is **MobileNode.ned** and **MobileSensorNode.ned** represents our sensors. These modules contain Communication and Mobility modules (defined in the extended module AdhocHost) and the Protocol module (defined in the file). The **mobilityDrones.ned** file connects all the UAVs(called quads), sensors and some other modules necessary to the simulation.

 ## Mobility
 

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

 ## Communication

 * **CommunicationCommand.msg**
 ```C++
enum CommunicationCommandType {
    // Sets the payload that the communication module sends
    SET_PAYLOAD=0;
    // Sets the target of the communication message (null means broadcast)
    SET_TARGET=1;
}

// Message declaration for the communication command
message CommunicationCommand {
    CommunicationCommandType commandType;
    
    // Template for the SET_PAYLOAD message type (message that the communication module should send)
    inet::FieldsChunk *payloadTemplate;
    
    // Target for the set target command
    string target;
}
 ```

 The message module has several implementations. The *base* folder contains several base implementations for possible communication modules, these files contain functions that interface with INET's communication capabilities but don't implement interaction with any other module.
 
 These files were used as base for the implementation of the communication modules. The following files are the implementations used in the simulations:
  * **UdpMobileNodeCommunicationApp.ned**
  
    Manages the communication between mobile nodes and between mobile nodes and sensors.
 * **UdpSensorCommunicationApp.ned**
    
    Manages communication between sensors and mobile nodes.

## Protocol 

* **DadcaMessage.msg**
**CommunicationProtocolBase.ned** 

* **DadcaProtocol.ned** and **DadcaProtocolSensor.ned**
     
     This protocol is similar to the ZigZagProtocol. It also manages data collection by mobile nodes in a set path. The difference is that this method aims to speed up the process of equally spacing the UAVs in the course by implementing a more advanced movement protocol.

     When the Pair Confirmation message is recieved by both UAVs, confirming the pair, both UAVs take note of the number of neighours on their left (closer to the start) and their right (further from the start) and share this information with their pair. Both update their neighbour count and use it to calculate a point in the course that would represent the extremity of both their sections if their current count of neighbours is accurate. Them they both travel together to this point and revert. This behaviour is implemented with a sequence of commands that get queued on the mobility module.
    

# Development

## Developing your own communication protocol

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
