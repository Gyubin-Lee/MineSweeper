#ifndef RENDER_C_H
#define RENDER_C_H

#include "cell.h"

void render(Cell ***grid, int rowSize, int colSize, int currBombs, int currHints);

void renderBomb(Cell ***grid, int rowSize, int colSize);

void renderAdj(Cell ***grid, int rowSize, int colSize);

#endif