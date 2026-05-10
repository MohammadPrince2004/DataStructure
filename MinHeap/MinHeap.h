

#include <iostream>
using namespace std;
template <typename TYPE>
#define SIZE 256

class MinHeap
{
private:
    TYPE Data[SIZE];
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
    void Insert(TYPE node)
    {
        Data[index] = node;
        index++;

        int i = index - 1;
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (Data[i] < Data[parent])
            {
                swap(Data[i], Data[parent]);
                i = parent;
            }
            else
                break;
        }
    }
    TYPE ExtractMin()
    {
        Display();
        cout<<"[-=-=-=--==]\n";
        if (isEmpty())
            return TYPE{};

        TYPE Min = Data[0];

        Data[0] = Data[index - 1];
        index--;

        int i = 0;
        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < index && Data[left] < Data[smallest])
                smallest = left;

            if (right < index && Data[right] < Data[smallest])
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
            cout << i << " -> " << Data[i] << "\n";
        }
    }
};
