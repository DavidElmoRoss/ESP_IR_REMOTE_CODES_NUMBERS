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
#include <IRremote.h>       // add IRremote library

// DEFINE SECTION
#define RED_LED 25  
#define GREEN_LED 26
#define BLUE_LED 27 

// Global Variable Section
long decoded_value;         // decoded value from IR Remote
int RECV_PIN = 2;           // Infrared receiver pin
decode_results results;     // Create a decoding results class object

// INTERRUPT SERVICE ROUTINE SECTION    
IRrecv irrecv(RECV_PIN);    // Create a class object used to receive class 
    
void setup()
{
  Serial.begin(9600); // Initialize the serial port and set the baud rate to 9600
  irrecv.enableIRIn(); // Start the receiver
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
  if (irrecv.decode(&results))        // if ir results are received
   {  
    decoded_value=(results.value);
    switch(decoded_value)             // select the button based on HEX decode
    {
      case 0xFF6897: Serial.println("Number 0");
                     break;
      case 0xFF30CF: Serial.println("Number 1");
                     break;
      case 0xFF18E7: Serial.println("Number 2");
                     break;
      case 0xFF7A85: Serial.println("Number 3");
                     break;
      case 0xff10EF: Serial.println("Number 4");
                     break;
      case 0xFF38C7: Serial.println("Number 5");
                     break;
      case 0xFF5AA5: Serial.println("Number 6");
                     break;
      case 0xFF42BD: Serial.println("Number 7");
                     break;
      default:       break;
    }
    
    irrecv.resume(); // Receive the next value
  }
  delay(500);        // delay 0.5 seconds
 }
}
