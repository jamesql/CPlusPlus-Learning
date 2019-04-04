#include <iostream>
#include <fstream>
#include "list"

using namespace std;

struct writeHistory {
public:
  string prnt;

  writeHistory(string printer) :
  prnt(printer) {}
};

ofstream File;
string fileName = "filetowriteto";
std::list<writeHistory> history;

int main() {
  string userInput;
  bool cont = true;
  File.open(fileName);
    if (File.is_open()) {
      cout << "File Opened!" << endl;
      while (cont) {
      cout << "Write to file : " << endl;
      cin >> userInput;
      history.push_back(writeHistory(userInput));
      File << userInput << "\n";
      cout << "Write another line? (y/n) : ";
      cin >> userInput;
      if (userInput.compare("n") == 0) cont = !cont;
      }
    } else cout << "Error : Cant Find File!" << endl;
    File.close();
    cout << "Output :" << endl;
    for (writeHistory x : history)
        cout << x.prnt << endl;
    cout << "End of output." << endl;
  return 0;
}
