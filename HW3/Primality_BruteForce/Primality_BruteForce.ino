/* "Brute Force" Primality Test
 * A "primality test" is a method to determine whether or not a natural number is prime.
 * 
 * Algorithm:
 * 1. Take a number, X, which we want to determine is prime or not.
 * 2. for each integer d, where d = 2 ... X / 2
 *    1. if d divides evenly into X, then X is not prime
 * 3. no d has been found that divides into X, thus X is prime
 * 
 */

#include <arduino.h>

int main() {
  init();

  long x, d;
  bool isPrime = true;
  Serial.begin(9600);
  Serial.setTimeout(10000);

  Serial.print("\n Hello. \n Please enter an integer X: "); 
  x = Serial.parseInt(); Serial.println(x);

  d = 2;
  while(d <= x / 2) {
    if(x % d == 0) {
      isPrime = false;
      break;
    }
    d++;
  }

/* This algorithm can be written more succinctly as a for loop.
  for(d = 2; d <= x / 2; d++) {
    if(x % d == 0) {
      isPrime = false;
      break;
    }
  }
*/

  if(isPrime) {
    Serial.print(x); Serial.println(" is a prime number.");
  } else {
    Serial.print(x); Serial.println(" is a composite number.");    
  }

  delay(1000);
  Serial.println("Goodbye");
  delay(1000);
  return 0;
}

