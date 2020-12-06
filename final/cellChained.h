#ifndef C_CHAIN_H
#define C_CHAIN_H

#include "cell.h"
#include <iostream>

class cellChain;

class cellNode
{
    friend class cellChain;

public:
    cellNode(Cell *cell_)
    {
        cell = cell_;
        next = 0;
        down = 0;
    }

private:
    Cell *cell;
    cellNode *next;
    cellNode *down;
};

class cellChain
{
public:
    cellChain()
    {
        first = 0;
    }

    void addHeadLast(Cell *newData)
    {
        if (!first)
        {
            cellNode *newNode = new cellNode(newData);
            first = newNode;
        }
        else
        {
            cellNode *temp = first;
            cellNode *prev;
            while (temp)
            {
                prev = temp;
                temp = temp->down;
            }
            cellNode *newNode = new cellNode(newData);
            prev->down = newNode;
        }
    }
    void addItemLast(int headIndex, Cell *newData)
    {
        int i = 0;
        cellNode *temp = first;
        while (i < headIndex)
        {
            temp = temp->down;
            i++;
        }
        cellNode *prev;
        while (temp)
        {
            prev = temp;
            temp = temp->next;
        }
        cellNode *newNode = new cellNode(newData);
        prev->next = newNode;
    }
    Cell *returnCell(int row, int col)
    {
        int i = 0;
        int j = 0;
        cellNode *temp = first;
        while (i < row)
        {
            temp = temp->down;
            i++;
        }
        while (j < col)
        {
            temp = temp->next;
            j++;
        }
        return temp->cell;
    }

    void printCellType()
    {
        cellNode *tempHead = first;
        while (tempHead)
        {
            cellNode *tempItem = tempHead;
            while (tempItem)
            {
                std::cout << tempItem->cell->cellType;
                std::cout << "  ";
                tempItem = tempItem->next;
            }
            std::cout << std::endl;
            tempHead = tempHead->down;
        }
    }

private:
    cellNode *first;
};

#endif