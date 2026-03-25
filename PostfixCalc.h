#include <string>
#include "Stack.h"
int Calc(int op1,int op2,char op){
    if(op=='+'){
        return op1+op2;
    }
    else if(op=='-'){
        return op1-op2;
    }
    else if(op=='*'){
        return op1*op2;
    }
    else if(op=='/'){
        return op1/op2;
    }
}
int Calculate(string exp){
    Stack operands;
    int result = 0;
    if(exp!=""){
        for(int i = 0 ;i<exp.length();i++ ){
            if(isdigit(exp[i])){
                operands.push(exp[i]-'0');
            }
            else if((exp[i]=='+')||(exp[i]=='-')||(exp[i]=='*')||(exp[i]=='/')){
                int op1 = operands.viewTopVal();
                operands.pop();
                int op2 = operands.viewTopVal();
                operands.pop();
                operands.push(Calc(op1,op2,exp[i]));
            }
        }
        result = operands.viewTopVal();
        return result;
    }else{
        return -1;
    }
    
}