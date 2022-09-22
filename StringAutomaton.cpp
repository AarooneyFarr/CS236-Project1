//
// Created by TheAa on 9/21/2022.
//

#include "StringAutomaton.h"

void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    //char tester = input[index];
    //bool test = isspace(tester);
    //bool test2 = (isspace(input[index]) && input[index] != '\n');
    //bool test3 = (input[index] != '\n');
    if (isalnum(input[index]) || (isspace(input[index]) && input[index] != '\n')) {
        inputRead++;
        index++;
        S1(input);
    }
    else if(input[index] == '\n'){
        newLines++;
        inputRead++;
        index++;
        S1(input);
    }
    else if(input[index] == '\''){
        inputRead++;
        index++;
        S2(input);
    }
    else{
        this->type = TokenType::UNDEFINED;
    }


}

void StringAutomaton::S2(const std::string& input) {
    if (isalnum(input[index])) {
        Serr();
    }
    else if(input[index] == '\''){
        inputRead++;
        index++;
        S1(input);
    }
    else if (input[index] == EOF){
        this->type = TokenType::UNDEFINED;
    }

}