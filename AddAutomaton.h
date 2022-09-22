//
// Created by TheAa on 9/21/2022.
//

#ifndef ADDAUTOMATON_H
#define ADDAUTOMATON_H

#include "Automaton.h"

class AddAutomaton : public Automaton{
public:
    AddAutomaton() : Automaton(TokenType:: ADD) {}

    void S0(const std::string& input);
};

#endif //ADDAUTOMATON_H
