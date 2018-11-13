#include <SimpleSDAudio.h>

int a = 2; // Tactile digital pin input
int val = 0; 
int led = 3; // LEDs
int Led = 5;
int LED = 6;
int LeD = 7;
int lEd = 8;
int Val = 0;
static int X = 800; // Starting Speed of Ball
int x = 0;

void setup() {
  pinMode(a, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  pinMode(Led, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(LeD, OUTPUT);
  pinMode(lEd,OUTPUT );
  Serial.begin(9600);

  
  
  SdPlay.setSDCSPin(4); // sd card chip select pin

  SdPlay.init(SSDA_MODE_FULLRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER);

  

 
  

}

void loop() {
 

  
  val = digitalRead(a); 
  Val = digitalRead(led); 
  
  if(val == LOW){ // AFTER BUTTON IS PRESSED X CHANGES AND PONG PLAYS THEN WAITS FOR THE NEXT PRESS 
    X = X - 25; // BALL SPEEDS UP AFTER EACH PRESS 
    Serial.println(X); 
    OdimensionalPong(); 
  }
  if(val == HIGH && X <= 100){
    digitalWrite(LED, HIGH); 
    digitalWrite(LeD, HIGH); 
    digitalWrite(lEd, HIGH); 
    digitalWrite(LeD, HIGH); 
    X = 100; // X STOPS DECREASING AND STAYS AT 75 WHEN BUTTON IS PRESSED 
    x = x + 1;
    if(x = 1){
     SdPlay.setFile("B.wav"); // music name file
     SdPlay.play(); // Play File
     delay(40000);
    }
  if(x = 2){
     SdPlay.setFile("Oz.wav"); // music name file
     SdPlay.play(); // Play File
     delay(20000);
    }
  if(x = 3){
     SdPlay.setFile("F.wav"); // music name file
     SdPlay.play(); // Play File
     delay(25000);
    }
  if(x = 4){
     SdPlay.setFile("M.wav"); // music name file
     SdPlay.play(); // Play File
     delay(20000);
    }
  if(x = 5){
     SdPlay.setFile("Ride.wav"); // music name file
     SdPlay.play(); // Play File
     delay(35000);
     X = 800; 
    }
  }
  
 
  
  
  }
  
 
  



void OdimensionalPong(){ // LEDs turning off and on for 1 dimensional Pong
  digitalWrite(led, HIGH);
  delay(X);
  digitalWrite(led, LOW);
  digitalWrite(Led, HIGH);
  delay(X);
  digitalWrite(Led, LOW);
  digitalWrite(LED, HIGH);
  delay(X);
  digitalWrite(LED, LOW);
  digitalWrite(LeD, HIGH);
  delay(X);
  digitalWrite(LeD, LOW);
  digitalWrite(lEd, HIGH);
  delay(X);
  digitalWrite(lEd, LOW);
  digitalWrite(LeD, HIGH);
  delay(X);
  digitalWrite(LeD, LOW);
  digitalWrite(LED, HIGH);
  delay(X);
  digitalWrite(LED, LOW);
  digitalWrite(Led, HIGH);
  delay(X);
}

