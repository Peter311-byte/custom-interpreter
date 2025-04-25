#pragma once
#include<iostream>
#include<string>
using namespace std;

// types: integer, Add, eof

class token{


    public:


    string type;
    int value;

        token(string Type, int Value){
            type = Type;
            value = Value;
        }


        string getType(){

            return type;
        }

        int getValue(){

            return value;
        }

        void operator=(const token& rhs){
            type = rhs.type;
            value = rhs.value;

        }

        





};