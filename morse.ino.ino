#include "morse.h"      // As you can see we've already added the library here


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // We'd declare a char variable now to store and retrieve the character from the serial monitor
  char ch;

  // We'd now declare a boolean to see if we're done taking the input from the serial monitor

  bool done = false;

  while(!done)
  {
    if (Serial.available())       // A check to see if the serial is available 
    {
      ch = Serial.read();         // this reads the input from the serial monitor and stores it into ch
      done = dispChar(ch);        // now, we update the value of done by using the dispChar function which won't just display the character but determine that if we are done or not
    }
  }

  // Now we can decide to either end it here or take further inputs, THIS PART FROM HERE IS AT ENTIRELY YOUR DISCRETION. Play with it as much you want. I'll upload this much code in a repo on github now by the
  // name SIT 210 Task 2.2C tutorial video and that would also be your instruction video on how to add your code to GitHub by creating a repository through your web browser.


  
}
