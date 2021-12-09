#include <iostream>

using namespace std;

class MyClass {  // The class
                 //   int val = 100;

 public:  // Access specifier
          //   MyClass();

  int myNum;        // Attribute (int variable)
  string myString;  // Attribute (string variable)
};

int main() {
  MyClass myObj;  // Create an object of MyClass

  // Access attributes and set values
  myObj.myNum = 15;
  myObj.myString = "haha";

  // Print attribute values
  cout << myObj.myNum << "\n";
  cout << myObj.myString;

  MyClass obj_b;
  cout << obj_b.myNum << endl;

  //   cout << obj_b.val << endl;
  //   cout << myObj.val << endl;

  // MyClass

  return 0;
}
