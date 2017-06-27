/*
 * Demonstration of the concept of statement block scope.
 * 
 * Modified from Purdum, Ch7 Beginning C for Arduino
 * 2017 Jonathan Reus
 * 
 * If you try to compile this program you'll get an error message

Statement_Block_Scope_Broken.ino: In function 'void programLoop()':
Statement_Block_Scope_Broken:50: error: 'temp' was not declared in this scope
   Serial.println(temp);
                  ^
exit status 1
'temp' was not declared in this scope

*/

#include <arduino.h>

#define MAXVAL 1000

int k = 0; // the variable k has global scope

int main() {
  init();

  setupCode();

  while(true) {
    programLoop();
  }

  return 0;
}

void setupCode() {
  Serial.begin(9600);
}

void programLoop() {
  int x = 5; // x has local scope (within the function programLoop)
  if(x < MAXVAL) {
      int temp;  // temp has statement scope
      
      temp = x * 100;
  }
  
  Serial.print("The value of temp is: ");
  Serial.println(temp);

  if(k++ > 10)
    exit(0); // special function to exit the program entirely, no matter what function you're in
    
}

