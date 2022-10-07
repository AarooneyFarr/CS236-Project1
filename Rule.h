//
// Created by TheAa on 10/5/2022.
//

#ifndef RULE_H
#define RULE_H
#include <string>
#include <vector>
#include "Predicate.h"

class Rule{
private:
    Predicate* headPredicate;
    std::vector<Predicate*> predicates;


public:
    Rule();

    std::string toString();
    void setHeadPredicate(Predicate* headPredicate);
    void addPredicate(Predicate* predicate);


};

#endif //RULE_H
