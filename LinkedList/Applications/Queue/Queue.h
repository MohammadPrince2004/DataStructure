#include <iostream>
#include "Node.h"
using namespace std;
class Queue{
    private :
        Node* front;
        Node* rear ;
    public : 
        Queue(){
            front = NULL;
            rear = NULL;    
        }
        bool isEmpty(){
            return (front == NULL);
        }
        void Enqueue(int element){
            Node* newNode = new Node;
            newNode -> data = element;
            newNode -> next = NULL;
            if(isEmpty()){
                front = newNode;
            }else{
                rear -> next = newNode ; 
            }
            rear = newNode;
        }
        void Dequeue(){
            if(!isEmpty()){
                Node* dltptr = front;
                front =  front -> next;
                if(front == NULL)
                    rear = NULL;
                delete dltptr;
            }else{
                cout<<"Empty Queue !!\n";
            }
        }
        void Show(){
            cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
            if(!isEmpty()){
                    Node* temp = front;
                    int c = 0;
                    while(temp != NULL){
                        cout<<"Element "<<c++<<" : "<<temp->data<<endl;
                        temp = temp->next;
                    }
            }else{
                cout<<"Empty Queue !! \n";
            }
            cout<<"=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
        }
        int getFront(){
            if(isEmpty())
                return -1;
            
            return (front -> data);
        }
        int getRear(){
            if(isEmpty())
                return -1;
            
            return (rear -> data);
        }
};