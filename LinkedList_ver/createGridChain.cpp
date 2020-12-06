#include "createGridChain.h"
#include <cstdlib>
#include <iostream>

cellChain *createGrid(int rowSize, int colSize, int bombs, int bSquares)
{
    int i = 0;
    int currBS = bSquares;
    int currBombs = bombs;
    int remainCell = rowSize * colSize;

    cellChain *grid = new cellChain();

    while (i < rowSize)
    {
        Cell *temp;
        int j = 0;
        while (j < colSize)
        {
            if (currBS > 0 && currBombs > 0 && remainCell == currBS + currBombs)
            {
                temp = new Cell(i, j, 2);
                currBS--;
            }
            else if (currBS == 0 && remainCell == currBombs)
            {
                temp = new Cell(i, j, 1);
                currBombs--;
            }
            else
            {
                if (currBS > 0 && rand() % remainCell < currBS)
                {
                    temp = new Cell(i, j, 2);
                    currBS--;
                }
                else
                {
                    if (currBombs > 0 && rand() % remainCell < currBombs)
                    {
                        temp = new Cell(i, j, 1);
                        currBombs--;
                    }
                    else
                        temp = new Cell(i, j, 0);
                }
            }
            if (j == 0)
            {
                grid->addHeadLast(temp);
            }
            else
            {
                grid->addItemLast(i, temp);
            }
            remainCell--;
            j++;
        }
        i++;
    }

    int j, k, l;
    for (i = 0; i < rowSize; i++)
    {
        for (j = 0; j < colSize; j++)
        {
            Cell *temp = grid->returnCell(i, j);
            if (temp->cellType == 1)
            {
                for (k = i - 1; k <= i + 1; k++)
                {
                    for (l = j - 1; l <= j + 1; l++)
                    {
                        if (k >= 0 && k < rowSize && l >= 0 && l < colSize)
                        {
                            Cell *temp2 = grid->returnCell(k, l);
                            temp2->adjacentBombs++;
                        }
                    }
                }
            }
        }
    }

    return grid;
}