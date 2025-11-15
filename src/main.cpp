#include <Arduino.h>


#define RGB_LED 8

// ONLY ALLOW A OR B TO HAVE POWER, DO NOT HAVE BOTH HIGH OR ISSUES MAY HAPPEN >:( !!!

#define MOT1_A 20 // High to steer in one direction, must be low when steering in the other direction
#define MOT1_B 19 // High to steer in other direction, must be low when steering in pin 20's direction.
#define MOT2_A 18 // High for Reverse, Low for not reverse (ensure it is low / 0 for going forward to avoid damage or issues)
#define MOT2_B 21 // High for Forward, Low for not forward (ensure it is low / 0 for reversing to avoid damage or issues)


// vars:
//    direction (Bool): True for forward, False for reverse.
//    speed (Byte): Speed 0-255 - controls PWM (Pulse Width)
void drive(byte speed, bool direction);

// vars:
//    direction (Bool): True for one direction, False for the other
//    strength (Byte): Speed 0-255 - controls strength of steer - may have limited effect.
void steer(byte strength, bool direction);

void setup() {

  pinMode(MOT1_A, OUTPUT);
  pinMode(MOT1_B, OUTPUT);
  pinMode(MOT2_A, OUTPUT);
  pinMode(MOT2_B, OUTPUT);

  digitalWrite(MOT1_A, LOW);
  digitalWrite(MOT1_B, LOW);
  digitalWrite(MOT2_A, LOW);
  digitalWrite(MOT2_B, LOW);

  analogWriteFrequency(MOT1_A, 20000); //PWM at 20kHz for quiet c: (set to 1000 for noise :V)
  analogWriteFrequency(MOT1_B, 20000); //PWM at 20kHz for quiet c:
  analogWriteFrequency(MOT2_A, 20000); //PWM at 20kHz for quiet c:
  analogWriteFrequency(MOT2_B, 20000); //PWM at 20kHz for quiet c:

  analogWrite(MOT2_B, 0); // controls forward pwm (speed-kinda) 0 - 255, need about 130 to get movement.

  

}

void loop() {
    rgbLedWrite(RGB_LED, 255,0,0);
    delay(500);
    rgbLedWrite(RGB_LED, 0,0,0);
    delay(500);
}



void drive(byte speed, bool direction)
{
  if(direction)
  {
    analogWrite(MOT2_A, 0);
    analogWrite(MOT2_B, speed);
  }
  else
  {
    analogWrite(MOT2_B, 0);
    analogWrite(MOT2_A, speed);
  }

}

void steer(byte strength, bool direction)
{
  if(direction)
  {
    analogWrite(MOT1_A, 0);
    analogWrite(MOT1_B, strength);
  }
  else
  {
    analogWrite(MOT1_B, 0);
    analogWrite(MOT1_A, strength);
  }

}