#include <iostream>

class Node
{
public:
    int data;
    int height;
    Node *left, *right;
    Node()
    {
        left = NULL;
        right = NULL;
        height = 0;
    }
};