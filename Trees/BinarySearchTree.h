#include <iostream>
#include <Queue>
#include "Node.h"
using namespace std;

class BinarySearchTree
{
private:
    Node *root;
    int nodeNumber;
    
    void TraverseInFix(Node *r)
    {
        if (r == NULL)
            return;
        TraverseInFix(r->left);
        cout << r->data << "\t";
        TraverseInFix(r->right);
    }
    void TraversePreFix(Node *r)
    {
        if (r == NULL)
            return;
        cout << r->data << "\t";
        TraversePreFix(r->left);
        TraversePreFix(r->right);
    }
    void TraversePostFix(Node *r)
    {
        if (r == NULL)
            return;
        TraversePostFix(r->left);
        TraversePostFix(r->right);
        cout << r->data << "\t";
    }
    Node *InsertItem(int item, Node *r)
    {
        if (r == NULL)
        {
            
            Node *newNode = new Node(item);
            r = newNode;
        }
        else
        {
            if (item > r->data)
                r->right = InsertItem(item, r->right);
            else if (item <= r->data)
                r->left = InsertItem(item, r->left);
        }
        return r;
    }
    Node *Search(int item, Node *r)
    {
        if (r != NULL)
        {
            if (r->data == item)
                return r;

            else
            {
                if (item < r->data)
                    return Search(item, r->left);
                else
                    return Search(item, r->right);
            }
        }
        return r;
    }
    Node *getMax(Node *r)
    {
        if (r != NULL)
        {
            if (r->right == NULL)
                return r;
            else
                r = getMax(r->right);
        }
        return r;
    }
    Node *getMin(Node *r)
    {
        if (r != NULL)
        {
            if (r->left == NULL)
                return r;
            else
                r = getMin(r->left);
        }
        return r;
    }
    Node *DeleteItem(int item, Node *r)
    {   
        Node* temp;
        if(r==NULL)
        {
            return r;
        }
        else
        {
            if(item<r->data)
            {
                r->left = DeleteItem(item,r->left);
            }
            else if(item>r->data)
            {   
                r->right = DeleteItem(item,r->right);
            }
            else
            {
                temp = r ;
                // one of leaves 
                if((temp->right==NULL)&&(temp->left==NULL))
                {
                    temp = NULL;
                    delete r;
                    return temp; 
                }
                else if((temp->right!=NULL)&&(temp->left==NULL))
                {
                    temp = r->right;
                    delete r;
                    return temp;
                }
                else if((temp->right==NULL)&&(temp->left!=NULL))
                {
                    temp = r->left;
                    delete r;
                    return temp;
                }
                else
                {
                    temp = getMin(r->right);
                    r->data = temp ->data; 
                    r->right = DeleteItem(temp->data,r->right);
                    return temp;
                }
            }
            return r;
        }

    }

public:
    BinarySearchTree()
    {
        root = NULL;
        nodeNumber = 0;
    }
    void Insert(int Item)
    {
        root = InsertItem(Item, root);
        nodeNumber++;
    }
    void DeleteItem(int item)
    {
        if(Search(item,root))
        {
            root = DeleteItem(item,root);
            cout<<"DONE !! \n";
            nodeNumber--;
        }
        else
        {
            cout<<"Not Found in Tree !! \n";
        }

            
    }
    void TraverseInFix()
    {
        TraverseInFix(root);
    }
    void TraversePreFix()
    {
        TraversePreFix(root);
    }
    void TraversePostFix()
    {
        TraversePostFix(root);
    }
    void TraverseBreadth()
    {
        Node* current = root ;
        queue <Node*> dataQueue ;
        dataQueue.push(current);
        while(!dataQueue.empty())
        {
            current = dataQueue.front();
            if(current->left!=NULL)
            {
                dataQueue.push(current->left);
            }
            if(current->right!=NULL)
            {
                dataQueue.push(current->right);
            }
            cout<<current->data<<"\t";
            dataQueue.pop();
        }

    }
    void Search(int item)
    {
        Node *found = Search(item, root);
        if (found != NULL)
            cout << "Found !!" << endl;
        else
            cout << "Not Found !!" << endl;
    }
    void getMax()
    {
        Node *maxPtr = getMax(root);
        if (maxPtr != NULL)
            cout << maxPtr->data << "\n";
        else
            cout << "Empty !!\n";
    }
    void getMin()
    {
        Node *minPtr = getMin(root);
        if (minPtr != NULL)
            cout << minPtr->data << "\n";
        else
            cout << "Empty !!\n";
    }
    int getNodesNumber()
    {
        return nodeNumber;
    }
    
};