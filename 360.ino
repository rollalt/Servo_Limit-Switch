
/* 
 *  S05-13 Servo with 3 push buttons
 *  Demonstration of Controlling Continuous Servo (360 servo)
 *  this code allows you to control 360 degree servo using push buttons
 *  
 * Modified by Ahmad Shamshiri for Robojax Robojax.com
 * on Jan 17, 2019 at 22:42 in Ajax, Ontario, Canada
 Watch the video instruction for this sketch: https://youtu.be/hVe4TSRV4ww
 
 Watch Introduction to  360 Servo video with code: https://youtu.be/b_xvu6wWafA
You can get the wiring diagram from my Arduino Course at Udemy.com
Learn Arduino step by step with all library, codes, wiring diagram all in one place
visit my course now http://robojax.com/L/?id=62

If you found this tutorial helpful, please support me so I can continue creating 
content like this. You can support me on Patreon http://robojax.com/L/?id=63
or make donation using PayPal http://robojax.com/L/?id=64

Original code by BARRAGAN <http://barraganstudio.com>
* 
 * Code is available at http://robojax.com/learn/arduino

 * This code is "AS IS" without warranty or liability. Free to be used as long as you keep this note intact.* 
 * This code has been download from Robojax.com
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>. 

*/
 
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int servoPin = 9;// this pin must be of those with PWM ~


#define STOPpin 3 // push button pin  for STOP
#define CWpin 2 //  push button for CW
#define CCWpin 4 // push button for CCW

int sc[]={106, 58, 0};// servo commands are in order 
        //CCW, STOP,CW
        
String scText[]={"CCW","Stop","CW"};// define texts for 3 action
int statusText;
int CWBS, CCWBS, SBS;
      //CW button status (CWBS)
      //CCW button status (CCWBS)
      //stop button status (SBS)

void setup() {
  Serial.begin(9600);
  pinMode(STOPpin,INPUT_PULLUP);// set pin for push button STOP
  pinMode(CCWpin,INPUT_PULLUP);// set pin for push button CCW  
  pinMode(CWpin,INPUT_PULLUP);// set pin for push button CW
    
  myservo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  myservo.write(sc[1]);// send STOP command
  statusText=1;// initial value is STOP
}



void loop() {

    CCWBS = digitalRead(CCWpin);// read status of button CCW
    SBS = digitalRead(STOPpin);// read status of button STOP
    CWBS = digitalRead(CWpin);// read status of button CW
        
    if(CCWBS ==LOW)
    {
      servoCommand(0);
    }else if(SBS ==LOW)
    {
      servoCommand(1);
    }else if(CWBS ==LOW)
    {
      servoCommand(2);
    }
    
  Serial.println(scText[statusText]);
  delay(50);
}// loop 



void servoCommand(int n)
{
   statusText = n;
   myservo.write(sc[n]); 
   Serial.print("Going to  ");
   Serial.print(scText[n]);
   Serial.print( "(");
   Serial.print(sc[n]);
   Serial.println(")");
}
