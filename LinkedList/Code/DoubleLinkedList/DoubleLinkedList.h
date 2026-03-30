#include <iostream>
using namespace std;
#include "Node.h"
class DoubleLinkedList{
    private:
        Node* head;
        Node* teal;
    public:
        DoubleLinkedList(){
            head = NULL;
            teal = NULL;
        }
        bool isEmpty(){
            return (head == NULL);
        }
        void InsertAtFirst(int element){
            
            Node* newNode = new Node;
            newNode -> data = element;
            newNode -> prev = NULL ; 
            newNode -> next = head;
            if(isEmpty()){
                teal = newNode;
            }else{
                head -> prev = newNode;
            }
            head = newNode;
        }
        void InsertAtLast(int element){
            if(isEmpty()){
                InsertAtFirst(element);
            }else{
                Node* newNode = new Node;
                newNode -> data = element;
                teal -> next = newNode;
                newNode -> prev = teal ; 
                teal = newNode;
            }
        }
        void InsertAtAnyPos(int element, int index){
            if(isEmpty()||(index==0)){
                InsertAtFirst(element);
            }else if(index == Count()){
                InsertAtLast(element);
            }else{
                Node* newNode = new Node;
                newNode -> data = element;
                Node* temp1 = head;
                Node* temp2 = NULL;
               
                int c = 0;
                while(c<index-1){
                    c++;
                    temp1 = temp1 -> next;
                }
                temp2 = temp1 -> next;
                newNode -> next = temp2;
                newNode -> prev = temp1;
                temp2 -> prev = newNode;
                temp1 -> next = newNode;
            }
        }
        void deleteAtFirst(){
            if(isEmpty()){
                cout<<"Empty List !!\n";
            }else{
                Node* dltptr = head ;
                if(Count()==1){
                    head = NULL;
                    teal = NULL;
                }else{
                    head -> next -> prev = NULL;
                    head = head -> next;
                }
                delete dltptr; 
            }
        }
        void delteAtLast(){
            if(isEmpty()){
                cout<<"Empty List !!\n";
            }else{
                if(Count()==1){
                    deleteAtFirst();
                }else{
                    Node* dltptr = teal ;
                    teal -> prev -> next = NULL;
                    teal = dltptr -> prev;
                    delete dltptr; 
                }
            }
        }
        void delteAtAnyPos(int index){
            if(isEmpty()||(index==0)){
                deleteAtFirst();
            }else if(index == Count()){
                delteAtLast();
            }else{
             
                Node* temp1 = NULL;
                Node* dltptr = head;
                Node* temp2 = NULL;
               
                int c = 0;
                while(c<index){
                    c++;
                    dltptr = dltptr -> next;
                }
                temp1 = dltptr ->prev;
                temp2 = dltptr ->next;
                temp1->next = temp2;
                temp2->prev = temp1;
                delete dltptr; 
            }
        }
       
        int Count(){
            int c = 0;
            Node* temp = head;
            while (temp!=NULL){
                c++;
                temp = temp->next;
            }
            return c;
        }
        
        void Show(){
            cout<<"=-=-=-=-=-=-=-=-=-=-=-=--=\n";
            if(!isEmpty()){
                Node* temp = head;
                int c = 0;
                while(temp!=NULL){
                    cout<<"Element "<<c<<" : "<<temp->data<<endl;
                    temp = temp -> next;
                    c++;
                }
            }else{
                cout<<"Empty List !!\n";
            }
            cout<<"=-=-=-=-=-=-=-=-=-=-=-=--=\n";
        }
        void ShowReverse(){
            cout<<"=-=-=-=-=-=-=-=-=-=-=-=--=\n";
            if(!isEmpty()){
                Node* temp = teal;
                int c = 0;
                while(temp!=NULL){
                    cout<<"Element "<<Count()-1-c<<" : "<<temp->data<<endl;
                    temp = temp -> prev;
                    c++;
                }
            }else{
                cout<<"Empty List !!\n";
            }
            cout<<"=-=-=-=-=-=-=-=-=-=-=-=--=\n";
        }

};