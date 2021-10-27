#include <iostream>

using namespace std;

int main() {
  float x = 0.0;
  float y = 1.0 / x;

  float z = 5.0 / 0;

  //   float a = 5 % 0;

  //   cout << "hi \r";
  //   cout << "hi \a";

  char character = '\47';
  character = '\x27';

  char A = 'A';
  char a = 'a';

  int i = A;

  cout << a - A << endl;

  cout << i << endl;

  int byte = 255;
  cout << "Byte in hex: " << hex << byte << endl;

  cout << hex << byte << endl;
  cout << byte << dec << byte << endl;

  cout << oct << byte << endl;
  cout << byte << oct << endl;

  int i = 10, j = 3;
  int k = (i % j * i / 3);

  cout << k << endl;

  return 0;
}