/*
 * An Implementation of the Insertion Sort algorithm
 * 
 * INSERTION SORT ALGORITHM
 * 1. for each element from position 1 to the end of the array
 *    1. pick out the value at this position call it x
 *    2. for each element, e to the left of x, until the beginning of the array
 *       1. if e is bigger than x, shift it to the right and put x in e's old spot
 *       2. if e is less than x, don't look any farther to the left 
 *    
 * PSEUDOCODE ALGORITHM
 * 1. for each i, from position 1 to the end of the array
 *    1. let x = A[i]
 *    2. for each j, from position i-1 to 0
 *       1. if A[j] > x, shift A[j] to A[j+1], and put x at A[j]
 *       2. if A[j] < x, exit loop 1.2. 
 * 
 * References: 
 * http://www.geeksforgeeks.org/insertion-sort/
 * 
 *  This example code is in the public domain. 
 *  Created 15 March 2017 by Jonathan Reus
 */

#include <arduino.h>

#define ASIZE 8

int main() {
  init();

  Serial.begin(9600);

  int A[] = { 49, 7, 118, 72, 24, 58, 3, 109 };
  
  Serial.println("Sort an array using Insertion Sort:");
  delay(2000);
  Serial.println("Sorting...");
  printArray(A, 0, ASIZE-1);
  delay(2000);

  insertionSort(A, ASIZE); // Sort the first ASIZE elements of the array A

  Serial.println();
  Serial.print("Sorted: ");
  printArray(A, 0, ASIZE-1);

  Serial.println("\nDone");
  Serial.flush();

  return 0;
}




// insertionSort(arr)
// Given an array (arr), this function uses the insertion sort algorithm to 
// sort the first N elements of the array into non-descreasing order.
void insertionSort(int arr[], int N) {
  int insertme;
  for(int i = 1; i < N; i++) { // insert every element from i through N-1
    insertme = arr[i];
    for(int j = i-1; j >= 0; j--) { // insert the ith element in its correct spot to its left
      if(insertme < arr[j]) { // if insertme is smaller than a[j], swap them
        arr[j+1] = arr[j];
        arr[j] = insertme;
      } else { // insertme is just where it needs to be, exit the inner for loop
        break;
      }
    }
    Serial.print("\nInserted: ");
    Serial.println(insertme);
    Serial.print("The array is now: ");
    printArray(arr, 0, N-1);
  }
}



// printArray(arr, left, right) 
// Prints the contents of an array (arr) from one index (left) to another (right).
void printArray(int arr[], int left, int right) {
  Serial.print("[ ");
  for(int i=left; i <= right; i++) {
    Serial.print(arr[i]);
    if(i < right) {
      Serial.print(", ");
    }
  }
  Serial.println(" ]");
}




