#include "inGameOption.h"

int mark(Cell **grid, int row, int col)
{
    if (grid[row - 1][col - 1].isMarked == 0)
    {
        grid[row - 1][col - 1].isMarked = 1;
        return 1;
    }
    else
    {
        grid[row - 1][col - 1].isMarked = 0;
        return -1;
    }
}

int open(Cell **grid, int row, int col, int rowSize, int colSize)
{
    if (grid[row - 1][col - 1].cellType == 1)
    { //bomb
        return -1;
    }
    else if (grid[row - 1][col - 1].cellType == 2)
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

            grid[i][j].isOpened = 1;

            if (grid[i][j].adjacentBombs == 0)
            {
                for (k = i - 1; k <= i + 1; k++)
                {
                    for (l = j - 1; l <= j + 1; l++)
                    {
                        if (k >= 0 && k < rowSize && l >= 0 && l < colSize)
                        {
                            if (k != i || l != j)
                            {
                                if (grid[k][l].isOpened == 0 && grid[k][l].cellType == 0)
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

int hint(Cell **grid, int row, int col, int rowSize, int colSize)
{
    if (grid[row - 1][col - 1].cellType == 1)
    {
        grid[row - 1][col - 1].isMarked = 1;
        return 1;
    }
    else
    {
        open(grid, row, col, rowSize, colSize);
        return -1;
    }
}

int judge(Cell **grid, int rowSize, int colSize)
{
    int i, j;
    for (i = 0; i < rowSize; i++)
    {
        for (j = 0; j < colSize; j++)
        {
            if (grid[i][j].cellType == 1)
            {
                if (grid[i][j].isMarked == 0)
                    return 0;
            }
        }
    }
    return 1;
}