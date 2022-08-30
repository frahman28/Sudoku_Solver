#ifndef SOLVER_H
#define SOLVER_H

extern bool solved;
extern int grid[9][9];
extern int displayGrid[9][9];
int randomValue(int min, int max);
bool isPresentInCol(int col, int num);
bool isPresentInRow(int row, int num);
bool isPresentInBox(int boxStartRow, int boxStartCol, int num);
bool findEmptyPlace(int& row, int& col);
bool isValidPlace(int row, int col, int num);
bool solveSudoku();
void generateGrid();
void loop();
void resetGrids();
void copyInputGrid(int grid[][9]);

void assessValidGraph();

#endif