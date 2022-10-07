//
// Created by TheAa on 10/4/2022.
//

#include "Parser.h"
#include <iostream>

Parser::Parser() {

}

DatalogProgram* Parser::parseDatalogProgram() {
    std::vector<Predicate*> schemes;
    std::vector<Predicate *> facts;
    std::vector<Rule *> rules;
    std::vector<Predicate *> queries;

    Predicate* scheme;

//    for(Token* token : tokens){
//        while(tokens[currToken]->getType() == TokenType::COMMENT){
//
//            tokens.erase(tokens.begin() + currToken);
//
//        }
//    }

    for(int i = tokens.size() - 1; i >= 0; i--) {
        if(tokens[currToken]->getType() == TokenType::COMMENT) {
            tokens.erase( tokens.begin() + i );
        }
    }


    match(TokenType::SCHEMES);
    match(TokenType::COLON);
    scheme = parseScheme();
    schemes.push_back(scheme);
    parseSchemeList(schemes);
    match(TokenType::FACTS);
    match(TokenType::COLON);
    parseFactList(facts);
    match(TokenType::RULES);
    match(TokenType::COLON);
    parseRuleList(rules);
    match(TokenType::QUERIES);
    match(TokenType::COLON);
    queries.push_back(parseQuery());
    parseQueryList(queries);
    match(TokenType::endOF);

    return new DatalogProgram(schemes, facts, rules, queries, this->domains);
}

//void Parser::parse(std::vector<Token*> tokens) {
//    try{
//        this->tokens = tokens;
//        parseDatalogProgram();
//        std::cout << "Success!" << std::endl;
//    }
//    catch (Token* t) {
//        std::cout << t->toString() << " caused an error!" << std::endl;
//    }
//}

DatalogProgram* Parser::parse(std::vector<Token*> tokens) {


    try{
        this->tokens = tokens;
        this->program = parseDatalogProgram();
        std::cout << "Success!" << std::endl;
        //std::string tester =  program->toString();

        return program;
    }
    catch (Token* t) {
        std::cout << "Failure!" << std::endl;
        std::cout << "  " << t->toString() << std::endl;
        std::string fail;
        throw fail;
    }

    return new DatalogProgram();
}

void Parser::parseSchemeList(std::vector<Predicate *>& schemes) {
    //Token* tester = tokens[currToken];

    if(tokens[currToken]->getTypeString() == "ID"){
        schemes.push_back(parseScheme());
        parseSchemeList(schemes);
    }
}

void Parser::parseFactList(std::vector<Predicate *> &facts) {
    if(tokens[currToken]->getTypeString() == "ID"){
        std::string test = tokens[currToken]->getDescription();
        facts.push_back(parseFact());
        parseFactList(facts);
    }
}

void Parser::parseRuleList(std::vector<Rule *> &rules) {
    //Token* tester = tokens[currToken];

    if(tokens[currToken]->getTypeString() == "ID"){
        rules.push_back(parseRule());

        parseRuleList(rules);
    }
}

void Parser::parseQueryList(std::vector<Predicate *> &queries) {
    if(tokens[currToken]->getTypeString() == "ID"){
        queries.push_back(parseQuery());
        parseQueryList(queries);
    }
}

Predicate* Parser::parseScheme() {
    Predicate* pred = new Predicate();



    pred->addId(match(TokenType::ID));
    match(TokenType::LEFT_PAREN);
    pred->addParam(new Parameter(match(TokenType::ID)));
    parseIdList(pred);
    match(TokenType::RIGHT_PAREN);

    //this->currToken--;

    return pred;
}

Predicate* Parser::parseFact() {
    Predicate* pred = new Predicate();



    pred->addId(match(TokenType::ID));
    match(TokenType::LEFT_PAREN);
    std::string domain = match(TokenType::STRING);
    this->domains.insert(domain);
    pred->addParam(new Parameter(domain));
    parseStringList(pred);
    match(TokenType::RIGHT_PAREN);
    match(TokenType::PERIOD);


    return pred;
}

Rule* Parser::parseRule() {
    Rule* rule = new Rule();



    rule->setHeadPredicate(parseHeadPredicate());
    match(TokenType::COLON_DASH);
    rule->addPredicate(parsePredicate());
    parsePredicateList(rule);
    match(TokenType::PERIOD);

    //Token* tester = tokens[currToken];
    //std::string who = rule->toString();

//    parseHeadPredicate();
//    match(TokenType::COLON_DASH);
//    parsePredicate();
//    parsePredicateList(rule);
//    match(TokenType::PERIOD);

    return rule;
}

Predicate* Parser::parseQuery() {
    Predicate* pred = parsePredicate();
    match(TokenType::Q_MARK);

    return pred;
}

Predicate* Parser::parseHeadPredicate() {
    Predicate* pred = new Predicate();

    pred->addId(match(TokenType::ID));
    match(TokenType::LEFT_PAREN);
    pred->addParam(new Parameter(match(TokenType::ID)));
    parseIdList(pred);
    match(TokenType::RIGHT_PAREN);

    return pred;
}

Predicate* Parser::parsePredicate() {
    Predicate* pred = new Predicate();

    pred->addId(match(TokenType::ID));
    match(TokenType::LEFT_PAREN);
    parseParameter(pred);
    parseParameterList(pred);
    match(TokenType::RIGHT_PAREN);

    return pred;
}

void Parser::parsePredicateList(Rule* &rule) {
    if(tokens[currToken]->getTypeString() == "COMMA"){
        match(TokenType::COMMA);
        rule->addPredicate(parsePredicate());
        parsePredicateList(rule);
    }
}

void Parser::parseParameterList(Predicate* &pred) {
    if(tokens[currToken]->getTypeString() == "COMMA"){
        match(TokenType::COMMA);
        parseParameter(pred);
        parseParameterList(pred);
    }
}

void Parser::parseStringList(Predicate* &pred) {
    if(tokens[currToken]->getTypeString() == "COMMA"){
        match(TokenType::COMMA);
        std::string domain = match(TokenType::STRING);
        this->domains.insert(domain);
        pred->addParam(new Parameter(domain));
        parseStringList(pred);
    }
}

void Parser::parseIdList(Predicate* &pred) {
    if(tokens[currToken]->getTypeString() == "COMMA"){
        match(TokenType::COMMA);
        pred->addParam(new Parameter(match(TokenType::ID)));
        parseIdList(pred);
    }
}

void Parser::parseParameter(Predicate* &pred) {

    if(tokens[currToken]->getTypeString() == "STRING"){
        pred->addParam(new Parameter(match(TokenType::STRING)));
    }
    else if(tokens[currToken]->getTypeString() == "ID")
    {
        pred->addParam(new Parameter(match(TokenType::ID)));
    }
    else{
        throw tokens[currToken];
    }
}

std::string Parser::match(TokenType matchTokenType) {
    //Token* tester = tokens[currToken];
//    for(Token* token : tokens){
//        std::cout << token->toString() << std::endl;
//    }

    //int size = tokens.size();


    if(matchTokenType == tokens[currToken]->getType()){
        //size = tokens.size();
        std::string des = tokens[currToken]->getDescription();
       // size = tokens.size();
        currToken++;
        //size = tokens.size();

        return des;
    }
    else{
        std::string des = tokens[currToken]->getDescription();

        throw tokens[currToken];

    }
}
