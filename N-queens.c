
#include <stdio.h>                        //ujjawal roy
#include <stdlib.h>                       //25/DA/061

#define MAX 20

int board[MAX];
int N;

// Check whether a queen can be placed at (row, col)
int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // Same column or same diagonal
        if (board[i] == col ||
            abs(board[i] - col) == abs(i - row)) {
            return 0;
        }
    }
    return 1;
}

// Solve N-Queens using backtracking
int solveNQueens(int row) {
    if (row == N) {
        return 1;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;

            if (solveNQueens(row + 1)) {
                return 1;
            }

            // Backtrack
            board[row] = -1;
        }
    }

    return 0;
}

// Print the chessboard
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the value of N: ");
    scanf("%d", &N);

    if (N < 1 || N > MAX) {
        printf("Invalid value of N!\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        board[i] = -1;
    }

    if (solveNQueens(0)) {
        printf("Solution to %d-Queens problem:\n", N);
        printBoard();
    } else {
        printf("No solution exists for N = %d\n", N);
    }

    return 0;
}
