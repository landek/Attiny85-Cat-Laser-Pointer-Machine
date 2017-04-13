#include <Adafruit_SoftServo.h>

#define panServoPIN 0     // Servo control line (orange) on Trinket Pin #0
#define TILTSERVOPIN 1    // Servo control line (orange) on Trinket Pin #1

Adafruit_SoftServo panServo, tiltServo;     // Create TWO servo objects

int pos=0;      // Initialize the position of servos

int calibrationTime = 15;     // Calibration time for PIR sensor – value between 15-30 is good
long unsigned int lowIn;        

long unsigned int pause = 5000;     // The amount of milliseconds the sensor has to be low before we assume all motion has stopped
                                    // Before we assume all motion has stopped
boolean lockLow = true;
boolean takeLowTime; 

                    // PIR Wiring – Pin closest to jumpers is GND
int pirOut = 2;     // Center pin – Digital I/O
int pirVcc = 3;     // Pin oppositve ground – 5v
int laser = 
                  
void setup() {    // Set up the interrupt that will refresh the servo for us automagically
  
  panServo.attach(panServoPIN);     // Attach the servo to pin 0 on Attiny85
  tiltServo.attach(TILTSERVOPIN);   // Attach the servo to pin 1 on Attiny85
  pinMode(pirOut, INPUT);       
  pinMode(pirVcc, OUTPUT);
  digitalWrite(pirVcc, HIGH);
  pinMode(laser, OUTPUT);
  digitalWrite(laser, HIGH);

  for(int i = 0; i < calibrationTime; i++){
    delay(1000);
  }
  while (digitalRead(pirOut) == HIGH) {
    delay(500);
  }
}

void loop(){
  
  if(digitalRead(pirOut) == HIGH){  // If the PIR output is HIGH – Motion is detached

  
//TURN ON LASER
    
    {
     digitalWrite(laser, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(250);  
    }
  
//BEGIN SERVO MOVEMENTS

//Servos will repeat the four following pieces of code 10 times

      //PAN SERVO START 1
  
          for(pos = 0; pos < 180; pos+=1)     // Goes from 0 degrees to 180 degrees
            {                                 // in steps of 1 degree
              panServo.write(pos);            // Tell servo to go to position in variable 'pos'
              delay(15);                      // waits 15ms for the servo to reach the position
            }
    
      //TILT SERVO START 1

          for(pos = 160; pos < 180; pos += 1) // Goes from 160 to 180 degrees – with tilt servo range is limited to about 160 to 180
            {
              tiltServo.write(pos);
              delay(10);
            }

      //PAN SERVO END 1

          for(pos = 180; pos > 0; pos-=1)     //Servo pans from 180 degrees to 0 degrees
            {
              panServo.write(pos);            
              delay(15);                      // To make the servo go faster – decrease the time // To make go slower – increase time
            }

        //TILT SERVO END 1

          for(pos = 180; pos>=160; pos-=1)    //Servo tilts from 180 to 160 degrees
            {                               
              tiltServo.write(pos);            
              delay(10);                     // To make the servo go faster – decrease the time // To make go slower – increase time
            }
            
     //TURN LASER DIODE OFF
    
    {
      digitalWrite(laser, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(250);  

    }
  }
}
