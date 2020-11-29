#ifndef RENDER_H
#define RENDER_H

#include "cell.h"

void render(Cell **grid, int rowSize, int colSize, int currBombs, int currHints);

void renderDebug(Cell **grid, int rowSize, int colSize);

void renderBomb(Cell **grid, int rowSize, int colSize);

#endif