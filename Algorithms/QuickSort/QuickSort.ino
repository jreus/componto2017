/*
 * An Implementation of the Quick Sort algorithm
 * 
 * References: 
 * http://www.geeksforgeeks.org/quick-sort/
 * https://www.youtube.com/watch?v=aQiWF4E8flQ
 * 
 * Sorting algorithms are algorithms that rearrange the elements of 
 * an array - also known as permuting the array - so that each element
 * is less than or equal to its successor.
 * 
* QUICKSORT (A, low, high)
 * Inputs:
 *  A: an array to sort
 *  low, high: starting and ending indices of a subarray of A to be sorted
 *
 * Result: The elements of the subarray A[low..high] are sorted into
 *  non-decreasing order.
 *  
 * Returns: nothing
 * 
 * 1. if low >= high, then the subarray A[low..high] has at most one element, 
 *    and therefore is a trivial case which is already sorted. 
 *    Just return without doing anything to A.
 * 2. otherwise do the following:
 *    A. Call PARTITION(A, low, high) to find a pivot point and set pivot to its result
 *    B. Recursively call QUICKSORT on the two sub-arrays of A on either side of the pivot index
 *       i. Call QUICKSORT(A, low, pivot - 1)
 *       ii. Call QUICKSORT(A, pivot + 1, high)
 *    
 *    
 * PARTITION(A, low, high)
 * Inputs:
 *   A: an array
 *   low, high: 
 *   
 * Result: Rearranges the elements of A[low..high] so that every element in
 * A[low..pivot-1] is less than or equal to A[pivot] and every element
 * in A[pivot+1..high] is greater than pivot. 
 * 
 * Returns: the value of pivot 
 *  
 * 1. set pivot to low
 * 2. for each u from low to high-1, do the following:
 *    A. if A[u] <= A[high], then swap A[pivot] with A[u] and increment pivot
 * 3. Swap A[pivot] with A[r]
 * 4. return pivot
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
  
  Serial.print("Sort the array:");
  printArray(A, 0, ASIZE-1);
  Serial.println();
  delay(2000);
  Serial.println("Sorting...");
  delay(2000);

  quickSort(A, 0, ASIZE-1); // Sort the array from idx 0 through ASIZE-1

  Serial.println();
  Serial.print("Sorted: ");
  printArray(A, 0, ASIZE-1);

  Serial.println("\nDone");
  Serial.flush();

  return 0;
}



// quickSort(arr, low, high)
// Given an array (arr), this function uses the quick sort algorithm recursively to 
// sort the elements from a starting index (low) to an ending index (high).
void quickSort(int arr[], int low, int high) {
  if(low >= high) {
    // do nothing to the array and exit the function, this is the trivial case
    return;
  } else {
    // Divide the array into two and conquer
    int pivot = partition(arr, low, high); // pick a pivot and arrange the array around that pivot
    quickSort(arr, low, pivot-1); // quicksort the left sub-array
    quickSort(arr, pivot+1, high); // quicksort the right sub-array
  }
}

// partition(a, low, high)
// This is a "helper function" that does the core work of the quicksort algorithm. 
// Given an array (a) and a low index (low) and high index (high), this function
// chooses the high element as a pivot, and divides the array into two sub-arrays, 
// one to the left with numbers less than the pivot, one to the right with numbers 
// greater than the pivot. 
//
// The partitioning process is illustrated well via this video:
// https://www.youtube.com/watch?v=aQiWF4E8flQ
int partition(int a[], int low, int high) {
  int wall = low, pivot = high;

  for(int i = low; i < high; i++) {
    if(a[i] <= a[pivot]) {
      // Move a[i] to the spot just right of the wall, then move the wall one step to the right
      arraySwap(a, wall, i);
      wall++;
    }
  }

  // Finally, put the pivot in the spot between the two sub arrays, where the wall is.
  arraySwap(a, wall, pivot);
  Serial.print("Partition pivot="); 
  Serial.print(a[wall]);
  Serial.print(" Array=");
  printArray(a, 0, ASIZE-1);
  return wall; // return the index where the pivot landed
}

// arraySwap(arr, i1, i2)
// Given an array (arr), this function swaps the positions of two elements 
// given their indexes (i1 and i2).
void arraySwap(int arr[], int i1, int i2) {
  int temp = arr[i1];
  arr[i1] = arr[i2];
  arr[i2] = temp;
}

// copyArray(from, low, high, to, to_idx)
// Copies elements from a low index (from_left) to a high index (from_right) of one array (from) 
// into a second array (to), starting at a specific index (to_start).
void copyArray(int from[], int from_left, int from_right, int to[], int to_start) {
  for(int idx = from_left; idx <= from_right; idx++) {
    to[to_start] = from[idx];
    to_start++;
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




