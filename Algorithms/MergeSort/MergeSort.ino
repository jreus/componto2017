/*
 * An Implementation of the MergeSort algorithm
 * 
 * Sorting algorithms are algorithms that rearrange the elements of 
 * an array - also known as permuting the array - so that each element
 * is less than or equal to its successor.
 * 
 * MERGESORT (A, p, r)
 * Inputs:
 *  A: an array to sort
 *  low, high: starting and ending indices of a subarray of A to be sorted
 *
 * Result: The elements of the subarray A[low..high] are sorted into
 *  non-decreasing order.
 * 
 * 1. if low >= high, then the subarray A[low..high] has at most one element, 
 *    and therefore is a trivial case which is already sorted. 
 *    Just return without doing anything to A.
 * 2. otherwise do the following:
 *    A. Calculate the middle index of the array: set mid to floor((low+high) / 2)
 *    B. Divide A into two halves and sort each half individually by calling MERGESORT recursively
 *      i. Recursively call MERGESORT(A,low,mid)
 *      ii. Recursively call MERGESORT(A, mid+1, high)
 *    C. Call MERGE(A,p,q,r) to recombine the two sorted halves
 *
 * MERGE(A, low, mid, high)
 * Inputs:
 *   A: an array
 *   low, mid, high: indices of A defining the two subarrays that need to be merged. Each of the 
 *   subarrays A[low..mid] and A[mid+1..high] is assumed to be already sorted.
 *   
 * Result: The subarray A[low..high] contains the elements originally
 * in A[low..mid] and A[mid+1..high] but now the entire subarray is sorted.
 *  
 * 1. set n1 to mid-low+1 and set n2 to high-mid 
 * 2. create two new temporary arrays B[] with size n1+1 and C with size n2+1
 * 3. Copy A[low..mid] into B[0..n1-1], and copy A[mid+1..high] into C[0..n2-1]
 * 4. Set the last slot of B and C (B[n1] and C[n2]) to a number bigger than anything in A 
 *    (pick a big number.. like 32000)
 * 5. set i and j to 1
 * 6. for k = low to high:
 *    A. If B[i] <= C[j], then set A[k] to B[i] and increment i
 *    B. Otherwise, (B[i] > C[j]), set A[k] to C[j] and increment j
 *  
 *  Reference:
 *  Using preprocessor directives: https://msdn.microsoft.com/en-us/library/36k2cdd4.aspx
 *  MergeSort: http://www.geeksforgeeks.org/merge-sort/
 *  Pass by Value & Reference: http://denniskubes.com/2012/08/20/is-c-pass-by-value-or-reference/
 *  Static vs. Dynamic Arrays: https://www.youtube.com/watch?v=qTb1sZX74K0
 *  Dynamic Memory Allocation in C: https://www.codingunit.com/c-tutorial-the-functions-malloc-and-free
 *    https://en.wikipedia.org/wiki/C_dynamic_memory_allocation
 *    
 *  Dynamic Memory in C++: 
 *    http://www.cplusplus.com/doc/tutorial/dynamic/
 *    http://www.cprogramming.com/tutorial/dynamic_memory_allocation.html
 *    https://www.programiz.com/cpp-programming/memory-management
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

  mergeSort(A, 0, ASIZE-1); // Sort the array from idx 0 through ASIZE-1

  Serial.println();
  Serial.print("Sorted: ");
  printArray(A, 0, ASIZE-1);

  Serial.println("\nDone");
  Serial.flush();

  return 0;
}


// The MergeSort function
void mergeSort(int arr[], int low, int high) {
  if(low >= high) {
    // do nothing
    return;
  } else {
    // Divide and conquer
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid); // recursively mergesort the two halves of the array
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high); // merge the two sorted halves of the array
  }
}

void merge(int a[], int low, int mid, int high) {
  int n1, n2;

  // calculate the sizes for the temporary arrays B and C
  n1 = mid - low + 1;
  n2 = high - mid;

  // ask the CPU for some memory for our arrays (we don't know their size ahead of time so we allocate the memory dynamically using "new")
  int * B = new int[n1+1]; // This creates a dynamically allocated array of size n1+1
  int * C = new int[n2+1];

  // Copy A[low..mid] into B and A[mid+1..high] into C
  copyArray(a, low, mid, B, 0);
  copyArray(a, mid+1, high, C, 0);

  B[n1] = 32000;
  C[n2] = 32000;

  Serial.print("\nMERGE "); 
  Serial.print(low);
  Serial.print(" ");
  Serial.print(mid);
  Serial.print(" ");
  Serial.print(high);
  Serial.println(": ");


  Serial.print("B: ");
  printArray(B, 0, n1+1);
  Serial.print("C: ");
  printArray(C, 0, n2+1);

  int i = 0, j = 0;
  for(int k = low; k <= high; k++) {
    if(B[i] <= C[j]) {
      a[k] = B[i++];
    } else {
      a[k] = C[j++];
    }
    Serial.print("a: ");
    printArray(a, 0, ASIZE-1);
  }

  // Always remember to free up your dynamic memory after you use it using delete!
  // use "delete" for single pieces of data, use "delete[]" for arrays
  delete[] B;
  delete[] C;
  
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


