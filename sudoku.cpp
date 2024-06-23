#include <iostream>
#include <vector>

using namespace std;

// Define the size of the Sudoku grid
const int SIZE = 9;

// Function prototypes
bool solveSudoku(vector<vector<int>>& grid);
bool isValid(vector<vector<int>>& grid, int row, int col, int num);
void printGrid(const vector<vector<int>>& grid);
bool findEmptyCell(vector<vector<int>>& grid, int& row, int& col);

int main() {
    // Define an unsolved Sudoku puzzle
    vector<vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid)) {
        cout << "Sudoku puzzle solved successfully:" << endl;
        printGrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }

    return 0;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(vector<vector<int>>& grid) {
    int row, col;
    if (!findEmptyCell(grid, row, col)) {
        return true; // No empty cell means the puzzle is solved
    }

    for (int num = 1; num <= 9; ++num) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num; // Tentatively assign num to the empty cell

            if (solveSudoku(grid)) {
                return true;
            }

            grid[row][col] = 0; // Reset the cell on backtrack
        }
    }

    return false; // Trigger backtracking
}

// Function to check if placing num in grid[row][col] is valid
bool isValid(vector<vector<int>>& grid, int row, int col, int num) {
    // Check row
    for (int i = 0; i < SIZE; ++i) {
        if (grid[row][i] == num) {
            return false;
        }
    }

    // Check column
    for (int i = 0; i < SIZE; ++i) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    // Check 3x3 sub-grid
    int startRow = row / 3 * 3;
    int startCol = col / 3 * 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to print the Sudoku grid
void printGrid(const vector<vector<int>>& grid) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to find an empty cell in the grid
bool findEmptyCell(vector<vector<int>>& grid, int& row, int& col) {
    for (row = 0; row < SIZE; ++row) {
        for (col = 0; col < SIZE; ++col) {
            if (grid[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}
