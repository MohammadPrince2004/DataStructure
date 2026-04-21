#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int val){
            left = NULL;
            right = NULL;
            data = val;
        }
};