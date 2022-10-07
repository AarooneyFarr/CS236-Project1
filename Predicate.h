//
// Created by TheAa on 10/5/2022.
//

#ifndef PREDICATE_H
#define PREDICATE_H
#include <string>
#include <vector>
#include "Parameter.h"

class Predicate{
private:
    std::string id;
    std::vector<Parameter*> params;

public:
   // Predicate();

    std::string toString();
    void addParam(Parameter* param);
    void addId(std::string idString);
};

#endif //PREDICATE_H
