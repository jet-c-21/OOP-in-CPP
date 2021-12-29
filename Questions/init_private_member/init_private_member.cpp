#include <iostream>
#include <utility>
#include <string>

using namespace std;

class Dog {
 private:
  static int x;

 public:
  static int total;
  string name;
  int id;
  explicit Dog(string name) {
    this->name = move(name);
    total += 1;
    this->id = total;
  }

  void show_info() {
    cout << name << "(" << id << ")" << endl;
  }

  static void show_dog_total() {
    cout << "Dog total: " << total << endl;
  }

  static void show_x() {
    cout << "x = " << x << endl;
  }
};

int Dog::total = 0;
int Dog::x = 777;

int main() {

  Dog lucky("Lucky"), puff("Puff");
  lucky.show_info();
  puff.show_info();

  Dog::show_dog_total();

  cout << lucky.total << endl;
  cout << Dog::total << endl;
//  cout << Dog::x;
  Dog::show_x();

}