#ifndef QUEUE_H
#define QUEUE_H

#include "linkedList.h"

class Queue
{
public:
    LinkedList *list;
    int item;

    Queue()
    {
        list = new LinkedList();
        item = 0;
    }

    void push(int newData)
    {
        list->addLast(newData);
        item++;
    }

    int pop()
    {
        if (!item)
        {
            return -1;
        }
        else
        {
            item--;
            return list->removeFirst();
        }
    }

    void print()
    {
        list->print();
    }

    int isEmpty()
    {
        if (!item)
            return 1;
        return 0;
    }
};

#endif