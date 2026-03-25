#include <iostream>
#define SIZE 5
using namespace std;
class CircularQueue{
    private:
        int front;
        int rear ;
        int length;
        int data[SIZE];
    public:
        CircularQueue(){
            front = -1;
            rear = -1;
            length = 0;
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
                rear=(rear+1)%SIZE;
                data[rear] = element;
            }
        }
        void dequeue(){
            if(isEmpty()){
                cout<<"isEmpty !!"<<endl;
            }else{
                front=(front+1)%SIZE;
                length--;
                if(length==0){
                    front=-1;
                    rear=-1;
                }
            }
        }
        void show(){
            cout<<"=-=-=-=-=-=-=-=-=-=-=-=\n";
            int c = front;
            while(c!=rear){
                cout<<data[c]<<endl;
                c=(c+1)%SIZE;
            }
            cout<<data[rear]<<endl;
        }

};