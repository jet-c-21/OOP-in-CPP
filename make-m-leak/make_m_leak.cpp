#include <iostream>

using namespace std;

class Class {
 public:
  Class(int val) {
    value = new int[val];
    cout << "Allocation (" << val << ") done." << endl;
  }
  int *value;
};

void make_a_leak() {
  Class object(1000);
}

int main() {
  make_a_leak();
}