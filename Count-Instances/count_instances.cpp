#include <iostream>

using namespace std;

class Class {
  static int Counter;
 public:
  Class() {
    ++Counter;
  };

  ~Class() {
    --Counter;
    if (Counter == 0)
      cout << "Bye, bye!" << endl;
  };

  static void HowMany() {
    cout << Counter << " instances" << endl;
  }
};

int Class::Counter = 0;

int main() {
  Class::HowMany();

  Class a;
  Class b;

  b.HowMany();

  Class c;
  Class d;

  d.HowMany();
}