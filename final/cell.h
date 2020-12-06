#ifndef CELL_H
#define CELL_H

class Cell
{
public:
    int row, col;
    int cellType; //0: empty, 1: bomb, 2: block
    int isOpened;
    int isMarked;
    int adjacentBombs;
    Cell *leftTop;
    Cell *top;
    Cell *rightTop;
    Cell *left;
    Cell *right;
    Cell *leftBottom;
    Cell *bottom;
    Cell *rightBottom;

    Cell() {}

    Cell(int row_, int col_, int cellType_)
    {
        row = row_;
        col = col_;
        cellType = cellType_;
        isOpened = 0;
        isMarked = 0;
        adjacentBombs = 0;
        leftTop = 0;
        top = 0;
        rightTop = 0;
        left = 0;
        right = 0;
        leftBottom = 0;
        bottom = 0;
        rightBottom = 0;
    }
};

#endif