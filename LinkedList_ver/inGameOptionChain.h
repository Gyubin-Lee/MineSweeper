#ifndef IGO_C_H
#define IGO_C_H

#include "cellChained.h"

int mark(cellChain *grid, int row, int col);

int hint(cellChain *grid, int row, int col, int rowSize, int colSize);

int open(cellChain *grid, int row, int col, int rowSize, int colSize);

int judge(cellChain *grid, int rowSize, int colSize, int currMarks, int bombs);

#endif