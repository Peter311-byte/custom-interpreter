#include<iostream>
#include "token.h"
#include<string>

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

            if (ptr>(text.length()-1)){
                token t3 = token("EOF", 0);
                return t3;
            }

            for(int i{0}; i<text.length();i++){
                if(text[i] == ' '){
                    text.erase(i,1);
                }
            }

           char current_char = text[ptr];

           if(isdigit(current_char) && isdigit(text[ptr+1])){
                string myString1;
                myString1 = string(1,current_char) + string(1,text[ptr+1]); 
                int z = stoi(myString1);
                token t4 = token("INT", z);
                ptr+=2;
                return t4;

           }

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

           if(current_char == '-'){
                token t5 = token("SUB",0);
                ptr+=1;
                return t5;
           }

           if(current_char == '*'){
                token t6 = token("MULTI",1);
                ptr+=1;
                return t6;
           }

           if(current_char == '/'){
                token t7 = token("DIV",1);
                ptr+=1;
                return t7;
           }

    }

    void eat(string Type, token &current_token){

        string type = current_token.getType();

        if(type == Type){
            current_token = lex();
        }
    }

    

    int factor(token& Token){
            int var = Token.value;
            eat("INT",Token);
            return var;
    }

    int term(token& currentToken){
        int Term = factor(currentToken);
            while(currentToken.type == "MULTI" || currentToken.type == "DIV"){
                if(currentToken.type == "MULTI"){
                    eat("MULTI",currentToken);
                    Term = Term * factor(currentToken);
                }else if (currentToken.type == "DIV"){
                    eat("DIV",currentToken);
                    Term = Term / factor(currentToken);
                }
            }
           
            return Term;
    }


    int expr(){
       
        token current_token = lex();
       int result = term(current_token);

        while(current_token.type == "ADD" || current_token.type == "SUB"){
            if(current_token.type == "ADD"){
                eat("ADD",current_token);
                result = result + term(current_token);
            }else if(current_token.type == "SUB"){
                eat("SUB", current_token);
                result = result - term(current_token);
            }
        }

        return result;
        

       
    }




    

    


        


};