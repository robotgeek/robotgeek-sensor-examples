/**************************************************************************
 *  This example shows how to control three LEDs using three analog inputs.
 *  Each analog sensor will be sequentially read using anlogRead()
 *  http://arduino.cc/en/Reference/analogRead
 *  This will give us a value between 0 and 1023 that represents the position
 *  of the sensor (for example, 0 will be fully counter clockwise on a 
 *  knob, while 1023 will be fully clockwise). 
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
 *    Rotational Knob: Analog Pin 0
 *    Slider Analog Pin 1
 *    Joystick (Horizontal): Analog Pin 2
 *    Joystick (Vertical): Not Used
 *    LED 1: Digital Pin 9
 *    LED 2: Digital Pin 10
 *    LED 3: Digital Pin 11
 *    A full wiring diagram should be distributed with this code
 *    and can be found in the 'rg_analog_to_led_example' folder
 *    https://github.com/trossenrobotics/robotgeek-sensor-examples/archive/master.zip
 * 
 *  Product Links
 *    Slider Board - http://www.trossenrobotics.com/robotgeek-slider
 *    Rotation Knob Board - http://www.trossenrobotics.com/robotgeek-rotation-knob
 *    Joystick Board - http://www.trossenrobotics.com/robotgeek-joystick
 *    LED Driver Board - http://www.trossenrobotics.com/robotgeek-led-driver
 *    Sensor Shield - http://www.trossenrobotics.com/robotgeek-sensor-shield
 *    3-Pin Sensor Cables - http://www.trossenrobotics.com/robotgeek-3pin-sensor-cable
 **************************************************************************/
  
// use #define to set the I/O numbers, since these will never change - this saves us memory while the Arduino is running
//define analog input ports
#define KNOB     A0
#define SLIDER   A1
#define JOYSTICK A2
//define digital output ports. Since these are PWM ports, we can use analogWrite() on them to vary the LED intensity
#define LED1     9
#define LED2     10
#define LED3     11

//variables to hold the current value of the analog sensor, a raw value from 0-1023
int knobValue = 0;         
int sliderValue = 0;
int joystickValue = 0;

//variables to hold mapped values for each analog sensor (having this value will allow us to easily use analogWrite()
int valueForLED1 =0;
int valueForLED2 =0;
int valueForLED3 =0;



void setup() {
  // set the pin for the LEDs as outputs:
  pinMode(LED1, OUTPUT);      
  pinMode(LED2, OUTPUT);      
  pinMode(LED3, OUTPUT);           
}

void loop(){
  //use analogread to store the current state of the analog sensor
  knobValue = analogRead(KNOB);
  sliderValue = analogRead(SLIDER);
  joystickValue = analogRead(JOYSTICK);
  
  //map the knobValue signal (which is between 0 and 1023) to a correspsonging value between 0 and 255 to make the value suitable for analogWrite()
  valueForLED1 = map(knobValue, 0,1023,0,255); 
  valueForLED2 = map(sliderValue, 0,1023,0,255);
  valueForLED3 = map(joystickValue, 0,1023,0,255);

  //use PWM to approximate an analog signal. a value of 0 will set the LED to off, and a value of 255 will set the LED to fully on. Anywhere inbetween will be a dimmed version of the LED
  analogWrite(LED1, valueForLED1);     
  analogWrite(LED2, valueForLED2);     
  analogWrite(LED3, valueForLED3);     
}
