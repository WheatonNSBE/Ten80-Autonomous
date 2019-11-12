#include <Ultrasonic.h>
#include <Servo.h>

#define USSPin 7
#define potPin 1
#define speedControllerPin 12
#define servoPin 4

int speedVal = 0;
int pos = 0;

int leftPos = 125;
int rightPos = 65;
int centerPos = 95;

long rangeInCM;

Ultrasonic USS(USSPin);
Servo speedController;
Servo servo;

int count = 1;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(500);
  Serial.println("Initiating Robot Project");

  speedController.attach(speedControllerPin);
  servo.attach(servoPin);

  speedController.write(100);
  delay(3000);
}

void loop() {
  if (count == 1) {
  for (int i = 100; i < 120; i++) {
   speedController.write(i);
  }
  }

  int RangeInCentimeters = USS.MeasureInInches();

  Serial.println(RangeInCentimeters);
   if (RangeInCentimeters >= 8) {
    servo.write(125);
  }
  
  else if (RangeInCentimeters <= 3){
    servo.write(65);
  }
  
  else if (RangeInCentimeters > 6){
    servo.write(94);
  }
  count++;
}
