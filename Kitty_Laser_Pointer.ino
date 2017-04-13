#include <Adafruit_SoftServo.h>

#define panSERVOPIN 0     // Servo control line (orange) on Trinket Pin #0
#define tiltSERVOPIN 1    // Servo control line (orange) on Trinket Pin #1

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
int laser = 4;
                  
void setup() {    // Set up the interrupt that will refresh the servo for us automagically
  
  panServo.attach(panSERVOPIN);     // Attach the servo to pin 0 on Attiny85
  tiltServo.attach(tiltSERVOPIN);   // Attach the servo to pin 1 on Attiny85
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

      //panServo SERVO START 1
  
          for(pos = 0; pos < 180; pos+=1)     // Goes from 0 degrees to 180 degrees
            {                                 // in steps of 1 degree
              panServo.write(pos);            // Tell servo to go to position in variable 'pos'
              delay(15);                      // waits 15ms for the servo to reach the position
            }
    
      //tiltServo SERVO START 1

          for(pos = 160; pos < 180; pos += 1) // Goes from 160 to 180 degrees – with tiltServo servo range is limited to about 160 to 180
            {
              tiltServo.write(pos);
              delay(10);
            }

      //panServo SERVO END 1

          for(pos = 180; pos > 0; pos-=1)     //Notice how the servo is moving from 180 to 0 so it needs pos-=1
            {
              panServo.write(pos);            
              delay(15);                      // To make the servo go faster – decrease the time // To make go slower – increase time
            }

        //tiltServo SERVO END 1

          for(pos = 180; pos>=160; pos-=1)    //Notice how the servo is moving from 180 to 0 so it needs pos-=1
            {                               
              tiltServo.write(pos);            
              delay(10);                     // To make the servo go faster – decrease the time // To make go slower – increase time
            }

//NUMBER 2

//panServo SERVO START 2
    
    for(pos = 0; pos < 90; pos += 1)  
    {                                                 
      panServo.write(pos);                   
      delay(5);                                   
    }

//tiltServo SERVO START 2
   
   for(pos = 150; pos < 180; pos += 1)
    {                                          
      tiltServo.write(pos);                  
      delay(10);                                   
    }
    
//panServo SERVO END 2
    
    for(pos = 140; pos>=25; pos-=1)
    {                              
      panServo.write(pos);                 
      delay(100);            // To make the servo go faster – decrease the time // To make go slower – increase time      
    }

//tiltServo SERVO END 2

    for(pos = 180; pos>=170; pos-=1)    
    {                               
      tiltServo.write(pos);                  
      delay(50);              // To make the servo go faster – decrease the time // To make go slower – increase time
    }

//NUMBER 3

  //panServo SERVO START 3
    
    for(pos = 180; pos < 120; pos += 1)  
    {                                                 
      panServo.write(pos);                  
      delay(10);                               
    }

//tiltServo SERVO START 3
   
   for(pos = 160; pos < 180; pos += 1) 
    {                                                
      tiltServo.write(pos);                   
      delay(10);                                  
    }
    
//panServo SERVO END 3
    
    for(pos = 30; pos>=90; pos-=1)   
    {                              
      panServo.write(pos);                  
      delay(20);              // To make the servo go faster – decrease the time // To make go slower – increase time
    }

//tiltServo SERVO END 3

    for(pos = 180; pos>=145; pos-=1)
    {                               
      tiltServo.write(pos); 
      delay(50);            // To make the servo go faster – decrease the time // To make go slower – increase time
    }

  //panServo SERVO START 4
    
    for(pos = 60; pos < 120; pos += 1) 
    {                                             
      panServo.write(pos);                  
      delay(15);                                  
    }

//NUMBER 4


//tiltServo SERVO START 4
   
   for(pos = 160; pos < 175; pos += 1)  
    {                                          
      tiltServo.write(pos);              
      delay(10);               
    }
    
//panServo SERVO END 4
    
    for(pos = 180; pos>=120; pos-=1)    
    {                              
      panServo.write(pos);          
      delay(20);              // To make the servo go faster – decrease the time // To make go slower – increase time
    }

//tiltServo SERVO END 4

    for(pos = 180; pos>=140; pos-=1)
    {                               
      tiltServo.write(pos);
      delay(15);              // To make the servo go faster – decrease the time // To make go slower – increase time
    }

//NUMBER 5

  //panServo SERVO START 5
    
    for(pos = 25; pos < 75; pos += 1)
    {                                  
      panServo.write(pos);                
      delay(15);                          
    }

//tiltServo SERVO START 5
   
   for(pos = 150; pos < 180; pos += 1)
    {                                               
      tiltServo.write(pos);                   
      delay(10);                                
    }
    
//panServo SERVO END 5
    
    for(pos = 50; pos>=0; pos-=1)   
    {                              
      panServo.write(pos);                 
      delay(40);                  // To make the servo go faster – decrease the time // To make go slower – increase time
    }

//tiltServo SERVO END 5

    for(pos = 180; pos>=170; pos-=1)   
    {                               
      tiltServo.write(pos);               
      delay(15);                     // To make the servo go faster – decrease the time // To make go slower – increase time
    }

//NUMBER 6

  //panServo SERVO START 6
    
    for(pos = 0; pos < 70; pos += 1) 
    {                                            
      panServo.write(pos);             
      delay(10);                            
    }

//tiltServo SERVO START 6
   
   for(pos = 170; pos < 160; pos += 1) 
    {                                            
      tiltServo.write(pos);                 
      delay(10);                              
    }
    
//panServo SERVO END 6
    
    for(pos = 25; pos>=100; pos-=1)    
    {                              
      panServo.write(pos);                 
      delay(50);                   // To make the servo go faster – decrease the time // To make go slower – increase time
    }

//tiltServo SERVO END 6

    for(pos = 155; pos>=180; pos-=1)  
    {                               
      tiltServo.write(pos);             
      delay(60);                    // To make the servo go faster – decrease the time // To make go slower – increase time
    }

//NUMBER 7

  //panServo SERVO START 7
    
    for(pos = 60; pos < 180; pos += 1)
    {                              
      panServo.write(pos);              
      delay(30);        
    }

//tiltServo SERVO START 7
   
   for(pos = 180; pos < 160; pos += 1)
    {                   
      tiltServo.write(pos);               
      delay(10);                             
    }
    
//panServo SERVO END 7
    
    for(pos = 100; pos>=145; pos-=1)   
    {                              
      panServo.write(pos);                
      delay(25);                           // To make the servo go faster – decrease the time // To make go slower – increase time
    }

//tiltServo SERVO END 7

    for(pos = 160; pos>=180; pos-=1)   
    {                               
      tiltServo.write(pos);                 
      delay(75);                       // To make the servo go faster – decrease the time // To make go slower – increase time
    }

  //panServo SERVO START 8
    
    for(pos = 145; pos < 170; pos += 1)  
    {                                                
      panServo.write(pos);                 
      delay(10);                            
    }

//tiltServo SERVO START 8
   
   for(pos = 180; pos < 170; pos += 1)  
    {                                              
      tiltServo.write(pos);                  
      delay(10);                                 
    }

//NUMBER 8
  
//panServo SERVO END 8
    
    for(pos = 20; pos>=60; pos-=1)   
    {                              
      panServo.write(pos);                  
      delay(50);                         // To make the servo go faster – decrease the time // To make go slower – increase time
    }

//tiltServo SERVO END 8

    for(pos = 155; pos>=180; pos-=1)   
    {                               
      tiltServo.write(pos);                 
      delay(50);                          // To make the servo go faster – decrease the time // To make go slower – increase time
    }

  //panServo SERVO START 9
    
    for(pos = 60; pos < 110; pos += 1) 
    {                           
      panServo.write(pos);       
      delay(10);             
    }

//NUMBER 9

//tiltServo SERVO START 9
   
   for(pos = 180; pos < 160; pos += 1)  
    {                                              
      tiltServo.write(pos);                 
      delay(10);                                
    }
    
//panServo SERVO END 9
    
    for(pos = 110; pos>=165; pos-=1)   
    {                              
      panServo.write(pos);                
      delay(25);                         // To make the servo go faster – decrease the time // To make go slower – increase time
    }

//tiltServo SERVO END 9

    for(pos = 155; pos>=180; pos-=1)    
    {                               
      tiltServo.write(pos);              
      delay(20);                         // To make the servo go faster – decrease the time // To make go slower – increase time.
    }

//NUMBER 10

  //panServo SERVO START 10
    
    for(pos = 45; pos < 100; pos += 1) 
    {                                          
      panServo.write(pos);                 
      delay(10);                         
    }

//tiltServo SERVO START 10
   
   for(pos = 180; pos < 150; pos += 1) 
    {                                              
      tiltServo.write(pos);                 
      delay(10);                               
    }
    
//panServo SERVO END 10
    
    for(pos = 130; pos>=90; pos-=1)   
    {                              
      panServo.write(pos);                 
      delay(25);                       // To make the servo go faster – decrease the time // To make go slower – increase time
    }

//tiltServo SERVO END 10

    for(pos = 150; pos>=180; pos-=1)    
    {                               
      tiltServo.write(pos);                 
      delay(50);                       // To make the servo go faster – decrease the time // To make go slower – increase time
    }


//END OF SERVO MOVEMENTS
            
     //TURN LASER DIODE OFF
    
    {
      digitalWrite(laser, LOW);   // Turn the Laser to low and wait for HIGH single from PIR sensor to start loop again
    delay(250);  

    }
  }
}


