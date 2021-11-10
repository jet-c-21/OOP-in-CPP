
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

#include <iostream>
#include <limits>

using namespace std;

int user_count = 0;
int* user_game_record;
string* user_name_record;

void invalid_user_count_prompt() {
  string msg =
      "\nInvalid Command! Please enter a positive interger for the count of "
      "players.";
  cout << msg << endl;
}

int ask_user_count_check_input(int user_choice) {
  if (user_choice > 0) return 1;
  return 0;
}

int ask_user_count() {
  // ask how many players are going to play the game
  string msg = "\nHow many players are playing the game?";
  cout << msg << endl;

  while (1) {
    int user_choice;
    cin >> user_choice;

    // cout << "raw input: " << user_choice << endl;

    if (ask_user_count_check_input(user_choice)) {
      return user_choice;
    }
    invalid_user_count_prompt();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}

void invalid_command_prompt() {
  string msg = "\nInvalid Command! Please try again.";
  cout << msg << endl;
}

int ask_game_mode_check_input(int user_choice) {
  if (user_choice == 1 || user_choice == 2) return 1;
  return 0;
}

int ask_game_mode(string user_name) {
  // ask user's choice of the game mode
  while (1) {
    string msg = "\nDear " + user_name +
                 ", Which game mode do you want to play:\nGreater one wins - "
                 "1\nSmaller one wins - 2\n";
    cout << msg << endl;

    int user_choice;
    cin >> user_choice;

    // cout << "raw input: " << user_choice << endl;

    if (ask_game_mode_check_input(user_choice)) {
      return user_choice;
    }
    invalid_command_prompt();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }
}

string ask_user_name(int user_id) {
  cout << "\nPlease enter the user name for player-" << user_id << ":" << endl;

  string user_name;
  cin >> user_name;

  return user_name;
}

int ask_throw_dice(string user_name) {
  // ask user's choice of Rock or Paper or Scissors
  while (1) {
    string msg =
        "\nDear " + user_name + ", Please enter a number to throw the dice:";
    cout << msg << endl;

    int user_choice;
    cin >> user_choice;

    // cout << "raw input: " << user_choice << endl;

    if (cin.fail()) {
      invalid_command_prompt();
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }

    return user_choice;
  }
}

void set_dice_seed(int seed) { srand(time(NULL) + seed); }

int get_dice_val() { return rand() % 6 + 1; }

int get_user_dice(string user_name) {
  int dice_val = get_dice_val();
  cout << "\nDear " + user_name + ", you threw a " << dice_val << endl;

  return dice_val;
}

int get_comp_dice() {
  int dice_val = get_dice_val();
  cout << "The computer threw a " << dice_val << endl;

  return dice_val;
}

int greater_mode_judge(int user_dice_value, int comp_dice_val) {
  /*
  user win -> 1
  comp win -> 0
  tie -> -1
  */
  if (user_dice_value > comp_dice_val) {
    return 1;
  } else if (user_dice_value < comp_dice_val) {
    return 0;
  } else {
    return -1;
  }
}

int smaller_mode_judge(int user_dice_value, int comp_dice_val) {
  /*
  user win -> 1
  comp win -> 0
  tie -> -1
  */
  if (user_dice_value < comp_dice_val) {
    return 1;
  } else if (user_dice_value > comp_dice_val) {
    return 0;
  } else {
    return -1;
  }
}

int dice_game(int user_id) {
  string user_name = ask_user_name(user_id);
  user_name_record[user_id - 1] = user_name;
  int win_count = 0;
  while (1) {
    int game_mode = ask_game_mode(user_name);
    int user_seed = ask_throw_dice(user_name);
    set_dice_seed(user_seed);

    int user_dice_val = get_user_dice(user_name);
    int comp_dice_val = get_comp_dice();

    // cout << user_dice_val << " " << comp_dice_val << endl;
    int game_result;
    if (game_mode == 1) {
      game_result = greater_mode_judge(user_dice_val, comp_dice_val);
    } else {
      game_result = smaller_mode_judge(user_dice_val, comp_dice_val);
    }

    if (game_result == 1) {
      win_count += 1;
      cout << "Congradulation! You've won " << win_count
           << " game(s), try to beat the computer in more games!" << endl;
    } else if (game_result == 0) {
      cout << "You lose! You've won " << win_count << " game(s)" << endl;
      return win_count;
    } else {
      cout << "Seems that we have a tie, let's play again." << endl;
    }
  }
}

void best_player_prompt(int user_idx) {
  cout << "The best player is " << user_name_record[user_idx] << endl;
}

void worst_player_prompt(int user_idx) {
  cout << "The worst player is " << user_name_record[user_idx] << endl;
}

void summary() {
  cout << "\nGame Summary:" << endl;
  if (user_count == 1) {
    best_player_prompt(0);
    worst_player_prompt(0);
    return;
  }

  // find best player
  int best_player_idx = 0;
  int curr_max_win_count = user_game_record[0];
  for (int i = 1; i < user_count; i++) {
    if (user_game_record[i] > curr_max_win_count) {
      curr_max_win_count = user_game_record[i];
      best_player_idx = i;
    }
  }

  // find worst player
  int worst_player_idx;
  for (int i = 0; i < user_count; i++) {
    if (i != best_player_idx) {
      worst_player_idx = i;
      break;
    }
  }
  int curr_min_win_count = user_game_record[worst_player_idx];
  for (int i = 0; i < user_count; i++) {
    if (i == best_player_idx) {
      continue;
    }

    if (user_game_record[i] < curr_min_win_count) {
      curr_min_win_count = user_game_record[i];
      worst_player_idx = i;
    }
  }

  best_player_prompt(best_player_idx);
  worst_player_prompt(worst_player_idx);
}

int main() {
  user_count = ask_user_count();
  //   cout << "user count: " << user_count << endl;

  cout << "Beware! the order of the player might influence the final summary "
          "of this game."
       << endl;

  // initialzie a global array to record the game result for each player
  user_game_record = new int[user_count];
  user_name_record = new string[user_count];

  for (int user_id = 1; user_id <= user_count; user_id++) {
    int win_count = dice_game(user_id);
    user_game_record[user_id - 1] = win_count;
  }

  summary();
  return 0;
}