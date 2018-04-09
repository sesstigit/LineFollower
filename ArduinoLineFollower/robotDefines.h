int mode = 0;

# define STOPPED 0
# define FOLLOWING_LINE 1
# define NO_LINE 2

// From AndroidCar
/* pin definitions */
#define SERVO_PIN 8
#define ESC_PIN 9
#define LEFT_IR_ARRAY_L A8
#define LEFT_IR_ARRAY_R A9
#define MID_IR_ARRAY_L A6
#define MID_IR_ARRAY_R A7
#define RIGHT_IR_ARRAY_L A10
#define RIGHT_IR_ARRAY_R A11
#define WHITE 1
#define BLACK 0
// End from AndroidCar

const int power = 500;
const int iniMotorPower = 250;
const int adj = 1;
float adjTurn = 8;

const int ledPin = 13;
const int buttonPin = 9;

// LFSensor more to the Left is "0"
const int lineFollowSensor0 = LEFT_IR_ARRAY_L; 
const int lineFollowSensor1 = LEFT_IR_ARRAY_R; 
const int lineFollowSensor2 = MID_IR_ARRAY_L; 
const int lineFollowSensor3 = MID_IR_ARRAY_R;
const int lineFollowSensor4 = RIGHT_IR_ARRAY_L;
const int lineFollowSensor5 = RIGHT_IR_ARRAY_R;

int LFSensor[6]={0, 0, 0, 0, 0, 0};

// PID controller
float Kp=50;
float Ki=0;
float Kd=0;

float error=0, P=0, I=0, D=0, PIDvalue=0;
float previousError=0, previousI=0;

#define RIGHT -1
#define LEFT 1

# Motor and steering constants
const int IDLE_SPEED = 1500;
const int MAX_FRONT_SPEED = 2000;
const int MAX_BACK_SPEED = 1000;
const int STRAIGHT_WHEELS = 90;
const int MAX_RIGHT_DEGREES = 40;
const int MAX_LEFT_DEGREES = 140;
#define OVERRIDE_FORWARD_SPEED 120
#define OVERRIDE_BACKWARD_SPEED -20
#define OVERRIDE_STEER_RIGHT 20
#define OVERRIDE_STEER_LEFT -20

Servo esc;  //ESC for the motor
Servo steer;  //Servo for steering
