#include <string>
#include "Stack.h"
string decimalToBin(float num){
    int digitPart = num;
    float floatPart = num- digitPart;
    
    Stack binaryDigits;
    string digitResult="";
    string floatResult="";
    while(digitPart!=0){
        binaryDigits.push((digitPart%2)+'0');
        digitPart=digitPart/2;
    }
    while(!binaryDigits.isEmpty()){
        digitResult+=binaryDigits.viewTopVal();
        binaryDigits.pop();
    }
    digitResult+='.';
    while(floatPart!=0){
        binaryDigits.push(int(floatPart*2)+'0');
        floatPart=(floatPart*2>=1)?floatPart*2-1:floatPart*2;
    }
    while(!binaryDigits.isEmpty()){
        floatResult=binaryDigits.viewTopVal()+floatResult;
        binaryDigits.pop();
    }
    digitResult=digitResult+floatResult;
    cout<<digitResult;
}