//
// Created by TheAa on 9/22/2022.
//

#include "MultilineAutomaton.h"

void MultilineAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void MultilineAutomaton::S1(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void MultilineAutomaton::S2(const std::string& input) {
    //char tester = input[index];
    if (isalnum(input[index]) || isspace(input[index])) {
        if(input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
    else if(input[index] == '\0'){
        Serr();
    }
    else if(input[index] == '|'){
        inputRead++;
        index++;
        S3(input);

    }
    else{
        if(input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }


}

void MultilineAutomaton::S3(const std::string& input) {
    //char tester2 = input[index];
    if (input[index] == '#') {
        inputRead++;
        //index++;
        //S2(input);
    }
    else if (input[index] == '\0') {
        Serr();
    }
    else{
        if(input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
}