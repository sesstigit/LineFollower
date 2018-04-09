
void motorStop()
{
  esc.writeMicroseconds(IDLE_SPEED);
  steer.writeMicroseconds(STRAIGHT_WHEELS);
  delay(200);
}

//--------------------------------------------- 
void motorForward()
{
  esc.writeMicroseconds(IDLE_SPEED + OVERRIDE_FORWARD_SPEED);
}

//---------------------------------------------
void motorBackward()
{
  esc.writeMicroseconds(IDLE_SPEED + OVERRIDE_BACKWARD_SPEED);
}

//---------------------------------------------
void motorFwTime (unsigned int time)
{
  motorForward();
  delay (time);
  motorStop();
}

//---------------------------------------------
void motorBwTime (unsigned int time)
{
  motorBackward();
  delay (time);
  motorStop();
}

//------------------------------------------------
void motorTurn(int direction, int degrees)
{
  final_degrees = STRAIGHT_WHEELS + (direction * degrees);
  constrain(final_degrees, MAX_RIGHT_DEGREES, MAX_LEFT_DEGREES);
  steer.writeMicroseconds(final_degrees);
  
  delay (round(adjTurn*degrees+1));
  motorStop();
}

//---------------------------------------------------
void motorPIDcontrol()
{
  final_degrees = STRAIGHT_WHEELS + PIDvalue
  //int leftMotorSpeed = 1500 - iniMotorPower - PIDvalue;
  //int rightMotorSpeed = 1500 + iniMotorPower*adj - PIDvalue;
  
  // The motor speed should not exceed the max PWM value
  // constrain(leftMotorSpeed, 1000, 2000);
  // constrain(rightMotorSpeed, 1000, 2000);
  
  constrain(final_degrees, MAX_RIGHT_DEGREES, MAX_LEFT_DEGREES);
  steer.writeMicroseconds(final_degrees);
  
  //leftServo.writeMicroseconds(leftMotorSpeed);
  //rightServo.writeMicroseconds(rightMotorSpeed);
  
  //Serial.print (PIDvalue);
  //Serial.print (" ==> Left, Right:  ");
  //Serial.print (leftMotorSpeed);
  //Serial.print ("   ");
  //Serial.println (rightMotorSpeed);
}

//-----------------------------
void drivePolygon(unsigned int time, int sides) // for motor test only
{
    for (int i = 0; i<sides; i++)
    {
        motorFwTime (time);
        motorTurn(RIGHT, 360/sides);
    }

}
