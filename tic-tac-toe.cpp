#include <iostream>
#include <vector>
using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board;
    int currentPlayer;

public:
    TicTacToe() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        currentPlayer = 1;
    }

    void printBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << endl;
            if (i < 2) cout << "---------" << endl;
        }
    }

    bool isBoardFull() {
        for (auto &row : board)
            for (char cell : row)
                if (cell == ' ') return false;
        return true;
    }

    bool makeMove(int row, int column) {
        if (row < 0 || row >= 3 || column < 0 || column >= 3 || board[row][column] != ' ') {
            cout << "Invalid move! Try again.\n";
            return false;
        }
        board[row][column] = (currentPlayer == 1) ? 'X' : 'O';
        currentPlayer = 3 - currentPlayer;  // switch player
        return true;
    }

    bool checkWinner() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return true;
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return true;
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return true;
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return true;
        return false;
    }

    int getCurrentPlayer() { return currentPlayer; }
};

int main() {
    TicTacToe game;
    int row, col;

    cout << "Welcome to Tic Tac Toe!\n";
    game.printBoard();

    while (!game.checkWinner() && !game.isBoardFull()) {
        cout << "Player " << game.getCurrentPlayer() << "'s turn.\n";
        cout << "Enter row (0-2) and column (0-2): ";
        cin >> row >> col;

        if (game.makeMove(row, col)) {
            game.printBoard();
        }
    }

    if (game.checkWinner()) {
        cout << "Player " << (3 - game.getCurrentPlayer()) << " wins!\n";
    } else {
        cout << "It's a draw!\n";
    }

    return 0;
}
