//
// Created by TheAa on 10/4/2022.
//

#ifndef DATALOGPROGRAM_H
#define DATALOGPROGRAM_H
#include "Parameter.h"
#include "Predicate.h"
#include "Rule.h"
#include <vector>
#include <set>
#include <string>


class DatalogProgram{
private:
    std::vector<Predicate*> schemes;
    std::vector<Predicate*> facts;
    std::vector<Predicate*> queries;
    std::vector<Rule*> rules;
    std::set<std::string> domains;

public:
    DatalogProgram();

    DatalogProgram(std::vector<Predicate*> schemes, std::vector<Predicate*> facts, std::vector<Rule*> rules, std::vector<Predicate*> queries, std::set<std::string> domains){
        this->schemes = schemes;
        this->facts = facts;
        this->rules = rules;
        this->queries = queries;
        this->domains = domains;
    }


    std::string toString();

};

#endif //DATALOGPROGRAM_H
