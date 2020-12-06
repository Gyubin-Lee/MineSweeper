#include "inGameOptionChain.h"

int mark(cellChain *grid, int row, int col)
{
    Cell *temp = grid->returnCell(row - 1, col - 1);
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

int open(cellChain *grid, int row, int col, int rowSize, int colSize)
{
    Cell *temp = grid->returnCell(row - 1, col - 1);
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
        Queue rowQueue = Queue();
        Queue colQueue = Queue();

        rowQueue.push(row - 1);
        colQueue.push(col - 1);

        int i, j, k, l;
        while (!rowQueue.isEmpty() && !colQueue.isEmpty())
        {
            i = rowQueue.pop();
            j = colQueue.pop();

            Cell *temp2 = grid->returnCell(i, j);
            temp2->isOpened = 1;

            if (temp2->adjacentBombs == 0)
            {
                for (k = i - 1; k <= i + 1; k++)
                {
                    for (l = j - 1; l <= j + 1; l++)
                    {
                        if (k >= 0 && k < rowSize && l >= 0 && l < colSize)
                        {
                            if (k != i || l != j)
                            {
                                Cell *temp3 = grid->returnCell(k, l);
                                if (temp3->isOpened == 0 && temp3->cellType == 0)
                                {
                                    rowQueue.push(k);
                                    colQueue.push(l);
                                }
                            }
                        }
                    }
                }
            }
        }
        return 1;
    }
}

int hint(cellChain *grid, int row, int col, int rowSize, int colSize)
{
    Cell *temp = grid->returnCell(row - 1, col - 1);

    if (temp->cellType == 1)
    {
        temp->isMarked = 1;
        return 1;
    }
    else
    {
        open(grid, row, col, rowSize, colSize);
        return -1;
    }
}

int judge(cellChain *grid, int rowSize, int colSize)
{
    int i, j;
    for (i = 0; i < rowSize; i++)
    {
        for (j = 0; j < colSize; j++)
        {
            Cell *temp = grid->returnCell(i, j);
            if (temp->cellType == 1)
            {
                if (temp->isMarked == 0)
                    return 0;
            }
        }
    }
    return 1;
}