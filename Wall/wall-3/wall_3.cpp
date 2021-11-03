#include <iostream>
using namespace std;

int main()
{
    int number;
    do{
        cin >> number;
        if(cin.fail())
            cout << "Not a number " << endl;
    }while(!cin.fail());
    cout << "number is " << number << endl;
    system("pause");
    return 0;
}