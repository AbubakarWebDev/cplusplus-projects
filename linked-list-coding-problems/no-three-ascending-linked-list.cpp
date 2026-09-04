/*
Q # 03: Implement a new class UnsortedList that ensures that not three adjacent nodes in it are in ascending order.
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

class UnsortedList
{
private:
    Node *Head;

public:
    UnsortedList()
    {
        Head = NULL;
    }

    bool isEmpty()
    {
        return (Head == NULL);
    }

    void appendNode(int value)
    {
        Node *new_node = new Node(value);

        if (isEmpty())
        {
            Head = new_node;
        }
        else
        {
            Node *ptr = Head;
            while (ptr->getNext() != NULL)
            {
                ptr = ptr->getNext();
            }
            ptr->setNext(new_node);
        }

        unsortlist();
    }

    void swapNodes(Node *node1, Node *node2)
    {
        int temp = node1->getValue();
        node1->setValue(node2->getValue());
        node2->setValue(temp);
    }

    int count()
    {
        int count = 0;

        Node *ptr = Head;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->getNext();
        }

        return count;
    }

    void unsortlist()
    {
        if (count() >= 3)
        {
            Node *ptr = Head;
            while (ptr->getNext() != NULL && ptr->getNext()->getNext() != NULL)
            {
                Node *first_node = ptr;
                Node *second_node = first_node->getNext();
                Node *third_node = second_node->getNext();

                if ((first_node->getValue() < second_node->getValue()) && (second_node->getValue() < third_node->getValue()))
                {

                    swapNodes(third_node, second_node);
                }
                ptr = ptr->getNext();
            }
        }
    }

    void printLinkedList()
    {
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
    UnsortedList list;

    int size, value;
    cout << "\nPlease Enter Your LinkedList Size: ";
    cin >> size;

    cout << "\nPlease Enter Your Linked List Values: ";
    for (int i = 0; i < size; i++)
    {
        cin >> value;
        list.appendNode(value);
    }

    list.printLinkedList();
    return 0;
}