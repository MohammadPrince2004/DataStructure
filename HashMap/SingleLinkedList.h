#ifndef SINGLELL
#define SINGLELL

#include <iostream>
#include "Node.h"
using namespace std;
template <typename TYPE>

class SingleLinkedList
{
private:
    Node<TYPE> *head;

public:
    SingleLinkedList()
    {
        head = NULL;
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
    void InsertAtFirst(char key, TYPE value)
    {
        Node<TYPE> *newNode = new Node(key, value);
        newNode->next = head;
        newNode->Value = value;
        head = newNode;
    }
    void InsertAtLast(char key, TYPE value)
    {
        if (isEmpty())
        {
            InsertAtFirst(key, value);
        }
        else
        {
            Node<TYPE> *newNode = new Node(key, value);
            Node<TYPE> *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void DeleteFirstNode()
    {
        if (!isEmpty())
        {
            Node<TYPE> *dltptr = head;
            head = head->next;
            delete dltptr;
        }
        else
        {
            cout << "Empty List !!\n";
        }
    }
    void DeleteLastNode()
    {
        if (!isEmpty())
        {
            if (Count() == 1)
            {
                DeleteFirstNode();
            }
            else
            {
                Node<TYPE> *dltptr = NULL;
                Node<TYPE> *temp = head;
                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                dltptr = temp->next;
                temp->next = NULL;
                delete dltptr;
            }
        }
        else
        {
            cout << "Empty List !!\n";
        }
    }
    void DeleteAnyNode(char element)
    {
        Node<TYPE> *dltptr = Search(element);
        if (!isEmpty())
        {
            if (dltptr == head)
            {
                DeleteFirstNode();
            }
            else if (dltptr->next == NULL)
            {
                DeleteLastNode();
            }
            else
            {

                Node<TYPE> *temp = head;
                while (temp->next != dltptr)
                {
                    temp = temp->next;
                }
                temp->next = dltptr->next;
                delete dltptr;
            }
        }
        else
        {
            cout << "Empty List !!\n";
        }
    }
    void Show()
    {
        if (isEmpty())
        {
            cout << "Empty List !!\n";
        }
        else
        {
            Node<TYPE> *temp = head;
            while (temp != NULL)
            {
                cout << "Key -> " << temp->Key << " ===> Value -> " << temp->Value << endl;
                temp = temp->next;
            }
        }
    }
    int Count()
    {
        int count = 0;
        if (!isEmpty())
        {
            Node<TYPE> *temp = head;

            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
        }
        return count;
    }
    Node<TYPE> *Search(char key)
    {

        if (!isEmpty())
        {
            Node<TYPE> *temp = head;

            while (temp != NULL)
            {
                if (temp->Key == key)
                {
                    return temp;
                }
                temp = temp->next;
            }
        }
        return NULL;
    }
};

#endif