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

    const std::vector<Predicate *> &getSchemes() const;

    const std::vector<Predicate *> &getFacts() const;

    const std::vector<Predicate *> &getQueries() const;

    const std::vector<Rule *> &getRules() const;

    const std::set<std::string> &getDomains() const;


    std::string toString();

};

#endif //DATALOGPROGRAM_H
