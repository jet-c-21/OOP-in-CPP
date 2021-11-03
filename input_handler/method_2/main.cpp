#include <iostream>
#include <limits>

using namespace std;

void invalid_choice_prompt() {
  string msg = "\nInvalid Command! Please try again.";
  cout << msg << endl;
}

int ask_user_rps_check_input(int user_choice) {
  if (user_choice == 1 || user_choice == 2 || user_choice == 3) return 1;
  return 0;
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

    if (ask_user_rps_check_input(user_choice)) {
      return user_choice;
    }
    invalid_choice_prompt();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}

int main() {
  int user_choice = ask_user_rps();
  cout << "uc: " << user_choice << " type: " << typeid(user_choice).name();

  return 0;
}