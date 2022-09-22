#include "Lexer.h"
//#include <vector>

int main(int argc, char** argv) {

    Lexer* lexer = new Lexer();

    lexer->Run(argv);
    std::vector<Token*> tokens = lexer->getTokens();

    delete lexer;

    return 0;
}