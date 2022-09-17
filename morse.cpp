#include "Arduino.h"
#include "morse.h"

char *morse_letters[] = {
    // The letters A-Z in Morse code
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
    ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
    "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
};

char *morse_numbers[] = {
    // The numbers 0-9 in Morse code
    "-----", ".----", "..---", "...--", "....-",
    ".....", "-....", "--...", "---..", "----."
};


void blink_dit_or_dah(char dit_or_dah)
{
  digitalWrite(LED_BUILTIN, HIGH);

  if(dit_or_dah == '.')
    delay(DOT_TIME);
  else                      // directly using else because there are only two symbols to select from.
    delay(DASH_TIME);

  digitalWrite(LED_BUILTIN, LOW);
}


void blink_morse_code(char *morse_code)
{
  int i;

  for(i=0; morse_code[i] != NULL && morse_code[i+1] != NULL; i++)
  {
     blink_dit_or_dah(morse_code[i]);
     delay(SAME_LETTER_TIME);   
  }
  blink_dit_or_dah(morse_code[i]);      // this is to display the last letter without the same letter time delay

  delay(DIFF_LETTER_TIME);              // this is to display the time for the different letter as the new letter would start from here
}


bool dispChar(const char ch)            // the function that we'd be calling in the morse.ino over and over again till it returns true which means it's recieved a . (period) to terminate the loop
{
  if( ch >= 'A' && ch <= 'Z')
  {
    Serial.println(ch);                 // printing the character on the serial monitor to know what character is being displayed right now
    blink_morse_code( morse_letters[ch - 'A']);  
  }
  else if ( ch >= 'a' && ch <= 'z')     // this checks for the lower case letters as the above if statement checks for the uppercase letters.
  {
    Serial.println(ch);
    blink_morse_code(morse_letters[ch - 'a']);
  }

  // Now we're done with the lower and uppercase letters

  else if (ch >= '0' && ch <= '9')
  {
    Serial.println(ch);
    blink_morse_code(morse_letters[ch - '0']);
  }

  // After checking for the numbers now we need to check for the space 
  else if ( ch == ' ')
  {
    delay(WORD_SPACE);
  }

  // Now we'd define the time units as we're done with the usage of delays and oh we still have the period condition left.

  else if ( ch == '.')
  {
    Serial.println("The Name was displayed successfully!");
    return true;          // Returns true after recieving the period at the end of the sentence 
  }
  // Now let's go define the time units.
}
