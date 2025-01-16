#include <iostream>
#define N 9
using namespace std;
void printGrid(int grid[N][N]) {
    cout << "\nSolved Sudoku Grid:\n";
    cout << "=========================\n";
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
            if ((col + 1) % 3 == 0 && col != N - 1)
                cout << "| "; 
        }
        cout << endl;
        if ((row + 1) % 3 == 0 && row != N - 1)
            cout << "-------------------------\n"; 
    }
    cout << "=========================\n";
}
bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num)
            return false;
    }
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num)
            return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool isEmpty = false;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty)
            break;
    }

    if (!isEmpty)
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }

    return false; 
}

int main() {
    int grid[N][N];
    char playAgain = 'y';  
    cout << "=======================================\n";
    cout << "           Sudoku Solver \n";
    cout << "=======================================\n";
    cout << "Instructions:\n";
    cout << "1. Enter the Sudoku puzzle row by row.\n";
    cout << "2. Use 0 for empty cells.\n";
    cout << "=======================================\n";
    while (playAgain == 'y' || playAgain == 'Y') {
        cout << "Enter your Sudoku puzzle:\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> grid[i][j];
            }
        }

        cout << "\nProcessing your Sudoku puzzle...\n";

        if (solveSudoku(grid)) {
            printGrid(grid);
            cout << "\nSudoku solved successfully!\n";
        } else {
            cout << "\nNo solution exists for the given Sudoku puzzle.\n";
        }
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y' && playAgain != 'n' && playAgain != 'N') {
            cout << "Invalid input. Exiting...\n";
            break;
        }

    }

    cout << "=======================================\n";
    cout << "          Program Terminated \n";
    cout << "=======================================\n";

    return 0;
}
