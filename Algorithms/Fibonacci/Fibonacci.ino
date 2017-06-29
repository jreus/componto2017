/*  
 *   This program shows two functions that compute the Nth 
 *   number of the Fibonacci sequence: F(N) = F(N-1)+F(N-2)
 *   
 *   One function shows an iterative solution, the second a recursive solution.
 *  
 *  
 *  Reference: 
 *  https://www.ics.uci.edu/~eppstein/161/960109.html
 *  http://will.thimbleby.net/algorithms/doku.php?id=fibonacci
 *  
 *  The Fibonacci story:
 *  Leonardo of Pisa (aka Fibonacci) was interested in many things, 
 *  including a subject we now know as population dynamics: 
 *  For instance, how quickly would a population of rabbits expand 
 *  under appropriate conditions?
 *  
 *  As is typical in mathematics (and analysis of algorithms is a form of 
 *  mathematics), we make the problem more abstract to get an idea of the 
 *  general features without getting lost in detail:
 *  
 *  We assume that a pair of rabbits has a pair of children every year.
 *  These children are too young to have children of their own until two 
 *  years later. Rabbits never die.
 *  
 *  (The last assumption sounds stupid, but makes the problem simpler. 
 *  After we have analyzed the simpler version, we could go back and add an 
 *  assumption e.g. that rabbits die in ten years, but it wouldn't change 
 *  the overall behavior of the problem very much.)
 *  
 *  We then express the number of pairs of rabbits as a function of time 
 *  (measured as a number of years since the start of the experiment):
 *  
 *  F(1) = 1 -- we start with one pair
 *  F(2) = 1 -- they're too young to have children the first year
 *  F(3) = 2 -- in the second year, they have a pair of children
 *  F(4) = 3 -- in the third year, they have another pair
 *  F(5) = 5 -- we get the first set of grandchildren
 *  
 *  The Nth Fibonacci number is defined recursively: 
 *  F(n) = F(n-1) + F(n-2)
 *  
 *  You could read this as: All the previous rabbits are still there (F(n-1)) 
 *  plus we get one pair of children for every pair of rabbits we had two years ago (F(n-2)).
 *  
 */

#include <arduino.h>

int main() {
  init();

  int N, result;
  Serial.begin(9600);
  Serial.setTimeout(10000);

  Serial.print("\n Hello. \n Please enter an integer N: "); 
  N = Serial.parseInt(); 
  Serial.println(N);

  result = fib_iter(N);
  //result = fib_recursive(N);
 
  delay(1000);
  Serial.print("The "); 
  Serial.print(N); 
  Serial.print(" Fibonacci number is ");
  Serial.println(result);
  
  Serial.println("Goodbye");
  delay(1000);
  return 0;
}

// A function that calculates the Nth Fibonacci number using iteration (loops).
int fib_iter(int N) {
  int fib_N1 = 1, fib_N2 = 1;

  if(N == 1 || N == 2) {
    return 1;
  }

  for(int i = 3; i <= N; i++) {
      int fib_N;
      fin_N = fib_N1 + fib_N2;
      fib_N2 = fib_N1;
      fib_N1 = fib_N;
  }
  return fib_N1;
}


// A function that calculates the Nth Fibonacci number using recursive calls to itself.
int fib_recursive(int N) {
  if(N == 1 || N == 2) {
    return 1;
  } else {
    return fib_recursive(N-1) + fib_recursive(N-2);
  }
}


