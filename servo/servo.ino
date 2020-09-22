
#include <Servo.h>

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor

int pos = 0;    // variable to store the servo position

Servo myservo;

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  pos = map(sensorValue,0,1024,0,180);
  myservo.write(pos);         
  Serial.println(pos);
}
