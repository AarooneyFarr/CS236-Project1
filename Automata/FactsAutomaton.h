//
// Created by TheAa on 9/21/2022.
//

#ifndef FACTSAUTOMATON_H
#define FACTSAUTOMATON_H

#include "Automaton.h"

class FactsAutomaton : public Automaton{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);


public:
    FactsAutomaton() : Automaton(TokenType:: FACTS) {}

    void S0(const std::string& input);
};

#endif //FACTSAUTOMATON_H
