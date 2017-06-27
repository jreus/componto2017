// In general, F(n) = F(n-1) + F(n-2)
int fib_iter(int N) {
  int fib_1, fib_2, fib;
  for(int i = 1; i <= N; i++) {
    if(i <= 2) {
      fib_1 = 1;
      fib_2 = 1;
    } else {
      fib = fib_1 + fib_2;
      fib_2 = fib_1;
      fib_1 = fib;
    }
  }
  return fib_1;
}

int fib_recursive(int N) {
  if(N < 3) {
    return 1;
  } else {
    return fib_recursive(N-1) + fib_recursive(N-2);
  }
}

