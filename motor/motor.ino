
int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the 

int PWM1 = 5;
int DIR1 = 4;

int vit = 0;
void setup()
{
  pinMode(DIR1, OUTPUT);
}
void loop()
{
  sensorValue = analogRead(sensorPin);
  
  if(sensorValue > 512){
    digitalWrite(DIR1,LOW);
    vit = map(sensorValue, 0, 512, 0, 255);
    analogWrite(PWM1, vit);   //PWM Speed Control
  }else{
    digitalWrite(DIR1,HIGH);
    vit = map(sensorValue, 513, 1024, 255, 0);
    analogWrite(PWM1, vit);   //PWM Speed Control
  }
  
}
