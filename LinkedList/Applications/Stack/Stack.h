#ifndef SRC
#include <iostream>
#include "Node.h"
using namespace std;
#endif
class Stack{
    private :
        Node* top ; 
        int length;
    public : 
        Stack(){
            top = NULL;
            length = 0;
        }
        bool isEmpty(){
            return (top==NULL);
        }
        void Push(int elment){
            Node* newNode = new Node;
            newNode -> data = elment;
            newNode -> next = top;
            top = newNode;
            length ++;
        }
        void Pop(){
            if(!isEmpty()){
                Node* dltptr = top;
                top = top -> next;
                delete dltptr;
            }else{
                cout<<"Empty Stack !!\n";
            }
        }
        int getTopVal(){
            if(!isEmpty()){
                return (top->data);
            }else{
                cout<<"Empty Stack !!\n";
            }
        }
        void Show(){
            cout<<"=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-\n";
            if(!isEmpty()){
                Node* temp = top;
                int c = 0;
                while(temp!=NULL){
                    cout<<"Element "<<length-1-c++<<" : "<<temp->data<<endl;
                    temp = temp -> next;
                }
            }else{
                cout<<"Empty Stack !!\n";
            }
            cout<<"=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-\n";
        }

};