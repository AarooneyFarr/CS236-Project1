cmake_minimum_required(VERSION 3.17)
project(Project1_Starter_Code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Automata)

add_executable(Project1_Starter_Code
        Automata/AddAutomaton.cpp
        Automata/AddAutomaton.h
        Automata/Automaton.h
        Automata/ColonAutomaton.cpp
        Automata/ColonAutomaton.h
        Automata/ColonDashAutomaton.cpp
        Automata/ColonDashAutomaton.h
        Automata/CommaAutomaton.cpp
        Automata/CommaAutomaton.h
        Automata/FactsAutomaton.cpp
        Automata/FactsAutomaton.h
        Automata/LeftParenAutomaton.cpp
        Automata/LeftParenAutomaton.h
        Automata/MultiplyAutomaton.cpp
        Automata/MultiplyAutomaton.h
        Automata/PeriodAutomaton.cpp
        Automata/PeriodAutomaton.h
        Automata/QueriesAutomaton.cpp
        Automata/QueriesAutomaton.h
        Automata/QuestionMarkAutomaton.cpp
        Automata/QuestionMarkAutomaton.h
        Automata/RightParenAutomaton.cpp
        Automata/RightParenAutomaton.h
        Automata/RulesAutomaton.cpp
        Automata/RulesAutomaton.h
        Automata/SchemesAutomaton.cpp
        Automata/SchemesAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        makefile
        Token.cpp
        Token.h)
