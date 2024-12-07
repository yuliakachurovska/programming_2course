#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class TicTacToe {
private:
    char currentPlayer;

    void drawLine() const {
        cout << "  ";
        for (int i = 0; i < 3; ++i) {
            if (i > 0) cout << "|";
            cout << "---";
        }
        cout << "\n";
    }

public:
    vector<vector<char>> board;
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

    void drawBoard() const {
        for (int row = 0; row < 3; ++row) {
            drawLine();
            cout << row + 1 << " ";
            for (int col = 0; col < 3; ++col) {
                if (col > 0) cout << "|";
                cout << " " << board[row][col] << " ";
            }
            cout << "\n";
        }
        drawLine();
        cout << "   1   2   3\n"; // Номери стовпців
    }

    bool gameRunning = true;

    void makeMove() {
        int row, col;
        while (true) {
            cout << "Player " << currentPlayer << ", enter row and column (or type 'exit' to quit): ";
            
            string input;
            cin >> input;

            if (input == "exit") {
                cout << "Player " << currentPlayer << " has quit the game.\n";
                gameRunning = false;
                return;
            }

            // Перетворення вводу на числа, бо ми зчитуємо як число так і exit
            try {
                row = stoi(input);
                cin >> col;
            } catch (const invalid_argument& e) {
                cout << "Invalid input! Please enter numbers between 1 and 3.\n";
                continue;
            }

            if (row < 1 || row > 3 || col < 1 || col > 3) {
                cout << "Invalid input! Please enter numbers between 1 and 3.\n";
                continue;
            }

            // Перевірка чи поле зайняте
            if (board[row - 1][col - 1] != ' ') {
                cout << "Cell is already taken! Choose another one.\n";
                continue;
            }
            board[row - 1][col - 1] = currentPlayer;
            break;
        }
    }

    bool isGameOver() const {
        for (int i = 0; i < 3; ++i) {
            // Рядки
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            // Стовпці
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        // Діагоналі
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;

        // Перевірка чи є доступні клітинки
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') return false;
            }
        }

        return false; // Якщо нічия
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getWinner() const {
        return isGameOver() ? currentPlayer : ' ';
    }

    void play() {
        while (gameRunning) {
            drawBoard();
            makeMove();

            if (isGameOver()) {
                drawBoard();
                if (getWinner() != ' ') {
                    cout << "Player " << currentPlayer << " wins!\n";
                } else {
                    cout << "It's a draw!\n";
                }
                break;
            }
            switchPlayer();
        }
    }

};

int main() {
    TicTacToe game;

    // cout << "If you want to quit the game, type 'exit' anytime during your turn.\n";
    // game.play();

    game.board[0][2] = 'X';
    game.board[0][1] = 'O';
    game.board[1][1] = 'X';
    game.board[2][0] = 'O';
    game.board[2][2] = 'X';
    game.board[0][0] = 'X';
    game.drawBoard();

    if (game.isGameOver()) {
        char winner = game.getWinner();
        if (winner != ' ') {
            cout << "Player " << winner << " wins!\n";
        } else {
            cout << "It's a draw!\n";
        }
    } else {
        cout << "Game is still continuous.\n";
    }
}

