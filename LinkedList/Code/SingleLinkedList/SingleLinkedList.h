
#include <iostream>
#include "Node.h"
using namespace std;


class SingleLinkedList{
    private :
        Node* head ;
    
    public : 
        SingleLinkedList(){
            head = NULL;
            
        }
        bool isEmpty(){
            return (head==NULL);
        }
        void InsertAtFirst(int element){
            Node* newNode = new Node;
            newNode->next = head;
            newNode->data = element;
            head = newNode;
            
        }
        void InsertAtLast(int element){
            if(isEmpty()){
                InsertAtFirst(element);
            }else{
                Node* newNode = new Node;
                newNode -> next = NULL;
                newNode -> data = element;
                Node* temp = head ;
                while(temp->next != NULL){
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
                head = head ->next ;
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
                    while(temp -> next -> next != NULL ){
                        temp = temp -> next;
                    }
                    dltptr = temp -> next;
                    temp -> next = NULL;
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
                while(temp  != NULL){
                    cout<<"Element "<<c++<<" : "<<temp->data<<endl;
                    temp = temp -> next;
                }
            }
            cout<<"-=-=-=-=-=-=-=-=--=-=-=-=-=-\n";
        }
        int Count(){
            int count = 0;
            if(!isEmpty()){
                Node* temp = head;
                
                while(temp  != NULL){
                    count++;
                    temp = temp -> next;
                }
            }
            return count;
        }
        bool Search(int item){
            
            if(!isEmpty()){
                Node* temp = head;
                
                while(temp  != NULL){
                    if (temp->data == item){
                        return 1; 
                    }
                    temp = temp -> next;
                }
            }
            return 0;
        }
        void Revrse(){
            if(isEmpty()){
                cout<<"Empty List !!\n";
            }else if(Count() ==1 ){
                cout<<"Single Element In List !!\n";
            }else{
                Node* prev = NULL ;
                Node* current = head ;
                Node* temp = NULL;
                while(current!=NULL){
                    temp = current -> next;
                    current -> next = prev;
                    prev = current ;
                    current = temp;
                }
                head = prev;
            }
        }
};