[![MCHP](images/microchip.png)](https://www.microchip.com)

## Driving a Bipolar Stepper Motor
<br><img src="images/stepper_symbol.png">
<br>Bipolar Stepper Motor

<br>This series of examples presents how to drive a bipolar stepper motor using a dsPIC33AK microcontroller, including the power stage. (This is a Work In Progress)


## Hardware Used

- [Curiosity Platform Development Board](https://www.microchip.com/en-us/development-tool/ev74h48a)
- [dsPIC33AK128MC106 General Purpose Dual In-Line Module (DIM)](https://www.microchip.com/en-us/development-tool/ev02g02a)
- [Multi-Phase Power Board (MPPB)](https://www.microchip.com/en-us/development-tool/ev35z86a)
- Motor used in the application: 16MY7405-01 Stepper Motor, but not mandatory
- A Voltage Power Supply (6-50V and 1-3A current capability, depending on the chosen motor)


<br>In these applications, the bipolar stepper motor will be driven in three modes:
* Full-Step
* Half-Step 
* Microstep


<br> These modes will be explained in more detail in the following four applications. The complexity of the application will gradually increase.

## Application scenarios:
* [Basic example showing the stepper motor in Full-Step, Half-Step and Microstepping modes](./2_Microstep)
* [Adding ramps(acceleration and deceleration) for better dynamic response - WIP - NotReady](./3_Full-Ramp)


<br><img src="images/BoardConfig.png">
<br>Hardware used


<br>Connections with male-male Jumper Wires
| MultiPhaseBoard | CuriosityBoard |
|-----------------|----------------|
| D_AH            | P72            |
| D_AL            | P96            |
| D_BH            | P70            |
| D_BL            | P98            |
| D_CH            | P28            |
| D_CL            | P30            |
| D_DH            | P75            |
| D_DL            | P32            |
| GND             | GND            |
