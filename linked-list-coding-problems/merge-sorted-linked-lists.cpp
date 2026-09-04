/*
Q # 04: Write a method add_lists(list1, list2) that receives the instances of two sorted lists and merges them in a way that resultant listed is also sorted.
*/

#include <iostream>
using namespace std;

class Node
{
private:
    int value;
    Node *next;

public:
    Node(int value)
    {
        this->value = value;
        next = NULL;
    }

    int getValue()
    {
        return value;
    }

    Node *getNext()
    {
        return next;
    }

    void setNext(Node *next)
    {
        this->next = next;
    }

    void setValue(int value)
    {
        this->value = value;
    }
};

class SinglyLinkedList
{
private:
    Node *Head;

public:
    SinglyLinkedList()
    {
        Head = NULL;
    }

    bool isEmpty()
    {
        return (Head == NULL);
    }

    Node *getHead()
    {
        return this->Head;
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
                Head = new_node;
            }
            else
            {
                Node *ptr = Head;
                while (ptr->getNext() != NULL && !(value > ptr->getValue() && value <= ptr->getNext()->getValue()))
                {
                    ptr = ptr->getNext();
                }

                new_node->setNext(ptr->getNext());
                ptr->setNext(new_node);
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

SinglyLinkedList addList(SinglyLinkedList list1, SinglyLinkedList list2)
{
    SinglyLinkedList list;

    Node *ptr1 = list1.getHead();
    while (ptr1 != NULL)
    {
        list.insertSortedly(ptr1->getValue());
        ptr1 = ptr1->getNext();
    }

    Node *ptr2 = list2.getHead();
    while (ptr2 != NULL)
    {
        list.insertSortedly(ptr2->getValue());
        ptr2 = ptr2->getNext();
    }

    return list;
}

int main()
{
    SinglyLinkedList list1, list2, list;

    int size, value;
    cout << "\nPlease Enter Your LinkedList Size: ";
    cin >> size;

    cout << "\nPlease Enter Your First Linked List Values: ";
    for (int i = 0; i < size; i++)
    {
        cin >> value;
        list1.insertSortedly(value);
    }

    cout << "\nPlease Enter Your Second Linked List Values: ";
    for (int i = 0; i < size; i++)
    {
        cin >> value;
        list2.insertSortedly(value);
    }

    list = addList(list1, list2);
    list.printLinkedList();

    return 0;
}