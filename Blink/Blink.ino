int led = 13;
int bouton = 12;
int compteur = 0;
bool allume = 0;
bool push = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(led, OUTPUT);
  pinMode(bouton,INPUT);
  Serial.begin(2000000);
}

// the loop function runs over and over again forever
void loop() {
  bool etatBouton = digitalRead(bouton);
  
  if(!etatBouton){
    if(push == 0){
      if (allume == 1){
        allume = 0;
        digitalWrite(led, HIGH); 
      }else{
        allume = 1;
        digitalWrite(led, LOW);
      }
      push = 1;
      compteur = compteur + 1;
      Serial.println(compteur);
    }
  }else{
    push = 0;
  }
}
