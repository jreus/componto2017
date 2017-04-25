/* "Brute Force" Primality Test version 2
 * A "primality test" is a method to determine whether or not a natural number is prime.
 * This is a slightly faster algorithm that tests divisors up to sqrt(x) - the square root of x.
 * 
 * Algorithm:
 * 1. Take a number, X, which we want to determine is prime or not.
 * 2. for each integer d, where d = 2 ... sqrt(X)
 *    1. if d divides evenly into X, then X is not prime
 * 3. no d has been found that divides into X, thus X is prime
 * 
 */

#include <arduino.h>

int main() {
  init();

  long x, d, maxval;
  bool isPrime = true;
  Serial.begin(9600);
  Serial.setTimeout(10000);

  Serial.print("\n Hello. \n Please enter an integer X: "); 
  x = Serial.parseInt(); Serial.println(x);

  maxval = sqrt(x);
  for(d = 2; d <= maxval; d++) {
    if(x % d == 0) {
      isPrime = false;
      break;
    }
  }

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

