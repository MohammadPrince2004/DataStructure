#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <iostream>
using namespace std;

class HuffmanNode
{
public:
    char character;
    int frequency;
    HuffmanNode *left;
    HuffmanNode *right;
    HuffmanNode(char c, int f)
    {
        character = c;
        frequency = f;
        left = right = NULL;
    }
};

#endif