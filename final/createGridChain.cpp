#include "createGridChain.h"
#include <cstdlib>

Cell ***createGrid(int rowSize, int colSize, int bombs, int bSquares)
{
    int i, j;
    int currBS = bSquares;
    int currBombs = bombs;
    int remainCell = rowSize * colSize;

    //initialize grid

    Cell ***grid = new Cell **[rowSize];

    for (i = 0; i < rowSize; i++)
    {
        grid[i] = new Cell *[colSize];
        for (j = 0; j < colSize; j++)
        {
            Cell *temp;

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
            grid[i][j] = temp;
            remainCell--;
        }
    }

    //check the number of adjacent bombs
    int k, l;
    for (i = 0; i < rowSize; i++)
    {
        for (j = 0; j < colSize; j++)
        {
            if (grid[i][j]->cellType == 1)
            {
                for (k = i - 1; k <= i + 1; k++)
                {
                    for (l = j - 1; l <= j + 1; l++)
                    {
                        if (k >= 0 && k < rowSize && l >= 0 && l < colSize)
                        {
                            grid[k][l]->adjacentBombs++;
                        }
                    }
                }
            }
        }
    }

    //make connection
    for (i = 0; i < rowSize; i++)
    {
        for (j = 0; j < colSize; j++)
        {
            Cell *temp = grid[i][j];
            if (temp->cellType == 0 && temp->adjacentBombs == 0)
            {
                if (i - 1 >= 0 && i - 1 < rowSize)
                {
                    if (j - 1 >= 0 && j - 1 < colSize)
                        temp->leftTop = grid[i - 1][j - 1];
                    if (j >= 0 && j < colSize)
                        temp->top = grid[i - 1][j];
                    if (j + 1 >= 0 && j + 1 < colSize)
                        temp->rightTop = grid[i - 1][j + 1];
                }
                if (i >= 0 && i < rowSize)
                {
                    if (j - 1 >= 0 && j - 1 < colSize)
                        temp->left = grid[i][j - 1];
                    if (j + 1 >= 0 && j + 1 < colSize)
                        temp->right = grid[i][j + 1];
                }
                if (i + 1 >= 0 && i + 1 < rowSize)
                {
                    if (j - 1 >= 0 && j - 1 < colSize)
                        temp->leftBottom = grid[i + 1][j - 1];
                    if (j >= 0 && j < colSize)
                        temp->bottom = grid[i + 1][j];
                    if (j + 1 >= 0 && j + 1 < colSize)
                        temp->rightBottom = grid[i + 1][j + 1];
                }
            }
        }
    }

    return grid;
}