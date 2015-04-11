//==============================================================================
// InputController.h - This is is the class definition for the abstraction of
//     which input controller is used to control the Hex robot.  There will be
//     several implementations of this class, which include:
//         PS2 - 
//         XBEE
//         Serial
//         Autonomous
//==============================================================================
#ifndef _INPUT_CONTROLLER_h_
#define _INPUT_CONTROLLER_h_

#include "Hex_Cfg.h"  // make sure we know what options are enabled...
#if ARDUINO>99
#include <Arduino.h> // Arduino 1.0
#else
#include <Wprogram.h> // Arduino 0022
#endif

class InputController {
  public:
    void     Init(void);
    void     ControlInput(void);
    void     AllowControllerInterrupts(boolean fAllow);

  private:
} ;   

typedef struct _Coord3D {
    long      x;
    long      y;
    long      z;
} COORD3D;


//==============================================================================
// Class ControlState: The purpose of the Control State object is to encapsulate
// all variables that can be dynamically changed in real time by controller input.
// The main code will check an instance of this object in each iteration to determine
// if it needs to execute a gait or switch modes. 
//==============================================================================
typedef struct _InControlState {
     boolean		fHexOn;				//Switch to turn on Phoenix
     boolean		fPrev_HexOn;			//Previous loop state 
//Body position
     COORD3D        BodyPos;

//Body Inverse Kinematics
     COORD3D        BodyRot1;               // X -Pitch, Y-Rotation, Z-Roll

//[gait]
     byte			GaitType;			//Gait type

     short			LegLiftHeight;		//Current Travel height
     COORD3D        TravelLength;            // X-Z or Length, Y is rotation.

//[Single Leg Control]
     byte			SelectedLeg;
     COORD3D        SLLeg;                // 
     boolean		fSLHold;		 	//Single leg control mode


//[Balance]
     boolean        BalanceMode;

//[TIMING]
     byte			InputTimeDelay;	//Delay that depends on the input to get the "sneaking" effect
     word			SpeedControl;	//Adjustible Delay
     
//[Mandible Control]
// Z+ points into the robot body
// Y+ points up into the air
// X+ points to the right
     COORD3D       ManPos;
     byte          ManClos;
     
//[Tail Control]
//Y pans the tail from side to side 
//Z raies and lowers the tail 
    COORD3D    TailPos; 
  
} INCONTROLSTATE;


#endif //_INPUT_CONTROLLER_h_
