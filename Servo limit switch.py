#include <Servo.h>

Servo clampservo; // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0; // variable to store the servo position
int closedswitch = 2; //set pin for micro switch
int pushbutton = 3; //set pin for push button

void setup() {
Serial.begin(9600);
clampservo.attach(9); // attaches the servo on pin 9 to the servo object
pinMode(closedswitch, INPUT_PULLUP);
pinMode(pushbutton, INPUT_PULLUP);
clampservo.write(0);

}

void loop() {
if (digitalRead(pushbutton) == LOW && digitalRead(closedswitch) == HIGH){
for (pos = pos; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
if (digitalRead(pushbutton) == HIGH && digitalRead(closedswitch) == LOW){
break;}
clampservo.write(pos);
delay(40);
}}

if (digitalRead(pushbutton) == LOW && digitalRead(closedswitch) == LOW){
for (pos = pos; pos >= 0; pos -= 1) { // goes from current position degrees to 0 degrees
clampservo.write(pos);              // tell servo to go to position in variable 'pos'
delay(5);        
}
}
}//end loop
