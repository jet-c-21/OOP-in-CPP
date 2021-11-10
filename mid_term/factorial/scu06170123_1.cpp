#include <iostream>
using namespace std;

int main() {
  int n;
  long double factorial = 1.0;

  cout << "Please input a positive interger to get the factorial:";
  cin >> n;

  if (n < 0)
    cout << "Error! Factorial of a negative number doesn't exist.";
  else {
    for (int i = 1; i <= n; ++i) {
      factorial *= i;
    }
    cout << n << "! = " << factorial;
  }

  return 0;
}