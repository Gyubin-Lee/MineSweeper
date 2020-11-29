#include <iostream>
#include "inGameOption.h"
#include "createGrid.h"
#include "render.h"

using namespace std;

int main()
{
    int rowSize, colSize;
    int bombs, hints, bSquares;

    cout << "### Minesweeper ###" << endl;

    do
    {
        cout << "Size(row) : ";
        cin >> rowSize;
        if (rowSize < 1)
            cout << "Please enter the number that larger than 0" << endl;
    } while (rowSize < 1);

    do
    {
        cout << "Size(col) : ";
        cin >> colSize;
        if (colSize < 1)
            cout << "Please enter the number that larger than 0" << endl;
    } while (colSize < 1);

    do
    {
        cout << "Total number of bombs(<row*col) : ";
        cin >> bombs;
        if (bombs < 1)
            cout << "You need at least 1 bomb" << endl;
        if (bombs >= rowSize * colSize)
            cout << "Too many bombs!" << endl;
    } while (bombs < 1 || bombs >= rowSize * colSize);

    do
    {
        cout << "Total number of hints(<row*col) : ";
        cin >> hints;
        if (hints < 0)
            cout << "Please enter the number that larger than 0 or 0" << endl;
        if (hints >= rowSize * colSize)
            cout << "Too many hints!" << endl;
    } while (hints < 0 || hints >= rowSize * colSize);

    do
    {
        cout << "Total number of blocked squares(<row*col-#ofBombs) : ";
        cin >> bSquares;
        if (bSquares < 0)
            cout << "Please enter the number that larger than 0 or 0" << endl;
        if (bSquares >= rowSize * colSize - bombs)
            cout << "Too many blocked squares!" << endl;
    } while (bSquares < 0 || bSquares >= rowSize * colSize - bombs);

    Cell **grid = createGrid(rowSize, colSize, bombs, bSquares);

    cout << endl
         << "############" << endl;
    cout << "Game Start!!" << endl;
    cout << "############" << endl
         << endl;

    int row, col;
    char act, exit;
    int currBombs = bombs;
    int currHints = hints;
    int result;

    //renderDebug(grid, rowSize, colSize);
    cout << endl;

    while (1)
    {
        render(grid, rowSize, colSize, currBombs, currHints);

        cout << "(e)xit : ";
        cin >> exit;
        if (exit == 'e')
            break;

        do
        {
            cout << "Enter row : ";
            cin >> row;
            if (row < 1 || row > rowSize)
                cout << "Invalid number" << endl;
        } while (row < 1 || row > rowSize);

        do
        {
            cout << "Enter column : ";
            cin >> col;
            if (col < 1 || col > colSize)
                cout << "Invalid number" << endl;
        } while (col < 1 || col > colSize);

        do
        {
            cout << "Action - (o)pen, (m)ark, (h)int : ";
            cin >> act;
            if (act == 'o')
            {
                result = open(grid, row, col, rowSize, colSize);
                if (result == -1)
                {
                    cout << "Game over!" << endl;
                    renderBomb(grid, rowSize, colSize);
                    return 0;
                }
                else if (result == 0)
                {
                    cout << "It's a block!" << endl;
                }
                break;
            }
            else if (act == 'm')
            {
                if (mark(grid, row, col) == 1)
                    currBombs--;

                else
                    currBombs++;

                break;
            }
            else if (act == 'h')
            {
                if (currHints < 1)
                {
                    cout << "You don't have any hint" << endl;
                }
                else
                {
                    if (hint(grid, row, col, rowSize, colSize) == 1)
                    {
                        currBombs--;
                    };
                    currHints--;
                }
                break;
            }
            else
                cout << "Type o, m, or h" << endl;
        } while (1);

        if (judge(grid, rowSize, colSize))
        {
            cout << "Success!" << endl;
            break;
        }

        cout << endl;
    }
}