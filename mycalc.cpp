#include<iostream>
#include "token.h"
#include "interpreter.h"
#include<string>


int main(){
    string text;

    cout<<"calc>>";
    getline(cin,text);
    interpreter i1 = interpreter(text);

    cout<<i1.text<<std::endl;
    
}