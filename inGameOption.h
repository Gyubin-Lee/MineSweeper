#ifndef IGO_H
#define IGO_H

#include "queue.h"
#include "cell.h"

int mark(Cell **grid, int row, int col);

int hint(Cell **grid, int row, int col, int rowSize, int colSize);

int open(Cell **grid, int row, int col, int rowSize, int colSize);

int judge(Cell **grid, int rowSize, int colSize);

#endif