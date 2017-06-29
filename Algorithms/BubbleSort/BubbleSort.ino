/*
 * An implementation of the Bubble Sort algorithm.
 * 
 * Bubble Sort works by repeatedly going through the array looking at pairs of elements 
 * along the way. If a pair is not in order, the two elements are swapped. This repeats
 * until a pass happens where no swaps are made, indicating that the array is sorted.
 * The algorithm is called bubble sort because of the way the largest values "bubble" to the
 * end of the array one after another. 
 * 
 * References: 
 * http://www.geeksforgeeks.org/bubble-sort/
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
  
  Serial.println("Sort an array using Bubble Sort:");
  delay(2000);
  Serial.println("Sorting...");
  printArray(A, 0, ASIZE-1);
  delay(2000);

  //bubbleSort(A, ASIZE); // Sort the first ASIZE elements of the array A
  betterBubbleSort(A, ASIZE);
  
  Serial.println();
  Serial.print("Sorted: ");
  printArray(A, 0, ASIZE-1);

  Serial.println("\nDone");
  Serial.flush();

  return 0;
}




// bubbleSort(sortme, N)
// Given an array (sortme), this function uses the bubble sort algorithm to 
// sort the first N elements of the array into non-descreasing order.
void bubbleSort(int sortme[], int N) {
  int i, j, pass=1;
  bool swapped = true;
  while(swapped) {      // outer loop 
    swapped = false;
    for(j = 1; j < N; j++) {    // inner loop (responsible for each pass)
       if(sortme[j - 1] > sortme[j]) {
         // swap the elements at j - 1 and j
         int temp = sortme[j-1];
         sortme[j-1] = sortme[j];
         sortme[j] = temp;
         swapped = true; // a swap has been made
       }
    }
    Serial.print("Pass ");
    Serial.print(pass++);
    Serial.print(": ");
    printArray(sortme, 0, N-1);
   } 
}

// betterBubbleSort(sortme, N)
// This is a modified version of the bubble sort algorithm that takes advantage of an observation.
// - After the first pass, the largest element is at the end of the array.
// - After the second pass, the next largest element bubbles up to the end of the array (to the left of the largest element) 
// - After the third pass, the third largest element bubbles up to its correct place.. and so on..
// This means each pass doesn't need to go through the whole array, it can stop at the point
// where we know the remaining elements are in order.  
void betterBubbleSort(int sortme[], int N) {
  int i, j;
  for(i = 0; i < N; i++) {            // outer loop, counts how many elements are at the end of the array and sorted
    for(j = 1; j < (N - i); j++) {    // inner loop, responsible for doing a pass from element 1 to element N - 1 - i
       if(sortme[j - 1] > sortme[j]) {
         // swap the elements at j - 1 and j
         int temp = sortme[j-1];
         sortme[j-1] = sortme[j];
         sortme[j] = temp;
       }
    } 
    Serial.print("Pass ");
    Serial.print(i+1);
    Serial.print(": ");
    printArray(sortme, 0, N-1);
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




