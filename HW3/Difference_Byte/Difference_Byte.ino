/*
 * Computes the absolute difference between two bytes.
 * 
 * This program illustrates some of the peculiarities that occur when
 * your data types are chosen badly. 
 */

#include <arduino.h>

int main() {
  init();

  byte a, b;
  Serial.begin(9600);
  Serial.setTimeout(10000);

  Serial.print("Hello. \n Please enter a positive integer less than 256:");
  a = (byte) Serial.parseInt();
  Serial.println(a);
  delay(1000);
  Serial.print("Enter a positive integer less than 256:");
  b = (byte) Serial.parseInt();
  Serial.println(b);
  a = a - b;
  Serial.print("The difference of those two numbers is: ");
  Serial.println(a);
  delay(200);
  return 0;
}

