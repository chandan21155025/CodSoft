#include <iostream>
using namespace std;

void displayBoard(char board[3][3]) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "| " << board[i][j] << " ";
        }
        cout << "|" << endl;
        cout << "-------------" << endl;
    }
}

bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X';
    bool gameWon = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    do {
        
        displayBoard(board);
        int row, col;
        do {
            cout << "Player " << currentPlayer << ", enter your move (row [1-3] and column [1-3]): ";
            cin >> row >> col;

            row--;
            col--;

            if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
                break;
            else
                cout << "Invalid move. Try again." << endl;
        } while (true);

        board[row][col] = currentPlayer;
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Congratulations! Player " << currentPlayer << " wins!" << endl;
            gameWon = true;
        }
       
        else if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    } while (!gameWon);

    cout << "Thank you for playing Tic-Tac-Toe!" << endl;

    return 0;
}

