//First you start by including the libraries that you are going to use in your program
#include <Ultrasonic.h>
#include <Servo.h>

//We use the Ultrasonic library for determining the distance to the nearest wall with the ultrasonic sensor on the car
Ultrasonic frontleftUltraSonicSensor(7);

//We use the Servo library for the speed controller(we are treating the speed controller as a servo and setting the speeds from 0-180)
//and the front wheel servo(we use it to control the direction the car travels in)
Servo speedController;
Servo frontWheelsServo;

int potentiometerPin = 1;             //Variable for the potentiometer pin, sets the speed that is passed to the speed controller
int speedControllerPin = 12;          //Variable for settiing the speed controller  pin, sets the speed of the motor
int frontWheelsServoPin = 4;          //Variable for setting the front left servo pin, controls the direction of the car

int currentValue = 0;                     //Variable for the speed that gets passed to the speed controller for the motor
int leftcurrentPositionition = 125;       //Variable for the left-most position of the servo
int rightcurrentPositionition = 65;       //Variable for the right-most position of the servo
int normalcurrentPositionition = 95;  //Variable for the start up position of the servo
int currentPosition = 0;                  //Variable for the current position of the servo
 
long RangeInCentimeters;              //Variable for the range in meters from the ultra sonic sensor

//Setup gets run at start up and is used to set pins and start the process
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(500);
  Serial.println("Begining Program: Autonomous Drive");

  //Attach the servo's to their appropriate pin's
  speedController.attach(speedControllerPin);
  frontWheelsServo.attach(frontWheelsServoPin);

  //Set the initial speed that the speed controller sets the motor to zero
  speedController.write(0);
  delay(3000);
}

void loop() {
//Get the distance in centimeters from the ultra sonic
  RangeInCentimeters = frontleftUltraSonicSensor.read();
//Read the current value from the sensor
  currentValue = analogRead(potentiometerPin); 
//Since the potentiometer increments by 100 units, divide that by 10             
  speedController.write(currentValue/10); 
 //Print the value that the speed is set to
  Serial.println(currentValue/10);    
//Set the position of the servo to the standard position      
  frontWheelsServo.write(normalcurrentPositionition);       

  //Prints the current ultra sonic sensor value before adjustement
  Serial.print("The Value in CM is: ");
  Serial.println(RangeInCentimeters);

  //Checks for the different values that indicate the correct level of farness from the target and set the direction the car should travel in
  if (RangeInCentimeters >= 35 ){
    currentPosition = leftcurrentPositionition;
    frontWheelsServo.write(currentPosition);
  }
  
  else if (RangeInCentimeters <= 20){
    currentPosition = rightcurrentPositionition;
    frontWheelsServo.write(currentPosition);
  }
  
  else if (RangeInCentimeters > 24){
    currentPosition = normalcurrentPositionition;
    frontWheelsServo.write(currentPosition);
  }

  //Prints the adjusted value
  Serial.print("The Current Position is: ");
  Serial.println(currentPosition);
  
  delay(100);
}
