/*
  Sketch 21.1.1
  Infrared Remote Control originally developed by Freenove.com


  modified May 9th, 2025 by David Elmo Ross
  Modified IRremote.hpp to NOT give deprecated warning.
  When button on IR REMOTE is pressed, it shows the value on the SCREEN.
  This is done after having decoded the HEX value that each key created.
  
*/


// INCLUDE SECTION
#include "arduino.h"        // add arduino library
#define SEND_PWM_BY_TIMER
#include <IRremote.hpp>


// DEFINE SECTION
#define RED_LED 25  
#define GREEN_LED 26
#define BLUE_LED 27 
#define IR_RECEIVE_PIN 2


// Global Variable Section
 unsigned long decoded_value;         // decoded value from IR Remote


    
void setup()
{
  Serial.begin(9600); // Initialize the serial port and set the baud rate to 9600
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  
  pinMode(RED_LED, OUTPUT);  
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT); 


  digitalWrite(RED_LED,1);
  digitalWrite(GREEN_LED,1);
  digitalWrite(BLUE_LED,1);
}


void loop() 
{ 
  printf("\e[2;1H");                  // position cursor at (2,1)
  printf("\e[2J");                    // clear the screen
  printf("IR Receiver is ready!\n");  // Print the string "IR Receiver is ready!"
  
  
  for(;;)                             // infinite loop
  {
 if (IrReceiver.decode())         // if ir results are received
   {  
    decoded_value=IrReceiver.decodedIRData.decodedRawData;
    switch(decoded_value)             // select the button based on HEX decode
    {
      case 0xE916FF00: Serial.println("Number 0");
                     break;
      case 0xf30cff00: Serial.println("Number 1");
                     break;
      case 0xe718FF00: Serial.println("Number 2");
                     break;
      case 0xA15eff00: Serial.println("Number 3");
                     break;
      case 0xF708FF00: Serial.println("Number 4");
                     break;
      case 0xE31Cff00: Serial.println("Number 5");
                     break;
      case 0xA55Aff00: Serial.println("Number 6");
                     break;
      case 0xBd42FF00: Serial.println("Number 7");
                     break;
      default:       break;
    }
    
    IrReceiver.resume();
  }
  delay(500);        // delay 0.5 seconds
 }
}

