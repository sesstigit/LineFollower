/*------------------------------------------------------------------
Smart Robot - Line Follower with programable PID controller via BT
==> Basic movement based on Nano Mouse Robot, developed by Michael Backus (http://www.akrobotnerd.com/ )
==> Line follow based on http://samvrit.tk/tutorials/pid-control-arduino-line-follower-robot/?ckattempt=1

Marcelo Jose Rovai - 06 April, 2016 - Visit: http://mjrobot.org
-------------------------------------------------------------------*/

#include <Servo.h>
#include "robotDefines.h"

String command;
String device;

// BT Module
#include <SoftwareSerial.h>
SoftwareSerial BT1(10, 11); // pin 10 is Rx and pin 11 is Tx

//---------------------------------------------
void setup() 
{
  
  Serial.begin(9600);
  BT1.begin(9600);
  
  //pinMode(ledPin, OUTPUT);
  //pinMode(buttonPin, INPUT_PULLUP);
  
  // line follow sensors
  pinMode(lineFollowSensor0, INPUT);
  pinMode(lineFollowSensor1, INPUT);
  pinMode(lineFollowSensor2, INPUT);
  pinMode(lineFollowSensor3, INPUT);
  pinMode(lineFollowSensor4, INPUT);
  pinMode(lineFollowSensor5, INPUT);
  
  // servos
  motor.attach(ESC_PIN);
  steering.attach(SERVO_PIN);
  
  BT1.print("check the PID constants to be sent to Robot");
  BT1.println('\n');

  //while (digitalRead(buttonPin) && !mode)
  while (!mode)
  {  
    checkBTcmd();  // verify if a comand is received from BT remote control
    manualCmd ();    
    command = "";  
  }
  checkPIDvalues();
  //mode = STOPPED;  //the code would never work if the mode is always stopped???
}

void loop() 
{
    
  //while (digitalRead(buttonPin) && !mode)
  while (!mode)
  { }
  
  readLFSsensors();    
    switch (mode)
  {
    case STOPPED: 
      motorStop();
      BT1.print("The End");
      ledBlink();
      previousError = error;
      break;

    case NO_LINE:  
      motorStop();
      motorTurn(LEFT, 180);
      previousError = 0;
      break;

    case FOLLOWING_LINE:     
      calculatePID();
      motorPIDcontrol();    
      break;     
  }
}


