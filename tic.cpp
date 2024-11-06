/*TIC-TAC-TOE GAME
 Build a simple console-based Tic-Tac-Toe game that
 allows two players to play against each other
 Game Board: Create a 3x3 grid as the game board.
 Players: Assign "X" and "O" to two players.
 Display Board: Show the current state of the board.
 Player Input: Prompt the current player to enter their move.
 Update Board: Update the game board with the player's move.
 Check for Win: Check if the current player has won.
 Check for Draw: Determine if the game is a draw.
 Switch Players: Alternate turns between "X" and "O" players.
 Display Result: Show the result of the game (win, draw, or ongoing).
 Play Again: Ask if the players want to play another game */
 
#include<iostream>
#include <cstring>

using namespace std;

char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row, col;
string s1, s2;
int digit;
bool tie = false;
char symbol = 'X';
int choice;

void info();
void table();
void move();
bool check();
void reset();

int main() {
    info();
    do {
        while (!check()) {
            table();
            move();
        }

        table(); 

        if (symbol == 'O' && tie == false) {
            cout << s1 << " Wins!!!" << endl;
        } else if (symbol == 'X' && tie == false) {
            cout << s2 << " Wins!!!" << endl;
        } else {
            cout << "It's a draw!" << endl;
        }

        cout << "Do you want to play again? If yes, enter 1. If no, enter 0: ";
        cin >> choice;

        if (choice) {
            reset();
        }

    } while (choice);

    return 0;
}

void info() {
    cout << "Enter the Name of First player: ";
    getline(cin, s1);

    cout << "Enter the Name of Second Player: ";
    getline(cin, s2);

    cout << s1 << " is player 1, player1 will play first\n";
    cout << s2 << " is player 2, player2 will play second\n";
}

void table() {
    cout << "       |       |       \n";
    cout << "   " << space[0][0] << "   |   " << space[0][1] << "   |   " << space[0][2] << "   \n";
    cout << "_______|_______|_______\n";
    cout << "       |       |       \n";
    cout << "   " << space[1][0] << "   |   " << space[1][1] << "   |   " << space[1][2] << "   \n";
    cout << "_______|_______|_______\n";
    cout << "       |       |       \n";
    cout << "   " << space[2][0] << "   |   " << space[2][1] << "   |   " << space[2][2] << "   \n";
    cout << "       |       |       \n";
}

void move() {
    if (symbol == 'X') {
        cout << s1 << ", please enter your move: ";
    } else {
        cout << s2 << ", please enter your move: ";
    }
    cin >> digit;

    switch (digit) {
        case 1: row = 0; col = 0; break;
        case 2: row = 0; col = 1; break;
        case 3: row = 0; col = 2; break;
        case 4: row = 1; col = 0; break;
        case 5: row = 1; col = 1; break;
        case 6: row = 1; col = 2; break;
        case 7: row = 2; col = 0; break;
        case 8: row = 2; col = 1; break;
        case 9: row = 2; col = 2; break;
        default: cout << "Invalid Input"; move(); return;
    }

    if (space[row][col] != 'X' && space[row][col] != 'O') {
        space[row][col] = symbol;
        symbol = (symbol == 'X') ? 'O' : 'X';
    } else {
        cout << "There is no empty space, try again.\n";
        move();
    }
}

bool check() {
    for (int i = 0; i < 3; i++) {
        if ((space[i][0] == space[i][1] && space[i][0] == space[i][2]) || 
            (space[0][i] == space[1][i] && space[0][i] == space[2][i])) {
            return true;
        }
    }
    if ((space[0][0] == space[1][1] && space[0][0] == space[2][2]) || 
        (space[0][2] == space[1][1] && space[0][2] == space[2][0])) {
        return true;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'X' && space[i][j] != 'O') {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

void reset() {
    char new_space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    memcpy(space, new_space, sizeof(space));
    tie = false;
    symbol = 'X';
}