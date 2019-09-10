// Example program
#include <iostream>
#include <string>
#include "list"

using namespace std;

int gamesToBePlayed;

struct game {
    public:
    int winner;
    
    string getWinningString() {
        if (winner == 0) {
            return "Tails Win!";
        } else {
            return "Heads Win!";
        }
    }
    
    game(int win) : winner(win) {}

};

struct gameHistory {
    public:
    std::list<game> games;
    int tails = 0;
    int heads = 0;
    double perTails;
    double perHeads;
    void addHistory(game history) {
        games.push_back(history);
        if (history.winner == 0) {
            tails++;
            perTails = (static_cast<double>(tails) / static_cast<double>(gamesToBePlayed));
        } else {
            heads++;
            perHeads = (static_cast<double>(heads) / static_cast<double>(gamesToBePlayed));

        }
    }
    void toString() {
        cout << "Heads : " << heads << " (" << perHeads*100 << "%)" << endl;
        cout << "Tails : " << tails << " (" << perTails*100 << "%)" << endl;
        for (game g : games) {
        cout << g.getWinningString() << endl;
        }
    }
    std::list<game> getHistoryList() {
        return games;
    }
    
    gameHistory(game thisGame)
    {
     addHistory(thisGame);
    }
    gameHistory() {}
    
};

gameHistory gh = gameHistory();

game playGame() {
    int winner = (rand() % 2);
    game f = game(winner);
    return f;
}


int main()
{
    // seeding
    srand ( time(NULL) );

  int gamestoget;
  cout << "How many games to record? ";
  cin >> gamestoget;
  cout << "Running " << gamestoget << " Games!\n";
  gamesToBePlayed = gamestoget;
  for (int x = 0; x < gamesToBePlayed; x++) {
      game newGame = playGame();
      gh.addHistory(newGame);
  }
  gh.toString();
  return 0;
   
  
}
