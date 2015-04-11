//====================================================================
//Project Lynxmotion Phoenix
//Description:
//    This is the hardware configuration file for the Hex Robot.
//
//    This version of the Configuration file is set up to run on the
//    Lynxmotion BotboardDuino board, which is similiar to the Arduino Duemilanove
//
//    This version of configuration file assumes that the servos will be controlled
//    by a Lynxmotion Servo controller SSC-32 and the user is using a Lynxmotion
//    PS2 to control the robot.
//
//Last Updated Date: April 10th 2015 
//Programmers:  Eric Shi (tronicsos) (Implemented 24 DoF Apod Hexapod code)
//              Kurt Eckhardt(KurtE) converted to C and Arduino
//
//NEW IN V1.1 (2013-05-17)
//   - Support for Arduino Pro Mini on Bot Board (originally for Basic Atom Pro)
//NEW IN V1.0
//   - First Release
//
//====================================================================

//==================================================================================================================================
//==================================================================================================================================
//==================================================================================================================================
//[CONDITIONAL COMPILING] - COMMENT IF NOT WANTED
// Define other optional compnents to be included or not...

//comment if terminal monitor is not required
#define OPT_TERMINAL_MONITOR

//uncomment the board you want to use
#define __BOTBOARDUINO__    //botboarduino board
//#define __BOTBOARD_ARDUINOPROMINI__  //arduino pro mini on botboard (originally for BasicAtomPro)

//====================================================================
#ifdef OPT_TERMINAL_MONITOR   // turning off terminal monitor will turn these off as well...
#define OPT_SSC_FORWARDER  // only useful if terminal monitor is enabled
#define OPT_FIND_SERVO_OFFSETS    // Only useful if terminal monitor is enabled
#endif

#define OPT_GPPLAYER

// Which type of control(s) do you want to compile in
#define DBGSerial         Serial

#if defined(UBRR1H)
#define SSCSerial         Serial1
#else
#endif

#define USEPS2

//==================================================================================================================================
//==================================================================================================================================
//==================================================================================================================================
// CHR-3
//==================================================================================================================================
#define USE_SSC32
//#define	cSSC_BINARYMODE	1			// Define if your SSC-32 card supports binary mode.

//[SERIAL CONNECTIONS]

// Warning I will undefine some components as the non-megas don't have enough memory...
//#undef OPT_FIND_SERVO_OFFSETS

#define cSSC_BAUD   38400   //SSC32 BAUD rate

//--------------------------------------------------------------------
//[Botboarduino Pin Numbers]
#ifdef __BOTBOARDUINO__
#define SOUND_PIN       5   // Botboarduino JR pin number
#define PS2_DAT         10
#define PS2_CMD         11
#define PS2_SEL         12
#define PS2_CLK         13
// If we are using a SSC-32 then:
// If were are running on an Arduino Mega we will use one of the hardware serial port, default to Serial1 above.
// If on Non mega, if the IO pins are set to 0, we will overload the hardware Serial port
// Else we will user SoftwareSerial to talk to the SSC-32
#define cSSC_OUT       8   //Output pin for Botboard - Input of SSC32 (Yellow)
#define cSSC_IN        9   //Input pin for Botboard - Output of SSC32 (Blue)
#endif

#ifdef __BOTBOARD_ARDUINOPROMINI__
#define SOUND_PIN      11   // Bot Board JR pin number (with Arduino Pro Mini plugged)
#define PS2_DAT        14
#define PS2_CMD        15
#define PS2_SEL        16
#define PS2_CLK        17
// If we are using a SSC-32 then:
// If were are running on an Arduino Mega we will use one of the hardware serial port, default to Serial1 above.
// If on Non mega, if the IO pins are set to 0, we will overload the hardware Serial port
// Else we will user SoftwareSerial to talk to the SSC-32
#define cSSC_OUT       10   //Output pin for Botboard - Input of SSC32 (Yellow)
#define cSSC_IN         9   //Input pin for Botboard - Output of SSC32 (Blue)
#endif

//====================================================================
//[SSC PIN NUMBERS]
#define cRRCoxaPin      25   //Rear Right leg Hip Horizontal
#define cRRFemurPin     26   //Rear Right leg Hip Vertical
#define cRRTibiaPin     27   //Rear Right leg Knee
#define cRRTarsPin      24   // Tar

#define cRMCoxaPin      21   //Middle Right leg Hip Horizontal
#define cRMFemurPin     22   //Middle Right leg Hip Vertical
#define cRMTibiaPin     23   //Middle Right leg Knee
#define cRMTarsPin      20   // Tar

#define cRFCoxaPin      17   //Front Right leg Hip Horizontal
#define cRFFemurPin     18   //Front Right leg Hip Vertical
#define cRFTibiaPin     19   //Front Right leg Knee
#define cRFTarsPin      16   // Tar

#define cLRCoxaPin      9   //Rear Left leg Hip Horizontal
#define cLRFemurPin     10   //Rear Left leg Hip Vertical
#define cLRTibiaPin     11   //Rear Left leg Knee
#define cLRTarsPin      8   // Tar

#define cLMCoxaPin      5   //Middle Left leg Hip Horizontal
#define cLMFemurPin     6   //Middle Left leg Hip Vertical
#define cLMTibiaPin     7   //Middle Left leg Knee
#define cLMTarsPin      4   // Tar

#define cLFCoxaPin      1   //Front Left leg Hip Horizontal
#define cLFFemurPin     2   //Front Left leg Hip Vertical
#define cLFTibiaPin     3   //Front Left leg Knee
#define cLFTarsPin      0   // Tar

//Mandible (claw) pins, distributed servos to balance current draw
#define cManRollPin     14
#define cManPitchPin    28
#define cManYawPin      29

//Tail
#define ctailPanPin 12
#define ctailPitchPin 13

//--------------------------------------------------------------------
//[MIN/MAX ANGLES]
#define cRRCoxaMin1     -560      //Mechanical limits of the Right Rear Leg
#define cRRCoxaMax1     930
#define cRRFemurMin1    -1000 //Adjusted by Eric
#define cRRFemurMax1    750
#define cRRTibiaMin1    -680
#define cRRTibiaMax1    900
#define cRRTarsMin1     -1300	//4DOF ONLY - In theory the kinematics can reach about -160 deg
#define cRRTarsMax1	500	//4DOF ONLY - The kinematics will never exceed 23 deg though..

#define cRMCoxaMin1     -500      //Mechanical limits of the Right Middle Leg
#define cRMCoxaMax1     500
#define cRMFemurMin1    -1000 //Adjusted by Eric 
#define cRMFemurMax1    750
#define cRMTibiaMin1    -680
#define cRMTibiaMax1    900
#define cRMTarsMin1     -1300	//4DOF ONLY - In theory the kinematics can reach about -160 deg
#define cRMTarsMax1	500	//4DOF ONLY - The kinematics will never exceed 23 deg though..

#define cRFCoxaMin1     -950      //Mechanical limits of the Right Front Leg
#define cRFCoxaMax1     620
#define cRFFemurMin1    -1000
#define cRFFemurMax1    750
#define cRFTibiaMin1    -680
#define cRFTibiaMax1    900
#define cRFTarsMin1     -1300	//4DOF ONLY - In theory the kinematics can reach about -160 deg
#define cRFTarsMax1	500	//4DOF ONLY - The kinematics will never exceed 23 deg though..

#define cLRCoxaMin1     -930      //Mechanical limits of the Left Rear Leg
#define cLRCoxaMax1     560
#define cLRFemurMin1    -1000
#define cLRFemurMax1    750
#define cLRTibiaMin1    -680
#define cLRTibiaMax1    900
#define cLRTarsMin1     -1300	//4DOF ONLY - In theory the kinematics can reach about -160 deg
#define cLRTarsMax1	500	//4DOF ONLY - The kinematics will never exceed 23 deg though..

#define cLMCoxaMin1     -500      //Mechanical limits of the Left Middle Leg
#define cLMCoxaMax1     500
#define cLMFemurMin1    -1000
#define cLMFemurMax1    750
#define cLMTibiaMin1    -680
#define cLMTibiaMax1    900
#define cLMTarsMin1     -1300	//4DOF ONLY - In theory the kinematics can reach about -160 deg
#define cLMTarsMax1	500	//4DOF ONLY - The kinematics will never exceed 23 deg though..

#define cLFCoxaMin1     -620      //Mechanical limits of the Left Front Leg
#define cLFCoxaMax1     950
#define cLFFemurMin1    -1000
#define cLFFemurMax1    750
#define cLFTibiaMin1    -680
#define cLFTibiaMax1    900
#define cLFTarsMin1     -1300	//4DOF ONLY - In theory the kinematics can reach about -160 deg
#define cLFTarsMax1	500	//4DOF ONLY - The kinematics will never exceed 23 deg though..

//Mechanical Limits of Mandible

//Head Rotate Limits
#define cHeadRotMAX1	900
#define cHeadRotMIN1	-900

//Head Panorate Limits (side to side)
#define cHeadPanMAX1	380
#define cHeadPanMIN1	-380

//Head Tilt Limits (up and down)
#define cHeadTiltMAX1 	600
#define cHeadTiltMIN1 	530

//Mechanical limits of Right Mandible
#define cMandRightMAX1	600
#define cMandRightMIN1	-280

//Mechanical limits of Left Mandible (reversed in SEQ, not here!)
#define cMandLeftMAX1	600
#define cMandLeftMIN1	-280

//Mechanical limits of Abdomen Tilt (tail up and down)
#define cAbdomTiltMAX1 	620
#define cAbdomTiltMIN1 	-580

//Mechanical limits of Abdomen Panorate (tail side to side)
#define cAbdomPanMAX1	360
#define cAbdomPanMIN1	-360

//--------------------------------------------------------------------
//[LEG DIMENSIONS]
//Universal dimensions for each leg in mm
#define cXXCoxaLength     55    //Length of the Coxa [mm] (55 Lynxmotion A-Pod)
#define cXXFemurLength    80    //Length of Femur [mm]
#define cXXTibiaLength    118   //Length of the Tibia [mm]
#define cXXTarsLength     85    //4DOF ONLY - Lenght of the Tars [mm] 

#define cRRCoxaLength     cXXCoxaLength	    //Right Rear leg
#define cRRFemurLength    cXXFemurLength
#define cRRTibiaLength    cXXTibiaLength
#define cRRTarsLength	  cXXTarsLength	    //4DOF ONLY

#define cRMCoxaLength     cXXCoxaLength	    //Right middle leg
#define cRMFemurLength    cXXFemurLength
#define cRMTibiaLength    cXXTibiaLength
#define cRMTarsLength	  cXXTarsLength	    //4DOF ONLY

#define cRFCoxaLength     cXXCoxaLength	    //Rigth front leg
#define cRFFemurLength    cXXFemurLength
#define cRFTibiaLength    cXXTibiaLength
#define cRFTarsLength	  cXXTarsLength    //4DOF ONLY

#define cLRCoxaLength     cXXCoxaLength	    //Left Rear leg
#define cLRFemurLength    cXXFemurLength
#define cLRTibiaLength    cXXTibiaLength
#define cLRTarsLength	  cXXTarsLength    //4DOF ONLY

#define cLMCoxaLength     cXXCoxaLength	    //Left middle leg
#define cLMFemurLength    cXXFemurLength
#define cLMTibiaLength    cXXTibiaLength
#define cLMTarsLength	  cXXTarsLength	    //4DOF ONLY

#define cLFCoxaLength     cXXCoxaLength	    //Left front leg
#define cLFFemurLength    cXXFemurLength
#define cLFTibiaLength    cXXTibiaLength
#define cLFTarsLength	  cXXTarsLength	    //4DOF ONLY


//--------------------------------------------------------------------
//[BODY DIMENSIONS]
#define cRRCoxaAngle1   -450   //Default Coxa setup angle, decimals = 1
#define cRMCoxaAngle1    0      //Default Coxa setup angle, decimals = 1
#define cRFCoxaAngle1    450      //Default Coxa setup angle, decimals = 1
#define cLRCoxaAngle1    -450   //Default Coxa setup angle, decimals = 1
#define cLMCoxaAngle1    0      //Default Coxa setup angle, decimals = 1
#define cLFCoxaAngle1    450      //Default Coxa setup angle, decimals = 1

#define cRROffsetX      -71     //Distance X from center of the body to the Right Rear coxa
#define cRROffsetZ      85     //Distance Z from center of the body to the Right Rear coxa
#define cRMOffsetX      -71    //Distance X from center of the body to the Right Middle coxa
#define cRMOffsetZ      0       //Distance Z from center of the body to the Right Middle coxa
#define cRFOffsetX      -71     //Distance X from center of the body to the Right Front coxa
#define cRFOffsetZ      -85    //Distance Z from center of the body to the Right Front coxa

#define cLROffsetX      71      //Distance X from center of the body to the Left Rear coxa
#define cLROffsetZ      85     //Distance Z from center of the body to the Left Rear coxa
#define cLMOffsetX      71     //Distance X from center of the body to the Left Middle coxa
#define cLMOffsetZ      0       //Distance Z from center of the body to the Left Middle coxa
#define cLFOffsetX      71      //Distance X from center of the body to the Left Front coxa
#define cLFOffsetZ      -85    //Distance Z from center of the body to the Left Front coxa

//--------------------------------------------------------------------
//[START POSITIONS FEET]
#define cHexInitXZ	 118
#define CHexInitXZCos60  40        // COS(60) = .5
#define CHexInitXZSin60  69    // sin(60) = .866
#define CHexInitY	15 //30


#define cRRInitPosX     83      //Start positions of the Right Rear leg
#define cRRInitPosY     CHexInitY
#define cRRInitPosZ     83

#define cRMInitPosX     118      //Start positions of the Right Middle leg
#define cRMInitPosY     CHexInitY
#define cRMInitPosZ     0

#define cRFInitPosX     83      //Start positions of the Right Front leg
#define cRFInitPosY     CHexInitY
#define cRFInitPosZ     -83

#define cLRInitPosX     83      //Start positions of the Left Rear leg
#define cLRInitPosY     CHexInitY
#define cLRInitPosZ     83

#define cLMInitPosX     118      //Start positions of the Left Middle leg
#define cLMInitPosY     CHexInitY
#define cLMInitPosZ     0

#define cLFInitPosX     83      //Start positions of the Left Front leg
#define cLFInitPosY     CHexInitY
#define cLFInitPosZ     -83
//--------------------------------------------------------------------
//[Tars factors used in formula to calc Tarsus angle relative to the ground]
#define cTarsConst	720	//4DOF ONLY
#define cTarsMulti	2	//4DOF ONLY
#define cTarsFactorA	70	//4DOF ONLY
#define cTarsFactorB	60	//4DOF ONLY
#define cTarsFactorC	50	//4DOF ONLY

#define MandRightClosedPWM  1500 //Right Mandible
#define cMandLeftClosedPWM 1500	//Left Mandible (reversed in SEQ, not here!)

