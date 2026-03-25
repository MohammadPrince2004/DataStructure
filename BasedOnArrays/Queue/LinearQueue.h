#include <iostream>
#define SIZE 5
using namespace std;
class Queue{
    private:
        int front;
        int rear ;
        int length;
        int data[SIZE];
    public:
        Queue(){
            front = -1;
            rear = -1;
            length=0;
        }
        bool isEmpty(){
            return (length==0);
        }
        bool isFull(){
            return (length==SIZE);
        }
        void enqueue(int element){
            if(isFull()){
                cout<<"Full Queue !!"<<endl;
            }else{
                if(isEmpty()){
                    front = 0;
                }
                length++;
                rear++;
                data[rear] = element;
            }
        }
        void dequeue(){
            if(isEmpty()){
                cout<<"isEmpty !!"<<endl;
            }else{
                front++;
                length--;
                if(length==0){
                    front=-1;
                    rear=-1;
                }
            }
        }
        void show(){
            cout<<"=-=-=-=-=-=-=-=-=-=-=-=\n";
            for(int i=front;i<=rear;i++){
                cout<<data[i]<<endl;
            }
        }

};