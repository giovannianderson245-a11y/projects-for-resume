/*
Giovanni Anderson
11-1-25
Lab 9
Tic Tac Toe game
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class TicTacToe{
	char board[3][3];
	char currentPlayer;
public:
	TicTacToe();
	void displayBoard();
	void playerMove();
	void computerMove();
	bool checkWin();
	bool isFull();
	void switchPlayer();
	void run();
};

TicTacToe::TicTacToe(){
	for(int i = 0; i<3; i++)
		for(int j = 0; j<3; j++)
			board[i][j] = ' ';
	srand(time(0));
	currentPlayer = (rand() % 2 == 0 ) ?'X':'O';
	cout << "Player" << currentPlayer <<" starts first\n";
}

void TicTacToe::displayBoard(){
	cout << "\n";
	for(int i = 0; i<3; i++){
		for(int j = 0; j<3; j++){
			cout << (board[i][j] == ' ' ? '_' : board[i][j]);
			if(j < 2) cout << " | ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void TicTacToe::playerMove(){
    int row, col;
    while(true){
        cout << "Player " << currentPlayer << "enter your move (row and column: 1-3): ";
        cin >> row >> col;
        row--;
        col--;
        
        if(row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' '){
            board[row][col] = currentPlayer;
            break;
        }
        else{
            cout << "Illegal move. Try again.\n";
        }
    }
}

void TicTacToe::computerMove(){
    cout << "CPU turn...\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' '){
                board[i][j] = currentPlayer;
                return;
            }
        }
    }
}

bool TicTacToe::checkWin(){
    for(int i = 0; i < 3; i++){
        if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return true;
    }
    for(int j = 0; j < 3; j++){
        if(board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return true;
    }
    if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return true;
    if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return true;
    
    return false;
}

bool TicTacToe::isFull(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

void TicTacToe::switchPlayer(){
	currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void TicTacToe::run(){
    while(true){
        displayBoard();
        
        if(currentPlayer == 'X'){
            playerMove();
        }
        else{
            computerMove();
        }
        
        if(checkWin()){
            displayBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if(isFull()){
            displayBoard();
            cout << "It's a tie.\n";
            break;
        }
        
        switchPlayer();
    }
}

int main(){
	TicTacToe game;
	game.run();
	return 0;
}