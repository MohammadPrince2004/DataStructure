#ifndef NODE
#define NODE
#include <iostream>
using namespace std;
template <typename TYPE>
class Node
{
public:
    char Key;
    TYPE Value;
    Node *next;
    Node(char key, TYPE value)
    {
        Key = key;
        Value = value;
        next = NULL;
    }
};
#endif