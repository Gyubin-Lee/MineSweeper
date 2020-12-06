#ifndef L_LIST_H
#define L_LIST_H

#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node() {}
    Node(int data_, Node *next_)
    {
        data = data_;
        next = next_;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = 0;
    }
    LinkedList(Node *head_)
    {
        head = head_;
    }

    void addLast(int newData)
    {
        Node *newNode = new Node(newData, 0);
        if (!head)
            head = newNode;
        else
        {
            Node *temp = head;
            Node *prev;
            while (temp)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = newNode;
        }
    }

    int removeFirst()
    {
        Node *temp = head;
        int item = temp->data;
        head = head->next;
        delete temp;
        return item;
    }

    void print()
    {
        if (!head)
            std::cout << "Nothing to print" << std::endl;

        else
        {
            Node *temp = head;
            Node *prev;
            while (temp)
            {
                std::cout << temp->data << "  ";
                prev = temp;
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }
};

#endif