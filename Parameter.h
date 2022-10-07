//
// Created by TheAa on 10/5/2022.
//

#ifndef PARAMETER_H
#define PARAMETER_H
#include <string>

class Parameter{
private:
    std::string value;
public:
    Parameter() : Parameter(""){}

    Parameter(std::string value){
        this->value = value;
    }

    std::string toString();
    void setValue(std::string value);
};

#endif //PARAMETER_H
