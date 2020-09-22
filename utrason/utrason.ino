
int trigPin = 9;
int echoPin = 10; 

int PWM1 = 5;
int DIR1 = 4;

int vit = 0;

long duration;
void setup()
{
  pinMode(DIR1, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop()
{
  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);



  digitalWrite(DIR1,HIGH);
  if(duration > 2000){
    vit = map(duration, 0, 2000, 0, 255);
    analogWrite(PWM1, vit);   //PWM Speed Control
  }
  Serial.print("Duration: ");
  Serial.println(duration);
  
}
