#include "render.h"
#include <iostream>

using namespace std;

void render(Cell **grid, int rowSize, int colSize, int currBombs, int currHints)
{
    int i, j;
    cout << "Bombs left = " << currBombs << ", Hints left = " << currHints << ";" << endl;

    for (i = 0; i < colSize; i++)
    {
        cout << "-----";
    }
    cout << endl;
    for (i = 0; i < colSize + 1; i++)
    {
        if (i == 0)
            cout << "   ";
        else
            cout << i << "  ";
    }
    cout << endl;
    for (i = 0; i < rowSize; i++)
    {
        cout << i + 1 << "  ";
        for (j = 0; j < colSize; j++)
        {
            if (grid[i][j].cellType != 2)
            {
                if (grid[i][j].isOpened)
                {
                    cout << grid[i][j].adjacentBombs << "  ";
                }
                else
                {
                    if (grid[i][j].isMarked)
                        cout << "M  ";
                    else
                        cout << "O  ";
                }
            }
            else
                cout << "X  ";
        }
        cout << endl;
    }
    for (i = 0; i < colSize; i++)
    {
        cout << "-----";
    }
    cout << endl;
}

void rendeDebug(Cell **grid, int rowSize, int colSize)
{
    int i, j;

    for (i = 0; i < colSize; i++)
    {
        cout << "-----";
    }
    cout << endl;
    for (i = 0; i < colSize + 1; i++)
    {
        if (i == 0)
            cout << "   ";
        else
            cout << i << "  ";
    }
    cout << endl;
    for (i = 0; i < rowSize; i++)
    {
        cout << i + 1 << "  ";
        for (j = 0; j < colSize; j++)
        {
            if (grid[i][j].cellType == 0)
            {
                cout << grid[i][j].adjacentBombs << "  ";
            }
            else if (grid[i][j].cellType == 1)
            {
                cout << "B  ";
            }
            else
            {
                cout << "X  ";
            }
        }
        cout << endl;
    }
    for (i = 0; i < colSize; i++)
    {
        cout << "-----";
    }
    cout << endl;
}

void renderBomb(Cell **grid, int rowSize, int colSize)
{
    int i, j;

    for (i = 0; i < colSize; i++)
    {
        cout << "-----";
    }
    cout << endl;
    for (i = 0; i < colSize + 1; i++)
    {
        if (i == 0)
            cout << "   ";
        else
            cout << i << "  ";
    }
    cout << endl;
    for (i = 0; i < rowSize; i++)
    {
        cout << i + 1 << "  ";
        for (j = 0; j < colSize; j++)
        {
            if (grid[i][j].cellType != 2)
            {
                if (grid[i][j].cellType == 1)
                {
                    cout << "B  ";
                }
                else
                {
                    if (grid[i][j].isOpened == 1)
                    {
                        cout << grid[i][j].adjacentBombs << "  ";
                    }
                    else
                    {
                        cout << "O  ";
                    }
                }
            }
            else
                cout << "X  ";
        }
        cout << endl;
    }
    for (i = 0; i < colSize; i++)
    {
        cout << "-----";
    }
    cout << endl;
}