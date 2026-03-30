
#include <iostream>
#define size 100
using namespace std;
class Stack{
    private : 
        int top ;
        char data[size];
       
        bool isFull(){
            if(top == size - 1 )
                return 1;
            return 0;
        }
    public : 
        bool isEmpty(){
            return (top==-1);
        }
        Stack(){
            top = -1;
        }
        void push(int element){
            if(isFull()){
                cout<<"isFull Stack !!\n";
            }else{
                top++;
                data[top] = element;
            }

        }
        void pop(){
            if(isEmpty()){
                cout<<"isEmpty Stack !!\n";
            }else{
                top--;
            }
        }
        char viewTopVal(){
            if(isEmpty()){
                cout<<"No Top Val !!\n";
                return -1;
            }
            cout<<data[top]<<"\n";
            return data[top];
        }
        void show(){
            for(int i = top ;i>=0;i--){
                cout<<data[i]<<endl;
            }
        }
        
};
