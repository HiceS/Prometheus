#include <Servo.h>

Servo servo;

int inByte = 0;

int sensorPin = A0;

int small1sensorPin = A1;
int small2sensorPin = A2;
int small3sensorPin = A3;
int small4sensorPin = A4;

int sparkPin = 2;
int sensorValue = 0;

String output = "The angle is set to: ";

void setup() {
  servo.attach(9);
  Serial.begin(9600);
  pinMode(sparkPin, OUTPUT);
}

void loop() {
 int angle;
 
 sensorValue = analogRead(sensorPin);
 int small1sensorValue = analogRead(small1sensorPin);
 int small2sensorValue = analogRead(small2sensorPin);
 int small3sensorValue = analogRead(small3sensorPin);
 int small4sensorValue = analogRead(small4sensorPin);
 
 
// Serial.println(sensorValue);
// Serial.println(small1sensorValue);
 Serial.println(small1sensorValue);
// Serial.println(small3sensorValue);
// Serial.println(small4sensorValue);

   if(analogRead(sensorPin) > 170 || analogRead(sensorPin) < 100) {
     digitalWrite(sparkPin, HIGH);
//     Serial.println("ON");
   }
   else {
     digitalWrite(sparkPin, LOW);
//     Serial.println("OFF");
   }
   
   int angle1 = small1sensorValue;
   int angle2 = small2sensorValue;
   int angle3 = small3sensorValue;
   int angle4 = small4sensorValue;
   
   int angle_avg = (angle1 + angle2 + angle3 + angle4) / 4;
   
   
   angle_avg  = map(angle, 150, 330, 0, 180);
   Serial.println(angle_avg);
   servo.write(angle);
}


