/*
 * This program illustrates a simple algorithm, which finds the maximum value
 * within an array of random numbers.
 * 
 * Algorithm:
 * 1. input: a number n, representing the size of the array
 *    output: the maximum value in the array
 * 2. generate an array, A, with n random values
 * 3. let currentMax = A[0]
 * 4. for each i, from 1 to n-1
 *    1. if currentMax < A[i], then set currentMax = A[i]
 * 5. return currentMax
 * 
 * 
 * See this link for the TFT library reference page:
 * https://www.arduino.cc/en/Reference/TFTLibrary
 *  
 *  This example code is in the public domain. 
 *  Created 15 March 2017 by Jonathan Reus
 */

#include <arduino.h>

#define MAX_SIZE 255

int main() {
  init();

  byte n;
  int my_arr[MAX_SIZE]; // you have to specify the size of an array when you define it! At least for now

  Serial.begin(9600);
  Serial.setTimeout(10000);
  Serial.println("\nHello");
  Serial.print("Enter a number N: ");
  n = Serial.parseInt(); Serial.println(n);
  Serial.println();
  delay(1000);

  // fill the array with random numbers
  for(int i = 0; i < n; i++) {
    my_arr[i] = random(-30000, 30000);
  }

  Serial.println("I generated the array:");
  // print the array
  Serial.print("[");
  for(int i = 0; i < n; i++) {
    Serial.print(", ");
    Serial.print(my_arr[i]);
  }
  Serial.println(" ]");
  Serial.println();
  
  delay(1000);
  Serial.println("Finding the max value...");

  // Run the max value algorithm
  int currentMax = my_arr[0];
  for(int i = 1; i < n; i++) {
    if(currentMax < my_arr[i]) {
      currentMax = my_arr[i];
    }
  }

  Serial.print("I found ");
  Serial.println(currentMax);
  Serial.println();
  Serial.println("Goodbye");

  Serial.flush();
  return 0;
}
