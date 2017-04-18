/*
 * A tour of C operators.
 * 
 * Make sure to open up the Serial monitor and set it
 * to 9600 baud to see the output of this program.
 */

#include <arduino.h>

int main() {
  init(); // I have to run this at the beginning of every program!

  // This is where my setup code goes!
  Serial.begin(9600);  // this command is necessary if you want to use Serial communication!

  // This is where my program code goes!
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
  Serial.println(300 > 20);
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

  delay(2000); // Give the program a chance to finish sending all the serial data
  return 0;
}