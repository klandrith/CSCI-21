/*
  Name: Kyle Landrith
  Small rock-paper-scissors game
*/

#include <iostream>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::rand;

void ClearScreen();

int main() {
  char understand_instructions;
  int user_choice = 0;
  int comp_choice = 0;
  bool winner = false;
  bool user_won = false;
  bool comp_won = false;
  char play_again = 'y';
  // Seed the Random Number Generator
  srand(time(0));

  cout << "We are about to play a game of rock paper scissors..."
       << "\nIn order to play you will be prompted to enter a selection..."
       << "\nFor rock enter a 1, for paper enter a 2, and for scissors enter a 3...\n"
       << "Enter Y if you understand...?" << endl;
       cin >> understand_instructions;

  if (understand_instructions == 'Y' || understand_instructions == 'y') {
    while (play_again == 'Y' || play_again == 'y') {
      ClearScreen();
      comp_choice = rand() % 3 + 1;
      cout << "Enter your selection (1 = rock, 2 = paper, 3 = rock): ";
      cin >> user_choice;

      if (user_choice == comp_choice) {
        comp_won = false;
        user_won = false;
      }
      else if (user_choice == 1 && comp_choice == 3) {
        user_won = true;
        comp_won = false;
        cout << "Rock beats scissors!" << endl;
      }
      else if (user_choice == 1 && comp_choice == 2) {
        user_won = false;
        comp_won = true;
        cout << "Paper beats rock!" << endl;
        }
        else if (user_choice == 2 && comp_choice == 1) {
          user_won = true;
          comp_won = false;
          cout << "Paper beats rock!" << endl;
        }
        else if (user_choice == 2 && comp_choice == 3) {
          user_won = false;
          comp_won = true;
          cout << "Scissors beat paper!" << endl;
        }
        else if (user_choice == 3 && comp_choice == 1) {
          user_won = false;
          comp_won = true;
          cout << "Rock beats scissors!" << endl;
        }
        else if (user_choice == 3 && comp_choice == 2) {
          user_won = true;
          comp_won = false;
          cout << "Scissors beats paper!" << endl;
        }
        else {
          cout << "Invalid selection..." << endl;
          user_won = false;
          comp_won = false;
        }
        if (comp_won) {
          cout << "You lost! The computer won!" << endl;
        }
        else if (user_won) {
          cout << "You won! The computer lost!" << endl;
        }
        else if (user_won == false && comp_won == false) {
          cout << "It was a draw! Both players selected the same thing!" << endl;
        }
        cout << "Would you like to play again? (Y/N): ";
        cin >> play_again;
        ClearScreen();
        cout << "Goodbye..." << endl;
      }
    }
  return 0;
}

//clearscreen function
void ClearScreen() {
#ifdef _WIN32
  std::system("cls");
#else
  // Assume POSIX
  std::system("clear");
#endif
}
