#include <iostream>
#include <queue>
#include "Node.h"
using namespace std;


class AVLTree
{
    private :
        Node* root;
        int updateHeight(Node *r)
        {
            int rightsubtree, leftsubtree;
            if (r == NULL)
                return -1;
            else
            {
                leftsubtree = updateHeight(r->left) + 1;
                rightsubtree = updateHeight(r->right) + 1;
            }
            r->height = max(leftsubtree, rightsubtree);
            return max(leftsubtree, rightsubtree);
        }
        int BalanceFactor(Node *r)
        {
            if (r == NULL)
                return 0;
            return updateHeight(r->left) - updateHeight(r->right);
        }
        Node *RotateRight(Node *r)
        {
            Node *temp = r->left;
            r->left = temp->right;
            temp->right = r;
            temp->height = updateHeight(temp);
            r->height = updateHeight(r);
            return temp;
        }
        Node *RotateLeft(Node *r)
        {
            Node *temp = r->right;
            r->right = temp->left;
            temp->left = r;
            temp->height = updateHeight(temp);
            r->height = updateHeight(r);
            return temp;
        }
        Node *InsertData(Node *r, int item)
        {
            
            if (r == NULL)
            {
                Node *newNode = new Node;
                newNode->data = item;
                r = newNode;
            }
            else
            {
                if (r->data > item)
                {
                    r->left = InsertData(r->left, item);
                }
                else if (r->data <= item)
                {
                    r->right = InsertData(r->right, item);
                }
            }
            // check balance
            if (BalanceFactor(r) == 2)
            {
                if (BalanceFactor(r->left) == -1)
                    // Left Rotation
                    r->left = RotateLeft(r->left);
                // Right Rotation
                r = RotateRight(r);
            }
            if (BalanceFactor(r) == -2)
            {
                if (BalanceFactor(r->right) == +1)
                    // Right Rotation
                    r->right = RotateRight(r->right);
                // Left Rotation
                r = RotateLeft(r);
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
        Node *DeleteItem(Node *r, int item)
        {
            if (r == NULL)
            {
                return NULL;
            }
            else
            {
                if (item > r->data)
                {
                    r->right = DeleteItem(r->right, item);
                }
                else if (item < r->data)
                {
                    r->left = DeleteItem(r->left, item);
                }
                else
                {
                    if ((r->right == NULL) || (r->left == NULL))
                    {
                        if ((r->right == NULL) && (r->left == NULL))
                        {
                            delete r;
                            return NULL;
                        }
                        else
                        {
                            Node *temp;
                            if (r->right == NULL)
                            {
                                temp = r->left;
                            }
                            else
                            {
                                temp = r->right;
                            }
                            delete r;
                            return temp;
                        }
                    }
                    else
                    {
                        Node *temp = getMin(r->right);
                        r->data = temp->data;
                        r->right = DeleteItem(r -> right , temp -> data);
                    }
                    
                }
                // check balance
                if (BalanceFactor(r) == 2)
                {
                    if (BalanceFactor(r->left) == -1)
                        // Left Rotation
                        r->left = RotateLeft(r->left);
                    // Right Rotation
                    r = RotateRight(r);
                }
                if (BalanceFactor(r) == -2)
                {
                    if (BalanceFactor(r->right) == +1)
                        // Right Rotation
                        r->right = RotateRight(r->right);
                    // Left Rotation
                    r = RotateLeft(r);
                }
                return r;
                
            }
        }
        void PreOrderTraverse(Node *r)
        {
            if (r == NULL)
                return;
            cout <<"Element : "<< r->data << " with height of : " << r->height << "\t" << endl;
            PreOrderTraverse(r->left);
            PreOrderTraverse(r->right);
        }
        void InOrderTraverse(Node *r)
        {
            if (r == NULL)
                return;
            InOrderTraverse(r->left);
             cout <<"Element : "<< r->data << " with height of : " << r->height << "\t" << endl;
            InOrderTraverse(r->right);
        }
        void PostOrderTraverse(Node *r)
        {
            if (r == NULL)
                return;
            PostOrderTraverse(r->left);
            PostOrderTraverse(r->right);
            cout <<"Element : "<< r->data << " with height of : " << r->height << "\t" << endl;
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
        

public:
    AVLTree()
    {
        root = NULL;
    }
    void InsertData(int item)
    {
        root = InsertData(root, item);
    }
    void DeleteItem(int item)
    {
        root = DeleteItem(root,item);
    }
    void PreOrderTraverse(){
        PreOrderTraverse(root);
    }
    void PostOrderTraverse(){
        PostOrderTraverse(root);
    }
    void InOrderTraverse(){
        InOrderTraverse(root);
    }
    void BreadthFisrtTraverse()
    {
        queue<Node*> Queue ;
        Node* temp = root;
        Queue.push(temp);
        while(!Queue.empty())
        {
            temp = Queue.front();
            if(temp->left!=NULL)
                Queue.push(temp->left);
            if(temp->right!=NULL)
                Queue.push(temp->right);
            cout<<temp->data<<"\t";
            Queue.pop();
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

};