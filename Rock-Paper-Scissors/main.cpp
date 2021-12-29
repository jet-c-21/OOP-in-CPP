/******************************************************************************
Author: Jet Chien
GitHub: https://github.com/jet-c-21

Rock : 1
Paper : 2
Scisscors : 3
*******************************************************************************/
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

#include <iostream> /* cin cout endl */
#include <limits>   /* numeric_limits */
#include <string>   /* string */

#include "art.h"  // Rock Paper Scissors Ascii View

using namespace std;

class RPS {
 public:
  int game_count = 0;
  int tie_count = 0;
  int win_count = 0;
  int lose_count = 0;

  // operation funcs
  int get_comp_choice();
  int ask_play_check_input(string user_choice);
  int ask_play();
  int ask_user_rps_check_input(int user_choice);
  int ask_user_rps();
  int ask_replay();
  void judge(int user_choice, int comp_choice);
  void game();
  void show_summary();
  void start();

  // prompt funcs
  void greet_prompt();
  void invalid_choice_prompt();
  void tie_prompt();
  void win_prompt();
  void lose_prompt();
  void comp_choice_prompt(int comp_choice);
  void bye_prompt();

};

void RPS::game() {
  game_count += 1;

  int user_choice = ask_user_rps();
  int comp_choice = get_comp_choice();
  comp_choice_prompt(comp_choice);
  judge(user_choice, comp_choice);

  if (ask_replay()) game();
}

void RPS::show_summary() {
  double win_rate = 0.0f;
  if ((win_count + lose_count) != 0) {
    win_rate = (win_count / (double) (win_count + lose_count)) * 100;
  }
  cout << endl;
  cout << "You've played " << game_count << " games." << endl;
  cout << "Tie Count: " << tie_count << endl;
  cout << "Win Count: " << win_count << endl;
  cout << "Lose Count: " << lose_count << endl;
  cout << "Win Rate: " << win_rate << "%" << endl;
}

int RPS::get_comp_choice() {
  srand(time(NULL));
  return rand() % 3 + 1;
}

void RPS::greet_prompt() {
  string greet = "Welcome to the Rock, Paper, Scisscors Game!";
  cout << greet << endl;
}

void RPS::invalid_choice_prompt() {
  string msg = "\nInvalid Command! Please try again.";
  cout << msg << endl;
}

int RPS::ask_play_check_input(string user_choice) {
  if (user_choice == "y" || user_choice == "n") return 1;
  return 0;
}

int RPS::ask_play() {
  while (1) {
    string msg = "\nDo you want to play? (Please enter y or n)";
    cout << msg << endl;

    string user_choice;
    cin >> user_choice;

    if (ask_play_check_input(user_choice)) {
      if (user_choice == "y") return 1;
      return 0;
    } else {
      invalid_choice_prompt();
    }
  }
}

int RPS::ask_user_rps_check_input(int user_choice) {
  if (user_choice == 1 || user_choice == 2 || user_choice == 3) return 1;
  return 0;
}

int RPS::ask_user_rps() {
  // ask user's choice of Rock or Paper or Scissors
  while (1) {
    string msg =
        "\nPlease enter your choice:\nRock - 1\nPaper - 2\nScissors - 3";
    cout << msg << endl;

    int user_choice;
    cin >> user_choice;

    if (ask_user_rps_check_input(user_choice)) {
      return user_choice;
    }

    invalid_choice_prompt();

    // refresh the buffer in cin
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}

void RPS::tie_prompt() {
  cout << "Seems we are tied." << endl;
  tie_count += 1;
}

void RPS::win_prompt() {
  cout << "Oh! You win." << endl;
  win_count += 1;
}

void RPS::lose_prompt() {
  cout << "Ha! Loser." << endl;
  lose_count += 1;
}

void RPS::comp_choice_prompt(int comp_choice) {
  cout << "Computer:" << endl;
  switch (comp_choice) {
    case 1:cout << rock << endl;
      break;

    case 2:cout << paper << endl;
      break;

    case 3:cout << scissors << endl;
      break;
  }
}

void RPS::bye_prompt() { cout << "\nBye Bye! See you next time."; }

void RPS::judge(int user_choice, int comp_choice) {
  if (user_choice == comp_choice) {
    tie_prompt();
    return;
  }

  switch (user_choice) {
    case 1:  // rock case
      if (comp_choice == 3) {
        win_prompt();
      } else {
        lose_prompt();
      }
      break;

    case 2:  // paper case
      if (comp_choice == 1) {
        win_prompt();
      } else {
        lose_prompt();
      }
      break;

    case 3:  // scissors case
      if (comp_choice == 2) {
        win_prompt();
      } else {
        lose_prompt();
      }
      break;
  }
}

int RPS::ask_replay() {
  while (1) {
    string msg = "\nDo you want to play again? (Please enter y or n)";
    cout << msg << endl;

    string user_choice;
    cin >> user_choice;

    if (ask_play_check_input(user_choice)) {
      if (user_choice == "y") return 1;
      return 0;
    } else {
      invalid_choice_prompt();
    }
  }
}

void RPS::start() {
  greet_prompt();

  if (ask_play()) {
    game();
    show_summary();
  };

  bye_prompt();
}

int main() {
  RPS rps;
  rps.start();

  return 0;
}