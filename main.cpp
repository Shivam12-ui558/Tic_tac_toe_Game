#include <iostream>
using namespace std;

// Let's create a 3x3 board for the game
char board[3][3];

// The current player: 'X' starts first
char currentPlayer = 'X';

// This function sets up an empty board
void initializeBoard() {
    for (int i = 0; i < 3; ++i) {           // Loop through rows
        for (int j = 0; j < 3; ++j) {       // Loop through columns
            board[i][j] = ' ';              // Set each cell as empty
        }
    }
}

// This function shows the current state of the board
void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];            // Print each cell
            if (j < 2) cout << " | ";       // Add vertical separator
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n"; // Add horizontal separator
    }
    cout << "\n";
}

// This function handles a player’s move
bool makeMove(int row, int col) {
    // Check if the position is valid and empty
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = currentPlayer;   // Place the current player's mark
        return true;
    }
    return false; // Invalid move
}

// This checks if the current player has won
bool checkWin() {
    // Check each row
    for (int i = 0; i < 3; ++i)
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;

    // Check each column
    for (int j = 0; j < 3; ++j)
        if (board[0][j] == currentPlayer &&
            board[1][j] == currentPlayer &&
            board[2][j] == currentPlayer)
            return true;

    // Check both diagonals
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}

// This checks if the board is full (draw)
bool checkDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false; // Still empty spots
    return true; // All filled = draw
}

// This switches the player after each turn
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// The main game loop
int main() {
    int row, col;

    initializeBoard(); // Start with empty board

    while (true) {
        displayBoard(); // Show board each turn

        // Ask the current player to make a move
        cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
        cin >> row >> col;

        // If the move is invalid, retry
        if (!makeMove(row, col)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        // Check for a win
        if (checkWin()) {
            displayBoard();
            cout << " Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check for draw
        if (checkDraw()) {
            displayBoard();
            cout << " It's a draw!\n";
            break;
        }

        // Switch to the other player
        switchPlayer();
    }

    return 0;
}
