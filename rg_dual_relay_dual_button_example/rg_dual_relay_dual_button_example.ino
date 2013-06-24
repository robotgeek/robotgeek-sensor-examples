/**************************************************************************
 *  This example shows how to control two relays using two pushbuttons.
 *  We will read the input from the button using digitalRead(), and based on that
 *  information we will directly set the state of the Relay using digital(write)
 *  When the button is pressed, it will give a HIGH signal, and the relay will
 *  then also go HIGH(activated)
 *
 *  Wiring for RobotGeek Sensor Shield & Sensors: 
 *    Pushbutton 1:Digital Pin 7  
 *    Pushbutton 2:Digital Pin 8 
 *    Relay 1: Digital Pin 10
 *    Relay 2: Digital Pin 11
 *    A full wiring diagram should be distributed with this code
 *    and can be found in the 'rg_dual_relay_dual_button_example' folder
 *    https://github.com/trossenrobotics/robotgeek-sensor-examples/archive/master.zip
 * 
 *  Product Links
 *    Relay Board - http://www.trossenrobotics.com/robotgeek-relay
 *    Pushbutton Board - http://www.trossenrobotics.com/robotGeek-pushbutton
 *    Sensor Shield - http://www.trossenrobotics.com/robotgeek-sensor-shield
 *    3-Pin Sensor Cables - http://www.trossenrobotics.com/robotgeek-3pin-sensor-cable
 **************************************************************************/
  
// use #define to set the I/O numbers, since these will never change - this saves us memory while the Arduino is running
#define BUTTON1 7
#define BUTTON2 8
#define RELAY1  10
#define RELAY2  11

//variables to hold the current status of the button.(LOW == unpressed, HIGH = pressed)
int buttonState1 = 0;         
int buttonState2 = 0;         

void setup() {
  // set the pin for the Buzzer as output:
  pinMode(BUTTON1, INPUT);      
  // set the pin for the Buzzer as output:
  pinMode(BUTTON2, INPUT);      

  // initialize the pins for the pushbutton as inputs:
  pinMode(RELAY1, OUTPUT);     
  pinMode(RELAY2, OUTPUT);     
}

void loop(){
  //use digitalRead to store the current state of the pushbutton in one of the 'buttonState' variables
  //when pressed down, digitalRead() will read a HIGH signal. Otherwise, digitalRead will read a LOW signal
  buttonState1 = digitalRead(BUTTON1);
  buttonState2 = digitalRead(BUTTON2);
  
  //digital write will send whatever signal the the pushbutton currently has to the relay.
  //this means when the pushbutton is HIGH(pressed), the relay will go HIGH(Activated)
  digitalWrite(RELAY1, buttonState1);  
  digitalWrite(RELAY2, buttonState2);  
}
