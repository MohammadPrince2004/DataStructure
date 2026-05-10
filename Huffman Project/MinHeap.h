
#ifndef HEAP
#define HEAP
#include <iostream>
#include "HuffmanNode.h"
using namespace std;
#define SIZE 256

class MinHeap
{
private:
    HuffmanNode *Data[SIZE];
    int index;

public:
    MinHeap()
    {
        index = 0;
    }
    int getSize()
    {
        return index;
    }
    bool isEmpty()
    {
        return (index == 0);
    }
    void Insert(HuffmanNode *node)
    {
        Data[index] = node;
        index++;

        int i = index - 1;
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (Data[i]->frequency < Data[parent]->frequency)
            {
                swap(Data[i], Data[parent]);
                i = parent;
            }
            else
                break;
        }
    }
    HuffmanNode *ExtractMin()
    {
        Display();
        cout<<"[-=-=-=--==]\n";
        if (isEmpty())
            return NULL;

        HuffmanNode *Min = Data[0];

        Data[0] = Data[index - 1];
        index--;

        int i = 0;
        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < index && Data[left]->frequency < Data[smallest]->frequency)
                smallest = left;

            if (right < index && Data[right]->frequency < Data[smallest]->frequency)
                smallest = right;

            if (smallest != i)
            {
                swap(Data[i], Data[smallest]);
                i = smallest;
            }
            else
                break;
        }

        return Min;
    }
    void Display()
    {
        for (int i = 0; i < index; i++)
        {
            cout << Data[i]->character << " -> " << Data[i]->frequency << "\n";
        }
    }
};

#endif