#include <iostream>
#include <limits>

using namespace std;

void invalid_choice_prompt() {
  string msg = "\nInvalid Command! Please try again.";
  cout << msg << endl;
}

int ask_user_rps() {
  // ask user's choice of Rock or Paper or Scissors
  while (1) {
    string msg =
        "\nPlease enter your choice:\nRock - 1\nPaper - 2\nScissors - 3";
    cout << msg << endl;

    int user_choice;
    cin >> user_choice;

    cout << "raw input: " << user_choice << endl;

    if (cin.fail()) {
      invalid_choice_prompt();
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    return user_choice;
  }
}

int main() {
  int user_choice = ask_user_rps();
  cout << "uc: " << user_choice << " type: " << typeid(user_choice).name();

  return 0;
}