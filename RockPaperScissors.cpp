#include <iostream>
#include "list"

// Using std ns;
using namespace std;

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

// Create Game History Objects
struct GameHistory {
  string pcchoice;
  string userc;
  string result;
  string toString;

  GameHistory(string pcc, string ucc, string rez) :
    pcchoice(pcc), userc(ucc), result(rez), toString(pcchoice+userc+result) {}
};

// Init Objects
Weapon playerChoice;
Weapon computerChoice;
Game curGame;

// Store Games in List
std::list<GameHistory> games;

// Stores computers choice as a string
string pcstring;
// User Input
string uinput;

// Randomly generate computers choice
void getPcChoice() {
  int ran = (rand() % 3);
  if (ran == 0) {
    computerChoice = ROCK;
    pcstring = "r";
  }
    else if (ran == 1) {
        computerChoice = PAPER;
        pcstring = "p";
      } else {
          computerChoice = SCISSORS;
          pcstring = "s";
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
  if (curGame == TIE) {
    cout << "Game is a tie!" << endl;
    games.push_back(GameHistory(pcstring+"-",uinput,"-T"));
  } else if (curGame == PCWIN) {
    games.push_back(GameHistory(pcstring+"-",uinput,"-PC"));
    cout << "Computer Wins!" << endl;
  } else if (curGame == USERWIN) {
    games.push_back(GameHistory(pcstring+"-",uinput,"-USER"));
      cout << "You Win!" << endl;
    }
}

// Prints all games recorded in games list
void printHistory() {
  cout << "----------- Game History -----------" << endl;
  cout << "Format : PC-USER-WINNER" << endl;
  cout << "------------------------------------" << endl;
  for (GameHistory gh : games) {
    cout << gh.toString << endl;
  }
  cout << "----------- Game History -----------" << endl;
}

// Game Loop
bool fin = false;

int main() {
  // Seed for random numbers
  srand ( time(NULL) );
  // Continue string
  string contin;
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
  printHistory();
  cout << "Program finished!" << endl;
  return 0;
}
