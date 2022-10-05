//
// Created by TheAa on 10/4/2022.
//

#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include "Token.h"
#include "DatalogProgram.h"


class Parser {
private:
    DatalogProgram program;
    std::vector<Token*> tokens;

public:
    void Parse();
    DatalogProgram parse();


};
#endif //PARSER_H
