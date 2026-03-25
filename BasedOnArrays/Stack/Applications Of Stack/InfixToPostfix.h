#include <string>
#include "Stack.h"
#include "BracketsCheck.h"
using namespace std;
int Piriority(char op){
    if((op=='+')||(op=='-'))
        return 1;
    else if((op=='*')||(op=='/'))
        return 2;
    else if (op=='^')
        return 3;
    else 
        return 0;
}
string infixtopostfix(string exp){
    string output = ""; 
    Stack operations;
    if(checkBrackets(exp)){
        for(int i = 0;i<exp.length();i++){
            if((exp[i]=='(')){
                operations.push(exp[i]);
            }else if(isalnum(exp[i])){
                output+=exp[i];
            }else if((exp[i]=='+')||(exp[i]=='-')||(exp[i]=='*')||(exp[i]=='/')||(exp[i]=='^')){
                if(!operations.isEmpty()){
                    if(Piriority(operations.viewTopVal())<Piriority(exp[i])){
                        operations.push(exp[i]);
                    }else{
                        while((Piriority(operations.viewTopVal())>=Piriority(exp[i]))&&(!operations.isEmpty())){
                            output+=operations.viewTopVal();
                            operations.pop();
                        }
                        operations.push(exp[i]);
                    }
                }else{
                    operations.push(exp[i]);
                }
            }else if((exp[i]==')')){
                while(operations.viewTopVal()!='('){
                    output+=operations.viewTopVal();
                    operations.pop();
                }
                operations.pop();
            }
        
        
        }
        while(!operations.isEmpty()){
            output+=operations.viewTopVal();
            operations.pop();
        }
        return output;
    }
    cout<<"Not Balanced Expression !!";
    return "";
    
}
