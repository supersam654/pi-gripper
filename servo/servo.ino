/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <math.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
const int flexPin = 5;
void setup() {
  Serial.begin(9600);
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object
}

int mapValue(int value) {
  int lower = 50;
  int higher = 90;
  int newValue = (value - lower) * 2;
  return max(0, min(newValue, 180));
}

// 1 degree takes 15ms
// HEREBEDRAGONS: Pause code until +5 is received.
// Limit switch: Digial: YES/NO

void loop() {
  int value = analogRead(flexPin);
  Serial.println(value);
  int mappedValue = mapValue(value);
  myservo.write(mappedValue);
  delay(500);
//  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(15);                       // waits 15ms for the servo to reach the position
//  }
}

