//
// Created by TheAa on 10/4/2022.
//

#include "Parser.h"

void Parser::parseDatalogProgram() {
    match(TokenType::SCHEMES);
    match(TokenType::COLON);
    parseScheme();
    parseSchemeList();
    match(TokenType::FACTS);
    match(TokenType::COLON);
    parseFactList();
    match(TokenType::RULES);
    match(TokenType::COLON);
    parseRuleList();
    match(TokenType::QUERIES);
    match(TokenType::COLON);
    parseQuery();
    parseQueryList();
    match(TokenType::endOF);
}

void Parser::Parse() {

}

DatalogProgram Parser::parse() {
    return DatalogProgram();
}

void Parser::parseSchemeList() {
    if(tokens[currToken]->getTypeString() == "ID"){
        parseScheme();
        parseSchemeList();
    }
}

void Parser::parseFactList() {
    if(tokens[currToken]->getTypeString() == "ID"){
        parseFact();
        parseFactList();
    }
}

void Parser::parseRuleList() {
    if(tokens[currToken]->getTypeString() == "ID"){
        parseRule();
        parseRuleList();
    }
}

void Parser::parseQueryList() {
    if(tokens[currToken]->getTypeString() == "ID"){
        parseQuery();
        parseQueryList();
    }
}

void Parser::parseScheme() {
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    match(TokenType::ID);
    parseIdList();
    match(TokenType::RIGHT_PAREN);
}

void Parser::parseFact() {
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    match(TokenType::STRING);
    parseStringList();
    match(TokenType::RIGHT_PAREN);
    match(TokenType::PERIOD);
}

void Parser::parseRule() {
    parseHeadPredicate();
    match(TokenType::COLON_DASH);
    parsePredicate();
    parsePredicateList();
    match(TokenType::PERIOD);
}

void Parser::parseQuery() {
    parsePredicate();
    match(TokenType::Q_MARK);
}

void Parser::parseHeadPredicate() {
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    match(TokenType::ID);
    parseIdList();
    match(TokenType::RIGHT_PAREN);
}

void Parser::parsePredicate() {
    match(TokenType::ID);
    match(TokenType::LEFT_PAREN);
    match(TokenType::ID);
    parseParameter();
    parseParameterList();
    match(TokenType::RIGHT_PAREN);
}

void Parser::parsePredicateList() {
    if(tokens[currToken]->getTypeString() == "COMMA"){
        match(TokenType::COMMA);
        parsePredicate();
        parsePredicateList();
    }
}

void Parser::parseParameterList() {
    if(tokens[currToken]->getTypeString() == "COMMA"){
        match(TokenType::COMMA);
        parseParameter();
        parseParameterList();
    }
}

void Parser::parseStringList() {
    if(tokens[currToken]->getTypeString() == "COMMA"){
        match(TokenType::COMMA);
        match(TokenType::STRING);
        parseStringList();
    }
}

void Parser::parseIdList() {
    if(tokens[currToken]->getTypeString() == "COMMA"){
        match(TokenType::COMMA);
        match(TokenType::ID);
        parseIdList();
    }
}

void Parser::parseParameter() {
    if(tokens[currToken]->getTypeString() == "STRING"){
        match(TokenType::STRING);
    }
    else if(tokens[currToken]->getTypeString() == "ID")
    {
        match(TokenType::ID);
    }
    else{
        throw tokens[currToken];
    }
}

void Parser::match(TokenType matchTokenType) {
    if(matchTokenType == tokens[currToken]->getType()){
        currToken++;
    }
    else{
        throw new Token(matchTokenType, " ", 0);
    }
}
