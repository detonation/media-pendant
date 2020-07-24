/*
So, mapping out the button uses here. Naming them START and STOP.
START SINGLE PRESS: PLAY/PAUSE
START LONG PRESS: VOLUME UP
START DOUBLE CLICK: TRACK NEXT

STOP SINGLE PRESS: STOP
STOP LONG PRESS: VOLUME DOWN
STOP DOUBLE CLICK: TRACK PREVIOUS

Many thanks to the Creators of OneButton Library and HID-Project library.
Their hard work made this project a breeze.
*/

#include "OneButton.h"
#include "HID-Project.h"

// Setup a new OneButton on pin 3 / start.  
OneButton button1(3, true); // works perfectly NO
// Setup a new OneButton on pin 2 / stop.  
OneButton button2(2, false, true); //works perfectly NC
const int pinLed = LED_BUILTIN;

// setup code here, to run once:
void setup() {
  Consumer.begin(); //start the HID process
//  Serial.begin(9600); //no need for serial, was just for troubleshooting
//  while (!Serial) {
//    ;
//  }
//  Serial.println("Starting TwoButtons...");

//lowering threshold for double-click from 600 to 250ms 
  button1.setClickTicks(500);

//lowering threshold for long-press from 1000 to 500ms
  button1.setPressTicks(500);

//doing the same for the other button
  button2.setClickTicks(500);
  button2.setPressTicks(500);
  
// link the button 1 functions.
  button1.attachClick(click1);
  button1.attachDoubleClick(doubleclick1);
  button1.attachLongPressStart(longPressStart1);
  button1.attachLongPressStop(longPressStop1);
  button1.attachDuringLongPress(longPress1);

 // link the button 2 functions.
  button2.attachClick(click2);
  button2.attachDoubleClick(doubleclick2);
  button2.attachLongPressStart(longPressStart2);
  button2.attachLongPressStop(longPressStop2);
  button2.attachDuringLongPress(longPress2);

}
void loop() {
  button1.tick();
  button2.tick();
  delay(10);
}

// This function will be called when the button1 was pressed 1 time (and no 2. button press followed).
void click1() {
//  Serial.println("Button 1 click.");
Consumer.write(MEDIA_PLAY_PAUSE);
} // click1

// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick1() {
Consumer.write(MEDIA_NEXT);
//  Serial.println("Button 1 doubleclick.");
} // doubleclick1

// This function will be called once, when the button1 is pressed for a long time.
void longPressStart1() {
//  Serial.println("Button 1 longPress start");
} // longPressStart1

// This function will be called often, while the button1 is pressed for a long time.
void longPress1() {
//  Serial.println("Button 1 longPress...");
Consumer.write(MEDIA_VOLUME_UP);
delay(75);
} // longPress1

// This function will be called once, when the button1 is released after beeing pressed for a long time.
void longPressStop1() {
//  Serial.println("Button 1 longPress stop");
} // longPressStop1

// ... and the same for button 2:

void click2() {
//  Serial.println("Button 2 click.");
Consumer.write(MEDIA_STOP);
} // click2

void doubleclick2() {
//  Serial.println("Button 2 doubleclick.");
Consumer.write(MEDIA_PREVIOUS);
} // doubleclick2

void longPressStart2() {
//  Serial.println("Button 2 longPress start");
} // longPressStart2

void longPress2() {
//Serial.println("Button 2 longPress...");
Consumer.write(MEDIA_VOLUME_DOWN);
delay(75);
} // longPress2

void longPressStop2() {
//  Serial.println("Button 2 longPress stop");
} // longPressStop2
