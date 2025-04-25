#include<iostream>
#include "token.h"
#include<string>
#include<vector>

using namespace std;
class interpreter{


    public:

    string text;
    int ptr{0};
    token current_token = token("ADD", 0);


    interpreter(string Text){
        text = Text;
    }



    token lex(){


        if(text.length()>3){
            cerr<<"Invalid input!"<<endl;
        }

            if (ptr>(text.length()-1)){
                token t3 = token("EOF", 0);
                return t3;
            }

           char current_char = text[ptr];

           if(isdigit(current_char)){

                int r = current_char - '0';
                token t1 = token("INT",r);
                ptr += 1;
                return t1;
           }

           if(current_char == '+'){
                token t2 = token("ADD", 0);
                ptr+=1;
                return t2;
           }

    }

    void eat(string Type, token &current_token){

        string type = current_token.getType();

        if(type == Type){
            current_token = lex();
        }
    }


    int expr(){

        token current_token = lex();

        token left = current_token;
        eat("INT", current_token);

        token mid = current_token;
        eat("ADD", current_token);

        token right = current_token;
        eat("INT", current_token);


        int result = left.getValue()+ right.getValue();

        return result;


    }




    

    


        


};