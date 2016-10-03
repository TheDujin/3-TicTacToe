#include <iostream>
using namespace std;

/* TicTacToe by Kevin Jin. A command-line based game of TicTacToe between two players.
 * Known minor bugs:
 * Inputting nothing as a move causes the program to loop infinitely.
 * Inputting 9 characters (or a multiple of 9) when prompted for a move causes the program to loop infinitely.
 * Inputting more than 1 character when prompted for "y, n, etc." causes ditto.
 * Under some conditions the program will print a board condition twice.
 */

//Functions and constants are defined.
void printBoard(char (*boardPtr)[4]);
char checkWin(int (*gridPtr)[3]);
bool makeMove(int whosTurn, char *inputPtr, int (*gridPtr)[3], char (*boardPtr)[4]);
void clearBoard(int (*gridPtr)[3], char(*boardPtr)[4], char *inputPtr);
const int X_MOVE = -1;
const int O_MOVE = 1;
//Main method. This is where the game initially starts.
int main() {
  //Initialize win counters to 0 and initialize important arrays:
  int xWins = 0;
  int oWins = 0;
  int ties = 0;
  //Holds the input. Initialized to contain null characters (to prevent infinite loops).
  char input[10];
  char *inputPtr = input;
  for (int i = 0; i < 10; i++) {
    input[i] = '\0';
  }
  //Grid holds the values of the tic tac toe grid: X is -1, blank is 0, and O is 1. Initialized to all 0's
  int grid[3][3];
  int (*gridPtr)[3] = grid;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      grid[i][j] = 0;
    }
  }
  //Board holds the appearance of the grid as the be outputted. Intialized to look like the board.
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
  //Outputs "welcome message".
  cout << "This is a simple text-based Tic Tac Toe program for command line!" << endl;
  cout << "Please specify your moves using a letter-number system (e.g. b2)." << endl;
  cout << "This program is intended for two players." << endl;
  //Initializes the isPlaying variable. Later it will determine whether the players want to play again. 
  bool isPlaying = true;
  while (isPlaying) {
    //It is currently X's turn.
    int whosTurn = X_MOVE;
    //While no one has won:
    while(checkWin(gridPtr) == '0') {
      //If it is X's turn, take in X's input and input it into the board if valid; otherwise prompt the user again.
      if (whosTurn == X_MOVE) {
	printBoard(boardPtr);
	cout << "X turn: ";
	/* 9 characters are read in to get rid of an error that previously would cause the program to crash
	 * when given 3 characters as input.
	 */
	 cin.get(input, 9);
	cin.get();
	//If the move is valid, it is now O's turn.
	if (makeMove(X_MOVE, inputPtr, gridPtr, boardPtr)) {
	  whosTurn = O_MOVE;
	}
	//Else, prompt the user again.
	else {
	  cout << "That move isn't valid, please try again!" << endl;
	}
      }
      //Otherwise, it is O's turn. The algorithm remains the same.
      else {
	printBoard(boardPtr);
	cout << "O turn: ";
	cin.get(input, 9);
	cin.get();
	if (makeMove(O_MOVE, inputPtr, gridPtr, boardPtr)) {
	  whosTurn = X_MOVE;
	}
	else {
	  cout << "That move isn't valid, please try again!" << endl;
	}
      }
    }
    //Once someone is won, the innermost loop is exited. Print the board again.
    printBoard(boardPtr);
    //Depending on who has won, increment a certain variable and print a certain message.
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
    //Ask if the users want to play again. "n" ends the game, any other characters continue it.
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
      //Clear the board for the next round.
      clearBoard(gridPtr, boardPtr, inputPtr);
    }
  }
  
  
  
  
  
}


/* A possible board layout:
 *   1 2 3
 * a X X O
 * b O X X
 * c O O X
 * 
 */

//Prints the board by iterating through the board array.
void printBoard(char (*boardPtr)[4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 7; j++) {
      cout << boardPtr[j][i];
    }
    cout << endl;
  }
}

//Clears the board by resetting grid, board, and input arrays to how they were at the beginning of the program.
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

//CheckWin is overly complicated, but it works!!! It checks all possible win conditions and if someone wins, output who won.
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
  //If the board isn't full, output '0'.
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (gridPtr[i][j] == 0) {
	return '0';
      }
    }
  }
  //If all grid squares are full but no one has won, output 'T' for tie.
  return 'T';
}
//makeMove checks that the move is valid, makes the move, then updates board array to reflect the move.
bool makeMove(int whosTurn, char *inputPtr, int (*gridPtr)[3], char (*boardPtr)[4]) {
  //If the third value in the array is a null character, i.e. the input is less than 3 characters in length:
  if (inputPtr[2] == '\0') {
    //If the first character in the input is an 'a', 'b', or 'c':
    if (inputPtr[0] == 'a' || inputPtr[0] == 'b' || inputPtr[0] == 'c') {
      //If the next character in the input is a '1', '2', or '3':
      if (inputPtr[1] == '1' || inputPtr[1] == '2' || inputPtr[1] == '3') {
	//Determine what indices of the grid array the input corresponds to.
	int inputChar = (int)inputPtr[0] - 'a';
	int inputNum = (int)inputPtr[1] - '1';
	//If the grid array is empty at those indices, make the move.
	if (gridPtr[inputChar][inputNum] == 0) {
	  gridPtr[inputChar][inputNum] = whosTurn;
	  //If it is X's turn, update board to contain an X at the appropriate spot. Otherwise, include an O.
	  if (whosTurn == X_MOVE)
	    boardPtr[inputNum * 2 + 2][inputChar + 1] = 'X';
	  else
	    boardPtr[inputNum * 2 + 2][inputChar + 1] = 'O';
	  //Reset the input array.
	  for (int i = 0; i < 10; i++) {
	    inputPtr[i] = '\0';
	  }
	  //The move was made, so return true.
	  return true;
	}
      }
    }
    //If the input was invalid, reset the input array anyways.
    for (int i = 0; i < 10; i++) {
      inputPtr[i] = '\0';
    }
  }
  //Since no move was made, return false.
  return false;
}
