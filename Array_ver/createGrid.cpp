#include "cell.h"
#include "createGrid.h"
#include <cstdlib>
#include <iostream>

Cell **createGrid(int rowSize, int colSize, int bombs, int bSquares)
{
    int i, j;
    int currBS = bSquares;
    int currBombs = bombs;
    int remainCell = rowSize * colSize;

    Cell **grid = new Cell *[rowSize];

    //initialize grid

    for (i = 0; i < rowSize; i++)
    {
        grid[i] = new Cell[colSize];
        for (j = 0; j < colSize; j++)
        {
            Cell temp;

            if (currBS > 0 && currBombs > 0 && remainCell == currBS + currBombs)
            {
                temp = Cell(i, j, 2);
                currBS--;
            }
            else if (currBS == 0 && remainCell == currBombs)
            {
                temp = Cell(i, j, 1);
                //std::cout << "bomb: " << i + 1 << " " << j + 1 << std::endl;
                currBombs--;
            }
            else
            {
                if (currBS > 0 && rand() % remainCell < currBS)
                {
                    temp = Cell(i, j, 2);
                    currBS--;
                }
                else
                {
                    if (currBombs > 0 && rand() % remainCell < currBombs)
                    {
                        temp = Cell(i, j, 1);
                        //std::cout << "bomb: " << i + 1 << " " << j + 1 << std::endl;
                        currBombs--;
                    }
                    else
                        temp = Cell(i, j, 0);
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
            if (grid[i][j].cellType == 1)
            {
                for (k = i - 1; k <= i + 1; k++)
                {
                    for (l = j - 1; l <= j + 1; l++)
                    {
                        if (k >= 0 && k < rowSize && l >= 0 && l < colSize)
                        {
                            grid[k][l].adjacentBombs++;
                        }
                    }
                }
            }
        }
    }

    return grid;
}