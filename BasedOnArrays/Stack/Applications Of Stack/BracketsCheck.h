#include <string>
#include "Stack.h"
bool Pair(char openbracket , char closedbracket){
    if((openbracket=='(')&&(closedbracket==')'))
        return 1;
    else if((openbracket=='[')&&(closedbracket==']'))
        return 1;
    else if((openbracket=='{')&&(closedbracket=='}'))
        return 1;
    return 0;
}
bool checkBrackets(string exp){
    Stack brackets;
    for(int i = 0;i<exp.length();i++){
        if((exp[i]=='[')||(exp[i]=='{')||(exp[i]=='(')){
            brackets.push(exp[i]);
        }else if((exp[i]==']')||(exp[i]=='}')||(exp[i]==')')){
            if(brackets.isEmpty()){
                return 0;
            }else{
                if(Pair(brackets.viewTopVal(),exp[i])){
                    brackets.pop();
                }else{
                    return 0;
                }
            }
        }
    }
   return (brackets.isEmpty());
}
