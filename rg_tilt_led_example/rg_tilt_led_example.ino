/**************************************************************************
 *  This example shows how to control an LED using a tilt switch.
 *  We will read the input from the tilt switch using digitalRead(), and based on that
 *  information we will set the state of the LED using digital write.
 *  Keep in mind that the tilt behavior will be relative to how you have the tilt switch
 *  oriented. If the switch is upright, then the code
 *      digitalWrite(LED, tiltState);  
 *  will turn the LED on when teh board is tilted. However if you have the switch oriented 
 *  on its side, you will have to invert the tiltState variable to get the desried behavior.
 *      digitalWrite(LED, !tiltState);  
 *
 *
 *
 *  Wiring for RobotGeek Sensor Shield & Sensors: 
 *    Tilt Switch :Digital Pin 2  
 *    LED:Digital Pin 12 
 *    A full wiring diagram should be distributed with this code
 *    and can be found in the 'rg_tilt_led_example' folder
 *    https://github.com/trossenrobotics/robotgeek-sensor-examples/archive/master.zip
 * 
 *  Product Links
 *    Tilt Switch Board - http://www.trossenrobotics.com/robotgeek-tilt-sensor
 *    LED Driver Board - http://www.trossenrobotics.com/robotgeek-led-driver
 *    Sensor Shield - http://www.trossenrobotics.com/robotgeek-sensor-shield
 *    3-Pin Sensor Cables - http://www.trossenrobotics.com/robotgeek-3pin-sensor-cable
 **************************************************************************/
  
// use #define to set the I/O numbers, since these will never change - this saves us memory while the Arduino is running
#define TILT 2
#define LED  12

//variables to hold the current status of the button.(LOW == unpressed, HIGH = pressed)
int tiltState = 0;          

void setup() {
  // set the pin for the Buzzer as output:
  pinMode(TILT, INPUT);      

  // initialize the pins for the pushbutton as inputs:
  pinMode(LED, OUTPUT);     
}

void loop(){
  //use digitalRead to store the current state of the pushbutton in one of the 'tiltState' variables
  //when pressed down, digitalRead() will read a HIGH signal. Otherwise, digitalRead will read a LOW signal
  tiltState = digitalRead(TILT);
  
  //digital write will send whatever signal the the pushbutton currently has to the relay.
  //this means when the pushbutton is HIGH(pressed), the relay will go HIGH(Activated)
  digitalWrite(LED, tiltState);  
}
