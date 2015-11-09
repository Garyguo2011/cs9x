#include "board.h"

Board::Board(int n) : size(n), board(n, vector<char>(n,'.')) {
}

void Board::SetCell(int player, int row, int col, char c) {
  if (row < 0 || row >= size ||
      col < 0 || col >= size ||
      player < 0 || player > 1){
    return;    
  }
  if (player == 1) {
      row = size - row - 1;
      col = size - col - 1;
  }
  board[row][col] = c;
}

void Board::Print(int player){

  // cout << board[0][0];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (player == 1) {
        int tempI = size - i - 1;
        int tempJ = size - j - 1;
        cout << " " << board[tempI][tempJ] << " ";
      } else {
        cout << " " << board[i][j] << " ";
      }
    }
    cout << endl;
  }
  cout << endl;
}

int main(int argc, char const *argv[])
{
  // cout << "Hello world";
  Board* board;

  cout << "Sample test: " << endl;
  board = new Board(3);
  board->SetCell(0, 0, 0, 'x');
  board->SetCell(0, 0, 1, 'o');
  board->SetCell(0, 0, 2, 'x');
  board->SetCell(0, 1, 0, 'o');
  board->SetCell(0, 1, 1, 'x');
  board->SetCell(0, 1, 2, '.');
  board->SetCell(0, 2, 0, 'o');
  board->SetCell(0, 2, 1, 'x');
  board->SetCell(0, 2, 2, 'o');
  board->Print(0);
  board->Print(1);
  cout << "changing board cell [0][2] to 'M' from player 0's perspective would result in the board: " << endl;
  board->SetCell(0, 0, 2, 'M');
  board->Print(0);
  cout << "while changing board cell [0][2] to 'M' from player 1's perspective would result in the board" << endl;
  board->Print(1);

  cout << "test with size 5" << endl;
  board = new Board(5);
  board->SetCell(1, 0, 0, 'c');
  board->SetCell(0, 0, 4, 'x');
  board->SetCell(1, 3, 2, 'l');
  board->SetCell(0, 0, 0, 'p');
  board->Print(0);
  board->Print(1);

  board = new Board(5);
  board->SetCell(0, 0, 0, 'x');
  board->SetCell(0, 1, 1, 'y');
  board->SetCell(1, 0, 0, 'g');
  board->SetCell(1, 0, 0, 'x');
  board->SetCell(0, 0, 0, 'f');
  board->SetCell(0, 3, 3, 'p');
  board->SetCell(0, 3, 0, 't');
  board->SetCell(1, 0, 3, 'l');
  board->Print(0);
  board->Print(1);

  cout << "test with size 19" << endl;
  board = new Board(19);
  board->SetCell(1, 0, 0, 'c');
  board->SetCell(0, 0, 4, 'x');
  board->SetCell(1, 3, 2, 'l');
  board->SetCell(0, 0, 0, 'p');
  board->Print(0);
  board->Print(1);
  
  board = new Board(19);
  board->SetCell(0, 0, 0, 'x');
  board->SetCell(0, 1, 1, 'y');
  board->SetCell(1, 0, 0, 'g');
  board->SetCell(1, 0, 0, 'x');
  board->SetCell(0, 0, 0, 'f');
  board->SetCell(0, 3, 3, 'p');
  board->SetCell(0, 3, 0, 't');
  board->SetCell(1, 0, 3, 'l');
  board->Print(0);
  board->Print(1);

  return 0;
}