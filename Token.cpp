#include "Token.h"
#include <string>

//Token::Token(TokenType type, std::string description, int line) {
    // TODO: initialize all member variables
//}

std::string Token::toString(){
    return ("(" + typeToString(this->type) + ",\"" + this->description + "\"," + std::to_string(this->line) + ")");
}

std::string Token::typeToString(TokenType type){
    switch (type){
        case TokenType::COLON: return "COLON"; break;
        case TokenType::COMMA: return "COMMA"; break;
        case TokenType::PERIOD: return "PERIOD"; break;
        case TokenType::Q_MARK: return "Q_MARK"; break;
        case TokenType::LEFT_PAREN: return "LEFT_PAREN"; break;
        case TokenType::RIGHT_PAREN: return "RIGHT_PAREN"; break;
        case TokenType::COLON_DASH: return "COLON_DASH"; break;
        case TokenType::MULTIPLY: return "MULTIPLY"; break;
        case TokenType::ADD: return "ADD"; break;
        case TokenType::SCHEMES: return "SCHEMES"; break;
        case TokenType::FACTS: return "FACTS"; break;
        case TokenType::RULES: return "RULES"; break;
        case TokenType::QUERIES: return "QUERIES"; break;
        case TokenType::UNDEFINED: return "UNDEFINED"; break;

    }

    return "ERROR";
}
