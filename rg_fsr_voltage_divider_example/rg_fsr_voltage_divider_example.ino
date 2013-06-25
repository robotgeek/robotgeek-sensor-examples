/**************************************************************************
 *  This example shows how to control an LED using a FSR (or other variale resitor)
 *  and a voltage divider.
 *  The analog sensor will be  read using anlogRead()
 *  http://arduino.cc/en/Reference/analogRead
 *  This will give us a value between 0 and 1023 that represents how hard we are
 *  pushing on the FSR.
 *  Once we have this value, we will use the map() function
 *  http://arduino.cc/en/Reference/map
 *  This function does the math to convert the value between 0 and 1023, to a
 *  proportinal value on the range from 0-255. We will need a value in this 
 *  range so that we can send the value to analogWrite()
 *  http://arduino.cc/en/Reference/analogWrite
 *  By sending this value, we can adjust the brightness of the LED. Keep in mind
 *  that analogWrite() only works on PWM pins.
 *
 *  Wiring for RobotGeek Sensor Shield & Sensors: 
 *    FSR: into 2-pin terminal of Voltage Divider
 *    Voltage Divder: Analog Pin 0
 *    LED Board: Digital Pin 11
 *    A full wiring diagram should be distributed with this code
 *    and can be found in the 'rg_fsr_voltage_divider_example' folder
 *    https://github.com/trossenrobotics/robotgeek-sensor-examples/archive/master.zip
 * 
 *  Product Links
 *    Voltage Divider Board - http://www.trossenrobotics.com/robotgeek-voltage-divider
 *    FSRs - https//www.trossenrobotics.com/store/c/3424-Force-Sensing-Resistors-FSR.aspx
 *    LED Driver Board - http://www.trossenrobotics.com/robotgeek-led-driver
 *    Sensor Shield - http://www.trossenrobotics.com/robotgeek-sensor-shield
 *    3-Pin Sensor Cables - http://www.trossenrobotics.com/robotgeek-3pin-sensor-cable
 **************************************************************************/
  
// use #define to set the I/O numbers, since these will never change - this saves us memory while the Arduino is running
//define analog input port
#define VOLTAGE_DIVIDER     A0
//define digital output port. Since these are PWM ports, we can use analogWrite() on them to vary the LED intensity
#define LED     11

//variable to hold the current value of the analog sensor, a raw value from 0-1023
int voltageDividerValue = 0;  

//variable to hold mapped values for each analog sensor (having this value will allow us to easily use analogWrite()
int valueForLED =0;

void setup() {
  // set the pin for the LEDs as outputs:
  pinMode(LED, OUTPUT);         
}

void loop(){
  //use analog to store the current value of the voltage divider
  voltageDividerValue = analogRead(VOLTAGE_DIVIDER);
  
  //map the knobValue signal (which is between 0 and 1023) to a correspsonging value between 0 and 255 to make the value suitable for analogWrite()
  valueForLED = map(voltageDividerValue, 0,1023,0,255); 

  //use PWM to approximate an analog signal. a value of 0 will set the LED to off, and a value of 255 will set the LED to fully on. Anywhere inbetween will be a dimmed version of the LED
  analogWrite(LED, valueForLED);     
}
