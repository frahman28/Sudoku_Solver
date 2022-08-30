#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include "Solver.h"


using namespace std;

bool solved = 0;

int grid[9][9] = {
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int displayGrid[9][9] = {
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int randomValue(int min, int max) {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(min, max);

    return distr(eng);
}
bool isPresentInCol(int col, int num) {
    for (int row = 0; row < 9; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}
bool isPresentInRow(int row, int num) { 
    for (int col = 0; col < 9; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}
bool isPresentInBox(int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}
bool findEmptyPlace(int& row, int& col) { 
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (grid[row][col] == 0) 
                return true;
    return false;
}
bool isValidPlace(int row, int col, int num) {
    return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row % 3,
        col - col % 3, num);
}
bool solveSudoku() {
    int row, col;
    if (!findEmptyPlace(row, col))
        return true; 
    for (int num = 1; num <= 9; num++) {
        if (isValidPlace(row, col, num)) { 
            grid[row][col] = num;
            if (solveSudoku())
                return true;
            grid[row][col] = 0; 
        }
    }
    return false;
}

void resetGrids() {
    solved = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = 0;
            displayGrid[i][j] = 0;
        }
    }
}

void generateGrid() {
    int coordinates[9][9][2]{
       {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}}, {{0, 3}, {0, 4}, {0, 5}, {1, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 4}, {2, 5}}, {{0, 6}, {0, 7}, {0, 8}, {1, 6}, {1, 7}, {1, 8}, {2, 6}, {2, 7}, {2, 8}},
       {{3, 0}, {3, 1}, {3, 2}, {4, 0}, {4, 1}, {4, 2}, {5, 0}, {5, 1}, {5, 2}}, {{3, 3}, {3, 4}, {3, 5}, {4, 3}, {4, 4}, {4, 5}, {5, 3}, {5, 4}, {5, 5}}, {{3, 6}, {3, 7}, {3, 8}, {4, 6}, {4, 7}, {4, 8}, {5, 6}, {5, 7}, {5, 8}},
       {{6, 0}, {6, 1}, {6, 2}, {7, 0}, {7, 1}, {7, 2}, {8, 0}, {8, 1}, {8, 2}}, {{6, 3}, {6, 4}, {6, 5}, {7, 3}, {7, 4}, {7, 5}, {8, 3}, {8, 4}, {8, 5}}, {{6, 6}, {6, 7}, {6, 8}, {7, 6}, {7, 7}, {7, 8}, {8, 6}, {8, 7}, {8, 8}}
    };

    for (int q = 0; q < 9; q++) {

        int n = randomValue(1, 5);

        vector<vector<int>> tempSet;

        for (int i = 0; i < n; i++) {
            int randomIndex = randomValue(0, 8);
            vector<int> v = { coordinates[q][randomIndex][0], coordinates[q][randomIndex][1] };

            while (std::find(tempSet.begin(), tempSet.end(), v) != tempSet.end()) {
                int randomIndex = randomValue(0, 8);
                v = { coordinates[q][randomIndex][0], coordinates[q][randomIndex][1] };
            }

            tempSet.push_back(v);

        }

        for (int j = 0; j < n; j++) {
            int randomNumber = randomValue(1, 9);
            while (!isValidPlace(tempSet[j][0], tempSet[j][1], randomNumber)) {
                randomNumber = randomValue(1, 9);
            }
            grid[tempSet[j][0]][tempSet[j][1]] = randomNumber;
        }

    }
}

void loop() {
    resetGrids();
    generateGrid();
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            displayGrid[i][j] = grid[i][j];
        }
    }
    if (solveSudoku() == true) {
        solved = 1;
    }
    else {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                grid[i][j] = 0;
                displayGrid[i][j] = 0;
            }
        }
        cout << "No solution exists";
    }
}

void assessValidGraph() {
    while (solved == 0) {
        loop();
    }
}

void copyInputGrid(int inputGrid[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            grid[i][j] = inputGrid[i][j];
            displayGrid[i][j] = inputGrid[i][j];
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            displayGrid[i][j] = grid[i][j];
        }
    }
    if (solveSudoku() == true) {
        solved = 1;
    }
    else {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                grid[i][j] = 0;
                displayGrid[i][j] = 0;
            }
        }
        cout << "No solution exists";
    }
}

