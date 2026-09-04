/*
Q # 02: Implement a new class SortedDoubleLinkedList class that keeps itself always sorted (ascending / descending)
*/

#include <iostream>
using namespace std;

class Node
{
private:
    int value;
    Node *next;
    Node *prev;

public:
    Node(int value = 0)
    {
        this->value = value;
        next = NULL;
        prev = NULL;
    }

    void setNext(Node *next)
    {
        this->next = next;
    }

    void setPrev(Node *prev)
    {
        this->prev = prev;
    }

    void setValue(int value)
    {
        this->value = value;
    }

    Node *getNext()
    {
        return this->next;
    }

    Node *getPrev()
    {
        return this->prev;
    }

    int getValue()
    {
        return value;
    }
};

class SortedDoubleLinkedList
{
private:
    Node *Head;

public:
    SortedDoubleLinkedList()
    {
        Head = NULL;
    }

    bool isEmpty()
    {
        return Head == NULL;
    }

    void insertSortedly(int value)
    {
        Node *new_node = new Node(value);

        if (isEmpty())
        {
            Head = new_node;
        }
        else
        {
            if (value <= Head->getValue())
            {
                new_node->setNext(Head);
                Head->setPrev(new_node);
                Head = new_node;
            }
            else
            {
                Node *ptr = Head;
                while (ptr->getNext() != NULL && !(value > ptr->getValue() && value <= ptr->getNext()->getValue()))
                {
                    ptr = ptr->getNext();
                }

                if (ptr->getNext() == NULL)
                {
                    ptr->setNext(new_node);
                    new_node->setPrev(ptr);
                }
                else
                {
                    new_node->setNext(ptr->getNext());
                    ptr->getNext()->setPrev(new_node);
                    ptr->setNext(new_node);
                    new_node->setPrev(ptr);
                }
            }
        }
    }

    void printLinkedList()
    {
        cout << "\nYour Linked List Values are: ";
        Node *ptr = Head;
        while (ptr != NULL)
        {
            cout << ptr->getValue() << ", ";
            ptr = ptr->getNext();
        }
    }
};

int main()
{
    SortedDoubleLinkedList list;

    int size, value;
    cout << "\nPlease Enter Your LinkedList Size: ";
    cin >> size;

    cout << "\nPlease Enter Your Linked List Values: ";
    for (int i = 0; i < size; i++)
    {
        cin >> value;
        list.insertSortedly(value);
    }

    list.printLinkedList();
    return 0;
}