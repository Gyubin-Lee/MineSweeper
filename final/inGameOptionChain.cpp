#include "inGameOptionChain.h"
#include <queue>

int mark(Cell ***grid, int row, int col)
{
    Cell *temp = grid[row - 1][col - 1];
    if (temp->isMarked == 0)
    {
        temp->isMarked = 1;
        return 1;
    }
    else
    {
        temp->isMarked = 0;
        return -1;
    }
}

int open(Cell ***grid, int row, int col, int rowSize, int colSize)
{
    Cell *temp = grid[row - 1][col - 1];
    if (temp->cellType == 1)
    { //bomb
        return -1;
    }
    else if (temp->cellType == 2)
    { //block
        return 0;
    }
    else
    { //normal
        std::queue<Cell *> cellQueue;

        cellQueue.push(grid[row - 1][col - 1]);

        while (!cellQueue.empty())
        {
            Cell *temp = cellQueue.front();
            cellQueue.pop();

            temp->isOpened = 1;

            if (temp->adjacentBombs == 0)
            {
                if (temp->leftTop && temp->leftTop->cellType == 0 && temp->leftTop->isOpened == 0)
                    cellQueue.push(temp->leftTop);
                if (temp->top && temp->top->cellType == 0 && temp->top->isOpened == 0)
                    cellQueue.push(temp->top);
                if (temp->rightTop && temp->rightTop->cellType == 0 && temp->rightTop->isOpened == 0)
                    cellQueue.push(temp->rightTop);
                if (temp->left && temp->left->cellType == 0 && temp->left->isOpened == 0)
                    cellQueue.push(temp->left);
                if (temp->right && temp->right->cellType == 0 && temp->right->isOpened == 0)
                    cellQueue.push(temp->right);
                if (temp->leftBottom && temp->leftBottom->cellType == 0 && temp->leftBottom->isOpened == 0)
                    cellQueue.push(temp->leftBottom);
                if (temp->bottom && temp->bottom->cellType == 0 && temp->bottom->isOpened == 0)
                    cellQueue.push(temp->bottom);
                if (temp->rightBottom && temp->rightBottom->cellType == 0 && temp->rightBottom->isOpened == 0)
                    cellQueue.push(temp->rightBottom);
            }
        }
        return 1;
    }
}

int hint(Cell ***grid, int row, int col, int rowSize, int colSize)
{
    Cell *temp = grid[row - 1][col - 1];

    if (temp->cellType == 1)
    {
        if (temp->isMarked == 0)
        {
            temp->isMarked = 1;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        open(grid, row, col, rowSize, colSize);
        return -1;
    }
}

int judge(Cell ***grid, int rowSize, int colSize, int currMarks, int bombs)
{
    int i, j;
    if (currMarks != bombs)
    {
        return 0;
    }

    for (i = 0; i < rowSize; i++)
    {
        for (j = 0; j < colSize; j++)
        {
            Cell *temp = grid[i][j];
            if (temp->cellType == 1)
            {
                if (temp->isMarked == 0)
                    return 0;
            }
        }
    }
    return 1;
}