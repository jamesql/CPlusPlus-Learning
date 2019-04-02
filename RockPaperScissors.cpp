#include <iostream>

// Create Weapons
enum Weapon {
  ROCK = 0,
  PAPER = 1,
  SCISSORS = 2
};

// Create Game Objects
enum Game {
  PCWIN = 0,
  USERWIN = 1,
  TIE = 2
};

// Using std ns;
using namespace std;

// Init Objects
Weapon playerChoice;
Weapon computerChoice;
Game curGame;

// Stores computers choice as a string
string pcstring;

// Randomly generate computers choice
void getPcChoice() {
  int ran = (rand() % 3);
  if (ran == 0) {
    computerChoice = ROCK;
    pcstring = "Rock";
  }
    else if (ran == 1) {
        computerChoice = PAPER;
        pcstring = "Paper";
      } else {
          computerChoice = SCISSORS;
          pcstring = "Scissors";
        }
}

// Calculates Win
void calcWin() {
  if (playerChoice == computerChoice)
    curGame = TIE;
  else
    if (playerChoice == ROCK && computerChoice != PAPER)
      curGame = USERWIN;
    else if (computerChoice == ROCK && playerChoice != PAPER)
      curGame = PCWIN;
      else if (playerChoice > computerChoice)
            curGame = USERWIN;
            else
              curGame = PCWIN;
 }

void sendResult() {
  if (curGame == TIE)
    cout << "Game is a tie!" << endl;
  else if (curGame == PCWIN)
    cout << "Computer Wins!" << endl;
    else if (curGame == USERWIN)
      cout << "You Win!" << endl;
}

// Game Loop
bool fin = false;

int main() {
  // Seed for random numbers
  srand ( time(NULL) );
  // Continue string
  string contin;
  // User Input
  string uinput;
  // Game While Loop
  do {
  cout << "Rock, Paper, Scissors! (r/p/s) : " << endl;
  cin >> uinput;
  if (uinput.compare("r") == 0) playerChoice = ROCK;
  else if (uinput.compare("p") == 0) playerChoice = PAPER;
    else if (uinput.compare("s") == 0) playerChoice = SCISSORS;
      else playerChoice = ROCK;
  cout << "You chose " << uinput << " (" << playerChoice << ")" << "!" << endl;
  getPcChoice();
  cout << "PC Chose " << pcstring << " (" << computerChoice << ")" << "!" << endl;
  calcWin();
  sendResult();
  cout << "Continue? (y/n) : ";
  cin >> contin;
  if (contin.compare("y") != 0)
    fin = true;
  } while (!fin);
  cout << "Program finished!" << endl;
  return 0;
}
