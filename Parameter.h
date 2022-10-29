//
// Created by TheAa on 10/5/2022.
//

#ifndef PARAMETER_H
#define PARAMETER_H
#include <string>

class Parameter{
private:
    std::string value;

    // 1 - string
    // 2 - ID
    int type;
public:
    Parameter() : Parameter(""){}

    Parameter(std::string value, int type = 0){
        this->value = value;
        this->type = type;
    }

    std::string toString();
    void setValue(std::string value);
    int getType() { return type; };
};

#endif //PARAMETER_H
