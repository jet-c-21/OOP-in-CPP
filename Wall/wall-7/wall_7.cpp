#include <iostream>

using namespace std;

void f(int a, int b) { cout << a - b << endl; }

void f(int c, int d) { cout << c + d << endl; }

int main(void) {
  f(2, 1);

  return 0;
}
