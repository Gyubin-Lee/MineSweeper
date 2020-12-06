#include "renderChain.h"
#include <iostream>

using namespace std;

void render(Cell ***grid, int rowSize, int colSize, int currBombs, int currHints)
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
        {
            if (i < 10)
                cout << i << "  ";
            else
            {
                cout << i << " ";
            }
        }
    }
    cout << endl;
    for (i = 0; i < rowSize; i++)
    {
        if (i + 1 < 10)
            cout << i + 1 << "  ";
        else
            cout << i + 1 << " ";

        for (j = 0; j < colSize; j++)
        {
            if (grid[i][j]->cellType != 2)
            {
                if (grid[i][j]->isOpened)
                {
                    cout << grid[i][j]->adjacentBombs << "  ";
                }
                else
                {
                    if (grid[i][j]->isMarked)
                        cout << "M  ";
                    else
                        cout << "_  ";
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

void renderBomb(Cell ***grid, int rowSize, int colSize)
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
        {
            if (i < 10)
                cout << i << "  ";
            else
            {
                cout << i << " ";
            }
        }
    }
    cout << endl;
    for (i = 0; i < rowSize; i++)
    {
        if (i + 1 < 10)
            cout << i + 1 << "  ";
        else
            cout << i + 1 << " ";

        for (j = 0; j < colSize; j++)
        {
            if (grid[i][j]->cellType != 2)
            {
                if (grid[i][j]->cellType == 1)
                {
                    cout << "B  ";
                }
                else
                {
                    if (grid[i][j]->isOpened == 1)
                    {
                        cout << grid[i][j]->adjacentBombs << "  ";
                    }
                    else
                    {
                        cout << "_  ";
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

void renderAdj(Cell ***grid, int rowSize, int colSize)
{
    int i, j;

    cout << "renderAdj" << endl;

    cout << endl;
    for (i = 0; i < colSize + 1; i++)
    {
        if (i == 0)
            cout << "   ";
        else
        {
            if (i < 10)
                cout << i << "  ";
            else
            {
                cout << i << " ";
            }
        }
    }
    cout << endl;
    for (i = 0; i < rowSize; i++)
    {
        if (i + 1 < 10)
            cout << i + 1 << "  ";
        else
            cout << i + 1 << " ";

        for (j = 0; j < colSize; j++)
        {
            if (grid[i][j]->cellType != 2)
            {
                if (grid[i][j]->cellType == 1)
                {
                    cout << "B  ";
                }
                else
                {

                    cout << grid[i][j]->adjacentBombs << "  ";
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
