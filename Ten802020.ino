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

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(500);
  Serial.println("Initiating Robot Project");

  speedController.attach(speedControllerPin);
  servo.attach(servoPin);

  speedController.write(0);
  delay(3000);
}

void loop() {
  speedController.write(100);
}
