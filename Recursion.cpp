#include <iostream>

using namespace std;

// Config of output

// Fib Numbers to output
int fibNumbers = 20;

// Config of output

// Recursive fib method
int fib(int n) {
  if (n == 0)
    return 0;
    else if (n == 1)
        return 1;
        else return fib(n-1) + fib(n-2);
}

// Program
int main() {
  for (int x = 0; x < fibNumbers; x++)
    cout << fib(x) << " , ";

  cout << endl;
  return 0;
}
