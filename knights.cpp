#include <iostream>
#include <unistd.h>

void printboard(std::string board[][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] != "." && std::stoi(board[i][j]) > 9) {
                std::cout << " " << board[i][j] << " |";
            }
            else {
                std::cout << " " << board[i][j] << " |";
            }
        }
        std::cout << '\n';
    }
}


void knightsTours(std::string board[][5], int row, int col, int count, bool &solved) {
    if (count > 25) {
        solved = true;
        printboard(board);
        return;
    }

    // check if it's out of bound or already visted
    if (row >= 5 || row < 0 || col >= 5 || col < 0 || board[row][col] != ".") {
        return;
    }

    if (!solved) {
        board[row][col] = std::to_string(count);
    }



    if (!solved) {
        knightsTours(board, row-2, col-1, count+1, solved);
    }
    if (!solved) {
        knightsTours(board, row-2, col+1, count+1, solved);
    }
    if (!solved) {
        knightsTours(board, row-1, col-2, count+1, solved);
    }
    if (!solved) {
        knightsTours(board, row-1, col+2, count+1, solved);
    }
    if (!solved) {
        knightsTours(board, row+1, col-2, count+1, solved);
    }
    if (!solved) {
        knightsTours(board, row+1, col+2, count+1, solved);
    }
    if (!solved) {
        knightsTours(board, row+2, col-1, count+1, solved);
    }
    if (!solved) {
        knightsTours(board, row+2, col+1, count+1, solved);
    }


    if (!solved) {
        board[row][col] = ".";
        return;
    }
}


int main() {
    bool solved = false;
    std::string board[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = ".";
        }
    }

    knightsTours(board, 0, 0, 1, solved);
    
    return 0;
}