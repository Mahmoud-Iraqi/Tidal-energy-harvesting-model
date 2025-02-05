#define AT_PIN A0 
#define VT_PIN A1
#include<Servo.h> 
Servo myservo; 
const int trigPin = 9;
const int echoPin = 10;
int gLED = 13; 
long duration;
int distanceCm, distanceInch;
int oldValue = 0 , newValue = 0;
void setup() {
  
pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(gLED,OUTPUT); 
  
  myservo.attach (8); 
 
  myservo.write(0);   

}

void loop() {
 digitalWrite(trigPin, LOW);                       
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);                         
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  distanceCm = duration * 0.0340 / 2;
  newValue = distanceCm;
 
    Serial.print("Distance: ");
    Serial.print(distanceCm);
    Serial.print(" cm");

  int at_read = analogRead(AT_PIN);
  int vt_read = analogRead(VT_PIN);

  float voltage = at_read * (5.0 / 1024.0) * 2.0;
  float current = vt_read * (5.0 / 1024.0) * 5.0;
  float watts = voltage * current;

  
  Serial.print(" \tVolts: "); 
  Serial.print( voltage, 3);
  Serial.print("\tAmps: ");
  Serial.print(current,3);
  Serial.print("\tWatts: ");
  Serial.print(watts,3);
  Serial.println();
  
  delay(500);
 if (distanceCm<=4) 
  { 
   
      myservo.write(100);  
     } 
    
   
    else if (distanceCm>=12) 
  { 
    
      myservo.write(100);  
     }  
    
else 
  { 
 
      myservo.write(0);  

  
  delay(500);
}
}
