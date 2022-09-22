//
// Created by TheAa on 9/21/2022.
//

#ifndef COMMENTAUTOMATON_H
#define COMMENTAUTOMATON_H

#include "Automaton.h"

class CommentAutomaton : public Automaton{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);


public:
    CommentAutomaton() : Automaton(TokenType:: COMMENT) {}

    void S0(const std::string& input);
};

#endif //COMMENTAUTOMATON_H
