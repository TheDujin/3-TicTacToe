#include <iostream>

using namespace std;

void printBoard(char (*boardPtr)[4]);
char checkWin(int (*gridPtr)[3]);
const int X_MOVE = 0;
const int O_MOVE = 1;
int main() {
  int grid[3][3];
  int (*gridPtr)[3] = grid;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      grid[i][j] = 0;
    }
  }
  char board[7][4];
  char (*boardPtr)[4] = board;
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 4; j++) {
      board[i][j] = ' ';
    }
  }
  board[2][0] = '1';
  board[4][0] = '2';
  board[6][0] = '3';
  board[0][1] = 'a';
  board[0][2] = 'b';
  board[0][3] = 'c';
  cout << "This is a simple text-based Tic Tac Toe program for command line!" << endl;
  cout << "Please specify your moves using a letter-number system (e.g. b2)." << endl;
  cout << "This program is intended for two players." << endl;
  printBoard(boardPtr);
  bool isPlaying = true;
  while (isPlaying) {
    int whosTurn = X_MOVE;
    while(checkWin(gridPtr) != '0') {
      if (whosTurn == X_MOVE) {
	
      }
      else {

      }
    }
  }
  
  
  
  
  
}


/*   1 2 3
 * a X X O
 * b O X X
 * c O O X
 * 
 */

void printBoard(char (*boardPtr)[4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 7; j++) {
      cout << boardPtr[j][i];
    }
    cout << endl;
  }
}

char checkWin(int (*gridPtr)[3]) {
  return '0';
}
