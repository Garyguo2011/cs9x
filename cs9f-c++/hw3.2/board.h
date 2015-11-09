#include <iostream>
#include <vector>
using namespace std;
class Board {
  public:
    Board(int n);
    void SetCell(int player, int row, int col, char c);
    void Print(int player);

  private:
    int size;
    vector< vector<char> > board;
};
