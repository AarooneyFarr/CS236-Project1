//
// Created by TheAa on 9/21/2022.
//

#ifndef RIGHTPARENAUTOMATON_H
#define RIGHTPARENAUTOMATON_H

#include "Automaton.h"

class RightParenAutomaton : public Automaton{
public:
    RightParenAutomaton() : Automaton(TokenType:: RIGHT_PAREN) {}

    void S0(const std::string& input);
};

#endif //RIGHTPARENAUTOMATON_H
