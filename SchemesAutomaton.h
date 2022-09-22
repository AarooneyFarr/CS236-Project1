//
// Created by TheAa on 9/21/2022.
//

#ifndef SCHEMESAUTOMATON_H
#define SCHEMESAUTOMATON_H

#include "Automaton.h"

class SchemesAutomaton : public Automaton{
public:
    SchemesAutomaton() : Automaton(TokenType:: SCHEMESs) {}

    void S0(const std::string& input);
};

#endif //SCHEMESAUTOMATON_H
