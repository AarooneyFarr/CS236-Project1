//
// Created by TheAa on 9/21/2022.
//

#ifndef IDAUTOMATON_H
#define IDAUTOMATON_H

#include "Automaton.h"

class IdAutomaton : public Automaton{
private:
    void S1(const std::string& input);


public:
    IdAutomaton() : Automaton(TokenType:: ID) {}

    void S0(const std::string& input);
};

#endif //IDAUTOMATON_H
