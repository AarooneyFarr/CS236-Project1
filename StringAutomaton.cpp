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
    if (isalnum(input[index])) {
        inputRead++;
        index++;
        S1(input);
    }
    else if(input[index] == '\''){
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }

}

void StringAutomaton::S2(const std::string& input) {
    if (isalnum(input[index]) || input[index] == EOF) {
        Serr();
    }
    else if(input[index] == '\''){
        inputRead++;
        index++;
        S1(input);
    }

}