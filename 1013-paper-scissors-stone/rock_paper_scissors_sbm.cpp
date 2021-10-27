/******************************************************************************
Author : Jet Chien


Game Play:
The players may count aloud to three, or speak the name of the game (e.g. "Rock! Paper! Scissors!"), 
either raising one hand in a fist and swinging it down with each syllable or holding it behind their back. 
They then "throw" by extending it towards their opponent. 

- Rock wins against scissors.
- Scissors win against paper.
- Paper wins against rock.
*******************************************************************************/
#include <iostream>
#include "art.h"

using namespace std;

int main() {
    
    cout << "Please enter your choice:" << endl;
    cout << "Rock-(1) Paper-(2) Scissors-(3)" << endl;
    
    
    int input;
    cin >> input;
    
    switch (input) {
        case 1:
            cout << rock << endl;
            break;
            
        case 2:
            cout << paper << endl;
            break;
            
        case 3:
            cout << scissors << endl;
            break;
    }

    return 0;
}