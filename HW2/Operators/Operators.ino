/*
 * A tour of C operators.
 * 
 * Make sure to open up the Serial monitor and set it
 * to 9600 baud to see the output of this program.
 */ 

#include <arduino.h>

int main() {
  init(); // this must be at the start of every program I write!

  // This is where I put setup code
  Serial.begin(9600); // start serial communication at 9600 bits per second

  // Here is where I put program code
  Serial.println("Some Calculations in C");
  Serial.println();

  Serial.print("98 - 300 x 21 =");
  Serial.println(98 - 300 * 21);
  Serial.println();

  Serial.print("Integer Division: 12 / 10 = ");
  Serial.println(12 / 10);
  Serial.print("Remainder = ");
  Serial.println(12 % 10);
  Serial.println();

  Serial.print("300 > 20 ?: ");
  Serial.println( 300 > 20 );
  Serial.print("300 < 20 ?: ");
  Serial.println(300 < 20);
  Serial.print("30 != 30 ?: ");
  Serial.println(30 != 30);
  
  Serial.print("15 == 15 OR 30 != 30 ?: ");
  Serial.println(15 == 15 || 30 != 30);
  
  Serial.print("NOT (15 == 15 OR 30 != 30) ?: ");
  Serial.println(!(15 == 15 || 30 != 30));
  
  Serial.print("(2+1) > 2 AND (23 / 4) == 5 AND (23 % 4) == 3 ?: ");
  Serial.println((2+1) > 2 && (23 / 4) == 5 && (23 % 4) == 3);

  Serial.flush(); // waits until all outgoing serial data is finished sending
  //delay(2000); // also does the trick, but flush() is built for this purpose!
  return 0;
}
