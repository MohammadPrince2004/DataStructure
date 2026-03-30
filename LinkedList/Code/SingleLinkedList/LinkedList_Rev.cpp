#include <iostream>
#define SIZE 5
using namespace std;
class Stack{
    private :
        int top ;
        float data[SIZE];
    public : 
        Stack(){
            top = -1;
        }
        bool isEmpty(){
            return (top==-1);
        }
        bool isFull(){
            return (top==SIZE-1);
        }
        void Push(float element){
            if(isFull()){
               cout<<"Full Stack !!\n"; 
            }else{
                data[++top]=element;
            }
        }
        void Pop(){
            if(isEmpty()){
                cout<<"Empty Stack !!";
            }else{
                top--;
            }
        }
        float getTopVal(){
            if(isEmpty()){
                cout<<"Empty Stack !!";
                return -1;
            }else{
                return data[top];
            }
        }
        void Show(){
            cout<<"-===-=-=-=-=-=-=-==-=-=\n";
            for(int i=top;i>=0;i--){
                cout<<"Elemnet "<<i<<" : "<<data[i]<<endl;
            }
            cout<<"-===-=-=-=-=-=-=-==-=-=\n";
        }
};
bool Parity(char open,char closed){
    if((open=='(')&&(closed==')'))
        return 1;
    if((open=='{')&&(closed=='}'))
        return 1;
    if((open=='[')&&(closed==']'))
        return 1;
    return 0;
}
bool checkBalancedBrackets(string Exp){
    Stack openBrackets;
    for(int i =0;i<Exp.length();i++){
        if((Exp[i]=='(')||(Exp[i]=='{')||(Exp[i]=='[')){
            openBrackets.Push(Exp[i]);
        }else if ((Exp[i]==')')||(Exp[i]==']')||(Exp[i]=='}')){
            if(openBrackets.isEmpty()){
                return 0;
            }else{
                if(Parity(openBrackets.getTopVal(),Exp[i])){
                    openBrackets.Pop();
                }else{
                    return 0;
                }
            }
        }
    }
    if(openBrackets.isEmpty()){
        return 1;
    }
    return 0;
}
int Periority(char op){
    if((op=='*')||(op=='/')){
        return 2;
    }else if((op=='+')||(op=='-')){
        return 1;
    }
    return 0;
}
string infixToPost(string Exp){
    string output = "";
    Stack brackets_op;
    if(checkBalancedBrackets(Exp)){
        for(int i=0;i<Exp.length();i++){
            if(Exp[i]=='('){
                brackets_op.Push(Exp[i]);
            }else if(isalnum(Exp[i])){
                output+=Exp[i];
            }else if((Exp[i]=='+')||(Exp[i]=='-')||(Exp[i]=='/')||(Exp[i]=='*')){
                if(!brackets_op.isEmpty()){
                    if(Periority(Exp[i])<=Periority(brackets_op.getTopVal())){
                        while(Periority(Exp[i])<=Periority(brackets_op.getTopVal())){
                            output+=brackets_op.getTopVal();
                            brackets_op.Pop();
                        }
                    }
                }
                brackets_op.Push(Exp[i]);
            }else if(Exp[i]==')'){
                while(brackets_op.getTopVal()!='('){
                    output+=brackets_op.getTopVal();
                    brackets_op.Pop();
                }
                brackets_op.Pop();
            }
        }
        while(!brackets_op.isEmpty()){
            output+=brackets_op.getTopVal();
            brackets_op.Pop();
        }
    }else{
        output="";
    }
    return output;      
}
float calc(int op1,char op,int op2){
    if(op=='+')
        return op1+op2;
    else if(op=='-')
        return op1-op2;
    else if(op=='*')
        return op1*op2;
    else if(op=='/')
        return op1/op2;
}
float calc_post(string postFix){
    char op;
    float op1;
    float op2;
    Stack numbers;
    for(int i=0;i<postFix.length();i++){
        if(isdigit(postFix[i])){
            numbers.Push(postFix[i]-'0');
        }
        else if((postFix[i]=='-')||(postFix[i]=='+')||(postFix[i]=='/')||(postFix[i]=='*')){
            op = postFix[i];
            op2 =  numbers.getTopVal();
            numbers.Pop();
            op1 =  numbers.getTopVal();
            numbers.Pop();
            numbers.Push(calc(op1,op,op2));
        }
    }
    return numbers.getTopVal();
}
class CirQueue{
    private:
        int front;
        int rear;
        int data[SIZE] ;
    public:
        CirQueue(){
            front = -1;
            rear = -1;
        }
        bool isEmpty(){
            return (front==-1);
        }
        bool isFull(){
            return (front==(rear+1)%SIZE);
        }
        void Enqueue(int element){
            if(isFull()){
                cout<<"FullQueue !!\n";
            }else{
                if(isEmpty()){
                    front=0;
                }           
                rear=(rear+1)%SIZE;
                data[rear]=element;

            }
            
            
        }
        void Dequeue(){
            if(isEmpty()){
                cout<<"is Empty !!\n";
            }else{
                front=(front+1)%SIZE;  
            }

        }
        void Show(){
            int c=front;
            while(c!=rear){
                cout<<data[c]<<endl;
                c=(c+1)%SIZE;
            }
            cout<<data[c];
        }
        
};

int main() {
    CirQueue cq;

    cq.Enqueue(10);
    cq.Enqueue(20);
    cq.Enqueue(30);
    cq.Enqueue(40);
    cq.Enqueue(50); // الآن الطابور ممتلئ
    cq.Show();

    cq.Dequeue(); // حذف 10 (الآن المكان index 0 أصبح فارغاً)
    cq.Dequeue(); // حذف 20 (الآن المكان index 1 أصبح فارغاً)

    cout << "After 2 Dequeues:\n";
    cq.Show();

    // هنا تظهر قوة الـ Circular Queue
    cq.Enqueue(60); // سيتم وضعها في index 0 الذي فرغ سابقاً
    cq.Enqueue(70); // سيتم وضعها في index 1
    cq.Show();

    return 0;
}