/*
 * An implementation of the Selection Sort algorithm.
 * Selection sort does its thing by repeatedly *selecting* the smallest element
 * of the array and bringing it to the front (following all previously selected smaller elements).
 * 
 * 
 * SELECTION SORT (A, n)
 * Inputs:
 * A: an array to be sorted
 * n: the number of elements in A to sort
 * Result: the elements of A are sorted in non-decreasing order
 * 
 * 1. for each i, from the first position in A to one before the last position: 
 *    A. Find the smallest value in the sequence of values from position i to the end of A 
 *    B. Swap the ith element with the smallest element
 * 
 * Step 1.A. is a variation of the Max Value algorithm we've seen before. 
 * A more precise rewriting of the algorithm looks something like this:
 * 
 * SELECTION SORT (A, n)
 * Inputs & Result same as before
 * 
 * 1. for each i, from the first position in A to one before the last position: 
 *    A. Set smallest to i 
 *    B. for each j, from i+1 to n:
 *       i. If A[j] < A[smallest] then set smallest to j
 *    C. Swap A[i] with A[smallest]
 * 
 * References: 
 * http://www.geeksforgeeks.org/selection-sort/
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
  
  Serial.println("Sort an array using Selection Sort:");
  delay(2000);
  Serial.println("Sorting...");
  printArray(A, 0, ASIZE-1);
  delay(2000);

  selectionSort(A, ASIZE); // Sort the first ASIZE elements of the array A

  Serial.println();
  Serial.print("Sorted: ");
  printArray(A, 0, ASIZE-1);

  Serial.println("\nDone");
  Serial.flush();

  return 0;
}




// selectionSort(arr)
// Given an array (A), this function uses the selection sort algorithm to 
// sort the first N elements of the array into non-descreasing order.
void selectionSort(int A[], int N) {
  int smallest, temp;
  for(int i = 0; i < N-1; i++) { // go through the array from index 0 to N-2
    smallest = i;  // Find the smallest element from index i to the end.. start by assuming i is the smallest
    for(int j= i+1; j < N; j++) { // go from i+1 to N-1, looking for the smallest element
      if(A[j] < A[smallest]) { // update the smallest index if we find a smaller element
        smallest = j;
      }
    }
    // Finally, swap A[i] and A[smallest]
    temp = A[i];
    A[i] = A[smallest];
    A[smallest] = temp;
    Serial.print("\nSelected: ");
    Serial.println(A[i]);
    Serial.print("The array is now: ");
    printArray(A, 0, N-1);
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




