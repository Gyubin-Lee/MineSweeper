#ifndef CHAIN_H
#define CHAIN_H

#include <iostream>

class Chain;

class Node
{
    friend class Chain;

public:
    Node(int data_)
    {
        data = data_;
        next = 0;
        down = 0;
    }

private:
    int data;
    Node *next;
    Node *down;
};

class Chain
{
public:
    Chain()
    {
        first = 0;
    }
    void addHeadLast(int newData)
    {
        std::cout << "aHL" << std::endl;
        if (!first)
        {
            Node *newNode = new Node(newData);
            first = newNode;
        }
        else
        {
            Node *newNode = new Node(newData);
            Node *temp = first;
            Node *prev;
            while (temp)
            {
                prev = temp;
                temp = temp->down;
            }
            prev->down = newNode;
        }
    }
    void addItemLast(int headIndex, int newData)
    {
        std::cout << "aIL" << std::endl;
        int i = 0;
        Node *temp = first;
        while (i < headIndex)
        {
            std::cout << "i while" << std::endl;
            temp = temp->down;
            i++;
        }
        Node *prev;
        while (temp)
        {
            prev = temp;
            temp = temp->next;
        }
        Node *newNode = new Node(newData);
        prev->next = newNode;
    }

    void print()
    {
        Node *tempHead = first;
        while (tempHead)
        {
            Node *tempItem = tempHead;
            while (tempItem)
            {
                std::cout << tempItem->data << "  ";
                tempItem = tempItem->next;
            }
            std::cout << std::endl;
            tempHead = tempHead->down;
        }
    }

private:
    Node *first;
};

#endif