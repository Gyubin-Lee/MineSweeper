#include "renderChain.h"
#include <iostream>

using namespace std;

void render(cellChain *grid, int rowSize, int colSize, int currBombs, int currHints)
{
    int i;
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

    int k = 0;

    while (k < rowSize)
    {
        cout << k + 1 << "  ";
        int l = 0;
        while (l < colSize)
        {
            Cell *tempCell = grid->returnCell(k, l);
            if (tempCell->cellType != 2)
            {
                if (tempCell->isOpened)
                {
                    cout << tempCell->adjacentBombs << "  ";
                }
                else
                {
                    if (tempCell->isMarked)
                        cout << "M  ";
                    else
                        cout << "_  ";
                }
            }
            else
                cout << "X  ";
            l++;
        }
        cout << endl;
        k++;
    }

    for (i = 0; i < colSize; i++)
    {
        cout << "-----";
    }
    cout << endl;
}

void renderBomb(cellChain *grid, int rowSize, int colSize)
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
            Cell *temp = grid->returnCell(i, j);
            if (temp->cellType != 2)
            {
                if (temp->cellType == 1)
                {
                    cout << "B  ";
                }
                else
                {
                    if (temp->isOpened == 1)
                    {
                        cout << temp->adjacentBombs << "  ";
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
