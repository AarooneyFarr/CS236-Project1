//
// Created by TheAa on 9/21/2022.
//

#include "CommentAutomaton.h"

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
    if (input[index] == EOF ) {
        inputRead++;
        index++;
        S2(input);
    }
    else if(input[index] == '\n'){
        //inputRead++;
        
        //newLines++;
        S2(input);
    }
    else if(input[index] == '|' && index == 1){
        Serr();
    }
    else{
        inputRead++;
        index++;
        S1(input);
    }


}

void CommentAutomaton::S2(const std::string& input) {



}