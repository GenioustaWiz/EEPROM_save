#include <EEPROM.h>
#include <Servo.h>
//SoftwareSerial myBT(8, 10);//rx and tx
Servo Door1; //creates a servo object to control a servo.
//you can put aas may servos as the adruino can allow.
 // variable to store the servo position.
int button2 = 0;
int button = 0;
const int U = 2;
const int O = 5;

void setup() {
  Door1.attach(9);
  pinMode(U, INPUT_PULLUP);
  pinMode(O, INPUT_PULLUP);

  if (EEPROM.read(0) == 2) // Reads the EEPROM value stored to know what state the door lock was in before it was last turned off
  { // An EEPROM value of 1 means UNLOCKED and a value of 2 means LOCKED
    Door1.write(180); // Rotates the servo to the unlocked position
    delay(200);
  }
  else if (EEPROM.read(0) == 1)
  {
   
    Door1.write(20); // Rotates the servo to the locked position
    delay(200);
  }
}

void loop() {
  button = digitalRead(U);
  button2 = digitalRead(O);
    
   if(button2 == LOW){
          Door1.write(180);
          delay(15);
          EEPROM.update(0, 2);
   }
  }
