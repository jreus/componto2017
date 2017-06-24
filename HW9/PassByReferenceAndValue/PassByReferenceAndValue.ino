/*
 * Examples illustrating the difference between pass-by-reference
 * and pass-by-value in functions.
 * 
 *    
 *  This example code is in the public domain. 
 *  Created 15 March 2017 by Jonathan Reus
 */

#include <arduino.h>

int main() {
  init();

  Serial.begin(9600);

  int val1, val2;
  val1 = 0;
  val2 = 222;

  Serial.print("Values before swap: ");
  printVals(val1, val2);

  Serial.print("Values after swapByValue: ");
  swapByValue(val1, val2);
  printVals(val1, val2);

  Serial.print("Values after swapByReference: ");
  swapByReference(val1, val2);
  printVals(val1, val2);

  // Because arrays are already stored as memory locations, when you pass an array into a function, 
  // changes to that array are reflected in the calling scope.
  int myarr[] = {1,2,3,4,5};
  Serial.print("\nArray before swaps: ");
  printArray(myarr, 5);
  swapArray(myarr, 0, 3); // swap elements at 0 and 3
  swapArray(myarr, 1, 2); // swap elements at 1 and 2
  Serial.print("Array after swaps: ");
  printArray(myarr, 5);

  Serial.flush(); // wait until all the data in the serial buffer has been sent to
  return 0;
}

// Swaps the contents of a and b, but only within the scope of this function.
void swapByValue(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
}

// Swaps the contents of a and b, but uses memory references for a and b instead of locally scoped copies
void swapByReference(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

// Prints two integers to the serial monitor
void printVals(int v1, int v2) {
  Serial.print("value1="); 
  Serial.print(v1); 
  Serial.print("  value2=");
  Serial.println(v2);
}

// Swaps two elements in an input array. These changes will exist within the calling scope.
void swapArray(int arr[], int idx1, int idx2) {
  int tmp = arr[idx1];
  arr[idx1] = arr[idx2];
  arr[idx2] = tmp;
}

// Prints an array arr, given its length
void printArray(int a[], int asize) {
  Serial.print("[ ");
  for(int i = 0; i < asize; i++) {
    Serial.print(a[i]);
    if(i < asize-1) {
      Serial.print(", ");
    } else {
      Serial.print(" ");
    }
  }
  Serial.println("]");
}


