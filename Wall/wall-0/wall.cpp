#include <iostream>
#include <iomanip>

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

    

    int win_count = 1, lose_count = 3, tie_count = 0, game_count = 4;

    float win_rate = 0.f;
    if ((win_count + lose_count) != 0) {
        win_rate = win_count / (float)(win_count + lose_count);
    }

    cout << win_rate << endl;

    cout << endl;
    cout << "You've played " << game_count << " games." << endl;
    cout << "Tie Count: " << tie_count << endl;
    cout << "Win Count: " << win_count << endl;
    cout << "Lose Count: " << lose_count << endl;
    cout << "Win Rate: " << win_rate << endl;

    return 0;
}