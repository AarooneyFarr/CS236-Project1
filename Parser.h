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
    int currToken = 0;

    void match(TokenType matchTokenType);

public:


    void Parse();
    DatalogProgram parse();

    void parseDatalogProgram();

    void parseSchemeList();
    void parseFactList();
    void parseRuleList();
    void parseQueryList();

    void parseScheme();
    void parseFact();
    void parseRule();
    void parseQuery();

    void parseHeadPredicate();
    void parsePredicate();

    void parsePredicateList();
    void parseParameterList();
    void parseStringList();
    void parseIdList();
    void parseParameter();

};
#endif //PARSER_H
