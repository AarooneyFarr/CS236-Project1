//
// Created by TheAa on 9/21/2022.
//

#ifndef RULESAUTOMATON_H
#define RULESAUTOMATON_H

#include "Automaton.h"

class RulesAutomaton : public Automaton{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);

public:
    RulesAutomaton() : Automaton(TokenType:: RULES) {}

    void S0(const std::string& input);
};

#endif //RULESAUTOMATON_H
