//
// Created by TheAa on 9/21/2022.
//

#ifndef QUERIESAUTOMATON_H
#define QUERIESAUTOMATON_H

#include "Automaton.h"

class QueriesAutomaton : public Automaton{
public:
    QueriesAutomaton() : Automaton(TokenType:: QUERIES) {}

    void S0(const std::string& input);
};

#endif //QUERIESAUTOMATON_H
