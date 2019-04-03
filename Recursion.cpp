#include <iostream>

using namespace std;

// Config of output

// Fib Numbers to output
int fibNumbers = 20;

// Powers base & exponent
int base = 3;
int expon = 4;
// Config of output

// Recursive fib method
int fib(int n) {
  if (n == 0)
    return 0;
    else if (n == 1)
        return 1;
        else return fib(n-1) + fib(n-2);
}

// Recursive Power method
int power(int base, int expo) {
    if (expo == 1)
      return base;
      else if (expo == 2)
            return base * base; 
             else return base * power(base,expo-1);
}

// Program
int main() {
  for (int x = 0; x < fibNumbers; x++)
    cout << fib(x) << " , ";
  cout << endl;
  cout << "Power : " << power(base,expon) << endl;
  cout << endl;
  return 0;
}
