#include "Lexer.h"
#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    std::string input = "";

    std::string filename = argv[1];

    std::ifstream myFile(filename);
    if(myFile.is_open()){
        while(myFile.peek() != EOF){
            char next = myFile.get();
            input = input + next;
        }
    }

    lexer->Run(input);
    std::vector<Token*> tokens = lexer->getTokens();

    for(Token* token : tokens){
        std::cout << token->toString() << std::endl;
    }

    std::string count = "Total Tokens = " + std::to_string(tokens.size());
    std::cout << count;

    delete lexer;

    return 0;
}