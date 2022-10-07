//
// Created by TheAa on 10/5/2022.
//

#include "Rule.h"

Rule::Rule(){

}

std::string Rule::toString() {

    std::string predString = "";

    for(Predicate* pred : this->predicates){
        if(this->predicates.back() == pred){
            predString += pred->toString();
        }
        else{
            predString += pred->toString() + ",";
        }

    }

    std::string ruleString = this->headPredicate->toString() + " :- " + predString;

    return ruleString;
}

void Rule::setHeadPredicate(Predicate* headPredicate) {
    this->headPredicate = headPredicate;
}

void Rule::addPredicate(Predicate* predicate) {
    this->predicates.push_back(predicate);
}

