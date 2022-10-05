#ifndef TOKEN_H
#define TOKEN_H
#include <string>



enum class TokenType {
    COLON,
    COLON_DASH,
    ADD,
    COMMA,
    FACTS,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    PERIOD,
    QUERIES,
    Q_MARK,
    RULES,
    SCHEMES,
    ID,
    STRING,
    endOF,
    COMMENT,

    // TODO: add the other types of tokens
    UNDEFINED
};

class Token
{
private:
    // TODO: add member variables for information needed by Token
    std::string description;
    int line = 0;
    TokenType type = TokenType::UNDEFINED;


private:

    std::string typeToString(TokenType type);
public:
    Token() : Token(TokenType::UNDEFINED, "undefined??", 0){}

    Token(TokenType type, std::string description, int line){
        this->description = description;
        this->line = line;
        this->type = type;
    };

    // TODO: add other needed methods
    std::string toString();

    std::string getTypeString();
    TokenType getType() const;


};

#endif // TOKEN_H

