//
// Created by TheAa on 9/21/2022.
//

#ifndef RULESAUTOMATON_H
#define RULESAUTOMATON_H

#include "Automaton.h"

class RulesAutomaton : public Automaton{
public:
    RulesAutomaton() : Automaton(TokenType:: RULES) {}

    void S0(const std::string& input);
};

#endif //RULESAUTOMATON_H
