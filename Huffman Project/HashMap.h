#ifndef HASH
#define HASH
#include <iostream>
#include "SingleLinkedList.h"
using namespace std;
#define SIZE 256
template <typename TYPE>

class HashMap
{
private:
public:
    SingleLinkedList<TYPE> HashTable[SIZE];
    int ExistingElements;
    HashMap()
    {
        ExistingElements = 0;
    }

    int Hash(char key)
    {
        return ((unsigned char)key % SIZE);
    }
    void Insert(char key, TYPE value)
    {
        int index = Hash(key);
        cout << index << endl;
        SingleLinkedList<TYPE> &LL = HashTable[index];
        Node<TYPE> *temp = LL.Search(key);
        if (temp != NULL)
        {
            temp->Value = value;
        }
        else
        {
            LL.InsertAtLast(key, value);
            ExistingElements = ExistingElements + 1;
        }
        
    }
    TYPE Get(char key)
    {
        int index = Hash(key);
        SingleLinkedList<TYPE> &LL = HashTable[index];
        Node<TYPE> *temp = LL.Search(key);
        if (temp != NULL)
        {
            return temp->Value;
            ;
        }
        else
        {
            return TYPE{};
        }
    }
    void Remove(char key)
    {
        int index = Hash(key);
        SingleLinkedList<TYPE> &LL = HashTable[index];
        Node<TYPE> *temp = LL.Search(key);
        if (temp == NULL)
            return;
        else
        {
            LL.DeleteAnyNode(key);
        }
    }
    void Display()
    {
        cout << "-=-=-=-=-=-= Table =-==-=-=-=--=-" << endl;
        Node<TYPE> *temp;
        for (int i = 0; i < SIZE; i++)
        {

            if (!HashTable[i].isEmpty())
            {

                HashTable[i].Show();
            }
        }
        cout << "-=-=-=-=-=-=-==-=-=-=--=-=-=-=-=-" << endl;
    }
};
#endif
