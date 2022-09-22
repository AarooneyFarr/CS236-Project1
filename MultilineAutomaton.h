//
// Created by TheAa on 9/22/2022.
//

#ifndef MULTILINEAUTOMATON_H
#define MULTILINEAUTOMATON_H

#include "Automaton.h"

class MultilineAutomaton : public Automaton{
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);
    void S5(const std::string& input);


public:
    MultilineAutomaton() : Automaton(TokenType:: COMMENT) {}

    void S0(const std::string& input);
};

#endif // MULTILINEAUTOMATON_H
