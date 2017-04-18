/*
 * The basic blink sketch written using the style
 * of standard C. 
 */

#include <arduino.h>

int main() {
  init();
  
  pinMode(13, OUTPUT);
  
  while(true) {
    digitalWrite(13, HIGH);
    delay(1000); 
    digitalWrite(13, LOW);
    delay(1000); 
  }
  return 0;
}
