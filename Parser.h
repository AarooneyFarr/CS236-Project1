//
// Created by TheAa on 10/4/2022.
//

#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include <set>
#include "Token.h"
#include "DatalogProgram.h"
#include "Predicate.h"
#include "Rule.h"
#include "Parameter.h"


class Parser {
private:
    DatalogProgram* program;
    std::vector<Token*> tokens;
    int currToken = 0;
    std::set<std::string> domains;

    std::string match(TokenType matchTokenType);

public:
    Parser();
    ~Parser();

    //void parse(std::vector<Token*> tokens);
    DatalogProgram * parse(std::vector<Token*> tokens);

    DatalogProgram* parseDatalogProgram();

    void parseSchemeList(std::vector<Predicate *> & schemes);
    void parseFactList(std::vector<Predicate *> & facts);
    void parseRuleList(std::vector<Rule *> & rules);
    void parseQueryList(std::vector<Predicate *> & queries);

    Predicate* parseScheme();
    Predicate* parseFact();
    Rule* parseRule();
    Predicate* parseQuery();

    Predicate* parseHeadPredicate();
    Predicate* parsePredicate();

    void parsePredicateList(Rule* & rule);
    void parseParameterList(Predicate* & pred);
    void parseStringList(Predicate* & pred);
    void parseIdList(Predicate* & pred);
    void parseParameter(Predicate* & pred);

};
#endif //PARSER_H
