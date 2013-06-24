/**************************************************************************
 *  This example shows how to control a simple Piezo buzzer (like the
 *  RobotGeek Buzzer) from a digital input (like the RobotGeek Pushbutton) 
 *  This code will turn on the buzzer when Button 1 is pressed, and turn it
 *  off if it is not pressed. The code will also play a short meolody of 3 
 *  tones when Button 2 is pressed. The melody is generated using the
 *  Arduino "Tone()" function
 *  http://arduino.cc/en/Reference/Tone 
 *  Please note that while it is possible to play a wide variety of notes
 *  with a piezo buzzer, some tones do not come out well. If your project
 *  needs quality sounding tones, we reccomend using a speaker.
 *
 *
 *  Wiring for RobotGeek Sensor Shield & Sensors: 
 *    Buzzer: Digital Pin 3
 *    Button 1: Digital Pin 7
 *    Button 2: Digital Pin 3
 *    A full wiring diagram can be found on the RobotGeek Buzzer Page
 *    http://www.trossenrobotics.com/robotgeek-buzzer
 *
 **************************************************************************/
  
// use #define to set the I/O numbers, since these will never change - this saves us memory while the Arduino is running
#define BUTTON1 7
#define BUTTON2 8
#define BUZZER  3

//variables to hold the current status of the button.(LOW == unpressed, HIGH = pressed)
int buttonState1 = 0;         
int buttonState2 = 0;         

void setup() {
  // set the pin for the Buzzer as output:
  pinMode(BUZZER, OUTPUT);      

  // initialize the pins for the pushbutton as inputs:
  pinMode(BUTTON1, INPUT);     
  pinMode(BUTTON2, INPUT);     
}

void loop(){
  //use digitalRead to store the current state of the pushbutton in one of the 'buttonState' variables
  buttonState1 = digitalRead(BUTTON1);
  buttonState2 = digitalRead(BUTTON2);

  //check if the first pushbutton is pressed, and turn the buzzer on as long as the button is pressed
  if (buttonState1 == HIGH) 
  {     
    // turn Buzzer on:    
    digitalWrite(BUZZER, HIGH);  //turn the buzzer on
  } 
  else 
  {
      digitalWrite(BUZZER, LOW);//turn the buzzer off 
  }


  //check if the second pushbutton is pressed, and play a series of notes. Otherwise, nothing happens.
  if (buttonState2 == HIGH) 
  {   
    //play first note  
    tone(BUZZER, 3500,165);//the tone() function will generate a tone on pin BUZZER at frequency 3500, for 165ms
    delay(200);//tone() will set the buzzer for 165ms, but we still need to wait before we issue the next tone() command. If we wait a littl
    //play second note
    tone(BUZZER, 4000,165);
    delay(200);
    //play third note
    tone(BUZZER, 4500,165);
    delay(200);

  } 
  


}
