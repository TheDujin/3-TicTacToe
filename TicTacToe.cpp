#include <iostream>
using namespace std;

/* TicTacToe by Kevin Jin. A command-line based game of TicTacToe between two players.
 * Known minor bugs:
 * Inputting nothing as a move causes the program to loop infinitely.
 * Inputting 9 characters when prompted for a move causes the program to loop infinitely.
 * Inputting more than 1 character when prompted for "y, n, etc." causes ditto.
 * Under some conditions the program will print a board condition twice.
 */

void printBoard(char (*boardPtr)[4]);
char checkWin(int (*gridPtr)[3]);
bool makeMove(int whosTurn, char *inputPtr, int (*gridPtr)[3], char (*boardPtr)[4]);
void clearBoard(int (*gridPtr)[3], char(*boardPtr)[4], char *inputPtr);
const int X_MOVE = -1;
const int O_MOVE = 1;
int main() {
  int xWins = 0;
  int oWins = 0;
  int ties = 0;
  char input[10];
  char *inputPtr = input;
  for (int i = 0; i < 10; i++) {
    input[i] = '\0';
  }
  input[0] = 'x';
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
  bool isPlaying = true;
  while (isPlaying) {
    int whosTurn = X_MOVE;
    while(checkWin(gridPtr) == '0') {
      if (whosTurn == X_MOVE) {
	printBoard(boardPtr);
	cout << "X turn: ";
	cin.get(input, 9);
	cin.get();
	cout << "Checking X";
	if (makeMove(X_MOVE, inputPtr, gridPtr, boardPtr)) {
	  whosTurn = O_MOVE;
	  cout << "Valid" << endl;
	}
	else {
	  cout << "That move isn't valid, please try again!" << endl;
	}
      }
      else {
	printBoard(boardPtr);
	cout << "O turn: ";
	cin.get(input, 9);
	cin.get();
	if (makeMove(O_MOVE, inputPtr, gridPtr, boardPtr)) {
	  whosTurn = X_MOVE;
	  cout << "Valid" << endl;
	}
	else {
	  cout << "That move isn't valid, please try again!" << endl;
	}
      }
    }
    printBoard(boardPtr);
    if (checkWin(gridPtr) == X_MOVE) {
      xWins++;
      cout << "X wins!" << endl << "Total X wins: " << xWins << "   Total O wins: " << oWins << "   Total ties: " << ties << endl; 
    }
    else if (checkWin(gridPtr) == O_MOVE) {
      oWins++;
      cout << "O wins!" << endl << "Total X wins: " << xWins << "   Total O wins: " << oWins << "   Total ties: " << ties << endl;
    }
    else {
      ties++;
      cout << "It's a tie!" << endl << "Total X wins: " << xWins << "   Total O wins: " << oWins << "   Total ties: " << ties << endl;
    }
    cout << "Play again? (y, n, any other characters will be interpreted as \'y\')" << endl;
    char yesNo = 'a';
    cin >> yesNo;
    cin.ignore();
    if (yesNo == 'n') {
      isPlaying = false;
      cout << "Thank you for playing!";
    }
    else {
      cout << "Resetting board..." << endl;
      clearBoard(gridPtr, boardPtr, inputPtr);
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

void clearBoard(int (*gridPtr)[3], char (*boardPtr)[4], char *inputPtr) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      gridPtr[i][j] = 0;
      boardPtr[2 * i + 2][j + 1] = ' ';
    }
  }
  for (int i = 0; i < 10; i++){
    inputPtr[i] = '\0';
  }
}
 
char checkWin(int (*gridPtr)[3]) {
  if (gridPtr[0][0] == X_MOVE && gridPtr[0][1] == X_MOVE && gridPtr[0][2] == X_MOVE) {
    return X_MOVE;
  }

  else if (gridPtr[0][0] == X_MOVE && gridPtr[1][0] == X_MOVE && gridPtr[2][0] == X_MOVE) {
    return X_MOVE;
  }

  else if (gridPtr[1][0] == X_MOVE && gridPtr[1][1] == X_MOVE && gridPtr[1][2] == X_MOVE) {
    return X_MOVE;
  }

  else if (gridPtr[0][1] == X_MOVE && gridPtr[1][1] == X_MOVE && gridPtr[2][1] == X_MOVE) {
    return X_MOVE;
  }

  else if (gridPtr[2][0] == X_MOVE && gridPtr[2][1] == X_MOVE && gridPtr[2][2] == X_MOVE) {
    return X_MOVE;
  }

  else if (gridPtr[0][2] == X_MOVE && gridPtr[1][2] == X_MOVE && gridPtr[2][2] == X_MOVE) {
    return X_MOVE;
  }

  else if (gridPtr[0][0] == X_MOVE && gridPtr[1][1] == X_MOVE && gridPtr[2][2] == X_MOVE) {
    return X_MOVE;
  }

  else if (gridPtr[0][2] == X_MOVE && gridPtr[1][1] == X_MOVE && gridPtr[2][0] == X_MOVE) {
    return X_MOVE;
  }
  
  else if (gridPtr[0][0] == O_MOVE && gridPtr[0][1] == O_MOVE && gridPtr[0][2] == O_MOVE) {
    return O_MOVE;
  }

  else if (gridPtr[0][0] == O_MOVE && gridPtr[1][0] == O_MOVE && gridPtr[2][0] == O_MOVE) {
    return O_MOVE;
  }

  else if (gridPtr[1][0] == O_MOVE && gridPtr[1][1] == O_MOVE && gridPtr[1][2] == O_MOVE) {
    return O_MOVE;
  }

  else if (gridPtr[0][1] == O_MOVE && gridPtr[1][1] == O_MOVE && gridPtr[2][1] == O_MOVE) {
    return O_MOVE;
  }

  else if (gridPtr[2][0] == O_MOVE && gridPtr[2][1] == O_MOVE && gridPtr[2][2] == O_MOVE) {
    return O_MOVE;
  }

  else if (gridPtr[0][2] == O_MOVE && gridPtr[1][2] == O_MOVE && gridPtr[2][2] == O_MOVE) {
    return O_MOVE;
  }

  else if (gridPtr[0][0] == O_MOVE && gridPtr[1][1] == O_MOVE && gridPtr[2][2] == O_MOVE) {
    return O_MOVE;
  }

  else if (gridPtr[0][2] == O_MOVE && gridPtr[1][1] == O_MOVE && gridPtr[2][0] == O_MOVE) {
    return O_MOVE;
  }
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (gridPtr[i][j] == 0) {
	return '0';
      }
    }
  }
  
  return 'T';
}

bool makeMove(int whosTurn, char *inputPtr, int (*gridPtr)[3], char (*boardPtr)[4]) {
  if (inputPtr[2] == '\0') {
    if (inputPtr[0] == 'a' || inputPtr[0] == 'b' || inputPtr[0] == 'c') {
      if (inputPtr[1] == '1' || inputPtr[1] == '2' || inputPtr[1] == '3') {
	int inputChar = (int)inputPtr[0] - 'a';
	int inputNum = (int)inputPtr[1] - '1';
	if (gridPtr[inputChar][inputNum] == 0) {
	  gridPtr[inputChar][inputNum] = whosTurn;
	  if (whosTurn == X_MOVE)
	    boardPtr[inputNum * 2 + 2][inputChar + 1] = 'X';
	  else
	    boardPtr[inputNum * 2 + 2][inputChar + 1] = 'O';
	  for (int i = 0; i < 10; i++) {
	    inputPtr[i] = '\0';
	  }
	  return true;
	}
      }
    }
    for (int i = 0; i < 10; i++) {
      inputPtr[i] = '\0';
    }
  }
  return false;
}
