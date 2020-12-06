#ifndef RENDER_C_H
#define RENDER_C_H

#include "cellChained.h"

void render(cellChain *grid, int rowSize, int colSize, int currBombs, int currHints);

void renderBomb(cellChain *grid, int rowSize, int colSize);

#endif