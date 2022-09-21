//
// Created by TheAa on 9/21/2022.
//

#ifndef COMMAAUTOMATON_H
#define COMMAAUTOMATON_H

#include "Automaton.h"

class CommaAutomaton : public Automaton{
public:
    CommaAutomaton() : Automaton(TokenType:: COMMA) {}

    void S0(const std::string& input);
};

#endif // COMMAAUTOMATON_H
