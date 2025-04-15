#pragma once
#include<iostream>
#include<string>
using namespace std;

// types: integer, Add, eof

class token{


    public:


        token(string Type, int Value){
            type = Type;
            value = Value;
        }






    private:
        string type;
        int value;


};