#ifndef CELL_H
#define CELL_H

class Cell
{
public:
    int row, col;
    int cellType; //0: normal, 1: bomb, 2: block
    int isOpened;
    int isMarked;
    int adjacentBombs;

    Cell() {}

    Cell(int row_, int col_, int cellType_)
    {
        row = row_;
        col = col_;
        cellType = cellType_;
        isOpened = 0;
        isMarked = 0;
        adjacentBombs = 0;
    }
};

#endif