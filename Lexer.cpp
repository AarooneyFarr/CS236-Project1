#include "Lexer.h"
#include "Automata/ColonAutomaton.h"
#include "Automata/ColonDashAutomaton.h"
#include "Automata/LeftParenAutomaton.h"
#include "Automata/MultiplyAutomaton.h"
#include "Automata/RightParenAutomaton.h"
#include "Automata/AddAutomaton.h"
#include "Automata/PeriodAutomaton.h"
#include "Automata/RulesAutomaton.h"
#include "Automata/FactsAutomaton.h"
#include "Automata/QueriesAutomaton.h"
#include "Automata/QuestionMarkAutomaton.h"
#include "Automata/SchemesAutomaton.h"


Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    // TODO: need to clean up the memory in `automata` and `tokens`
}

void Lexer::CreateAutomata() {
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new LeftParenAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new RightParenAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new QuestionMarkAutomaton());
    automata.push_back(new SchemesAutomaton());
    // TODO: Add the other needed automata here
}

void Lexer::Run(std::string& input) {
   

    int lineNumber = 1;

    // While there are more characters to tokenize
    while (input.size() > 0) {
        int maxRead = 0;
        Automaton * maxAutomaton = automata.front();

        
        if(isspace(input[0])){
            input.erase(0,1);
        }

        // Here is the "Parallel" part of the algorithm
        //   Each automaton runs with the same input
        // foreach automaton in automata {
        for(Automaton* automaton : automata){
            int inputRead = automaton->Start(input);
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automaton;
            }
        }
        // Here is the "Max" part of the algorithm
        if (maxRead > 0) {
            Token* newToken = maxAutomaton->CreateToken(input, lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            maxRead = 1;
                Token* newToken = new Token(TokenType::UNDEFINED, std::string (1,input[0]), lineNumber);
                
                tokens.push_back(newToken);
        }
        // Update `input` by removing characters read to create Token
        input.erase(0, maxRead);
    }
    //add end of file token to all tokens

}
