#ifndef MORSE_H
#define MORSE_H

// First off we'd define the UNIT of time
#define UNIT 300                      // I'm taking it as 300, you can set it up as something else that you like
#define DOT_TIME UNIT                 // Dot time = 1 UNIT
#define DASH_TIME 3*UNIT              // Dash time = 3 UNITS
#define SAME_LETTER_TIME UNIT         // Same letter time = 1 UNIT
#define DIFF_LETTER_TIME 3*UNIT       // Diff letter time = 3 UNITS
#define WORD_SPACE  7*UNIT            // Word space = 7 UNITS


// We need to make our bool dispChar function accessible in the morse.ino now, as this is a library. we'd declare the function here

bool dispChar(const char ch);

// We're done with editing this header file, let's head to the morse.ino file now.


#endif
