//www.elegoo.com
//2016.12.08
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int vel = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
       //servo parado (equivalente a angulo 90º)
   vel = 90;
   myservo.write(vel);              
   delay(1500);    
 
   //servo 100% CW (equivalente a angulo 180º)
   vel = 180;
   myservo.write(vel);              
   delay(1500); 
 
   //servo 100% CCW (equivalente a angulo 0º)
   vel = 0;
   myservo.write(vel);              
   delay(1500); 
}
