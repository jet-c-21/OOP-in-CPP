#include <iostream>
using namespace std;

int main() {
    int a = 1;
    int b = 4;
    float c = a / (float)b;

    cout << typeid(c).name() << endl;
    cout << c << endl;


    return 0;
}