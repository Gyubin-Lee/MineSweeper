#ifndef C_GRID_C_H
#define C_GRID_C_H

#include "cellChained.h"

cellChain *createGrid(int rowSize, int colSize, int bombs, int bSquares);

int **answerSheet(cellChain *grid, int rowSize, int colSize);

#endif