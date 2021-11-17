#include <iostream>
using namespace std;

int main() {
  int x = 10;
  //   int *p, arr_a[3]; // bad declaration

  int *p;
  int arr_a[3];

  arr_a[0] = 20;
  //   arr_a[1] = &x;  // compile error

  int *arr_b[3];

  arr_b[0] = &x;
  //   arr_b[1] = x;  // compile error

  cout << "arr_a: " << endl;
  cout << arr_a[0] << endl;
  cout << arr_a[1] << endl;
  cout << arr_a[2] << endl;
  cout << arr_a[5] << endl;
  cout << endl;

  cout << "arr_b: " << endl;
  cout << arr_b[0] << endl;
  cout << arr_b[1] << endl;
  cout << arr_b[2] << endl;
  cout << arr_b[5] << endl;
  cout << endl;

  return 0;
}