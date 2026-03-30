
#include <iostream>
#include "Node.h"
using namespace std;


class CircularLinkedList{
    private :
        Node* head ;
    
    public : 
        CircularLinkedList(){
            head = NULL;
            
        }
        bool isEmpty(){
            return (head==NULL);
        }
        void InsertAtFirst(int element){
            Node* newNode = new Node;
            newNode->data = element;
            if(isEmpty()){
                head = newNode;
                newNode->next = head;
            }else{
                newNode->next = head;
                Node* temp = head;
                while(temp->next!=head){
                    temp = temp->next;
                }
                head = newNode;
                temp -> next = head;
            }
        }
        void InsertAtLast(int element){
            if(isEmpty()){
                InsertAtFirst(element);
            }else{
                Node* newNode = new Node;
                newNode -> next = head;
                newNode -> data = element;
                Node* temp = head ;
                while(temp->next != head){
                    temp = temp->next;
                }
                temp -> next = newNode;
            }
        }
        void InsertAtAnyPos(int element , int index){
            if(isEmpty()||(index==0)){
                InsertAtFirst(element);
            }else if(index == Count()){
                InsertAtLast(element);
            }else{
                Node* newNode = new Node;
                int c = 0 ;
                Node* temp = head;
                while(c<index-1){
                    temp = temp->next;
                    c++;
                }
                newNode->data = element;
                newNode ->next = temp ->next;
                temp->next = newNode;

            }
        }
        void DeleteFirstNode(){
            if(!isEmpty()){
                Node* dltptr = head;
                if(Count()!=1){
                    Node* temp = head;
                    while(temp->next!=head){
                        temp = temp->next;
                    }
                    head = head ->next ;
                    temp->next = head;
                }else{
                    head = NULL;
                }
                delete dltptr;
            }else{
                cout<<"Empty List !!\n";
            }
            
        }
        void DeleteLastNode(){
            if(!isEmpty()){
                if(Count()==1){
                    DeleteFirstNode();
                }else{
                    Node* dltptr = NULL;
                    Node* temp = head;
                    while(temp -> next -> next != head ){
                        temp = temp -> next;
                    }
                    dltptr = temp -> next;
                    temp -> next = head;
                    delete dltptr;
                }
            }else{
                cout<<"Empty List !!\n";
            }
        }
        void DeleteAnyNode(int index){
            if(!isEmpty()){
                if((Count()==1)||(index ==0)){
                    DeleteFirstNode();
                }else if(index == Count()-1){
                    DeleteLastNode();
                }else{
                    int c = 0;
                    Node* temp = head;
                    Node* dlptr = NULL;
                    while(c<index-1){
                        temp = temp -> next;
                        c++;
                    }
                    dlptr = temp ->next;
                    temp -> next = dlptr -> next;
                    delete dlptr;
                }
            }else{
                cout<<"Empty List !!\n";
            }
        }
        void Show(){
            cout<<"-=-=-=-=-=-=-=-=--=-=-=-=-=-\n";
            if(isEmpty()){
                cout<<"Empty List !!\n";
            }else{
                Node* temp = head;
                int c = 0;
                while(temp->next  != head){
                    cout<<"Element "<<c++<<" : "<<temp->data<<endl;
                    temp = temp -> next;
                }
                cout<<"Element "<<c++<<" : "<<temp->data<<endl;
            }
            cout<<"-=-=-=-=-=-=-=-=--=-=-=-=-=-\n";
        }
        int Count(){
            int count = 0;
            if(!isEmpty()){
                Node* temp = head;
                
                while(temp->next  != head){
                    count++;
                    temp = temp -> next;
                }
                count++;
            }
            return count;
        }
     
       
};
