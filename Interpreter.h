//
// Created by TheAa on 10/29/2022.
//

#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"

class Interpreter{
private:
    DatalogProgram program;
    Database database;

public:
    Interpreter(DatalogProgram program) {
        this->program = program;
    }

    void InterpretSchemes() {
        for (Predicate* scheme : program.getSchemes()){
            Relation* newRelation = new Relation(scheme->getId(), Header(scheme->getParamsStringList()));
            database.addRelation(newRelation);
        }
    }

    void InterpretFacts() {
        for (Predicate* fact : program.getFacts()) {
            database.getRelation(fact->getId())->addTuple(Tuple(fact->getParamsStringList()));
        }
    }

    //void InterpretRules();
    void InterpretQueries() {
        for (Predicate* query : program.getQueries()) {
            Relation* copyRelation = database.getRelationCopy(query->getId());
            vector<int> firstIndex;
            string prevID = "";
            int prevIt = 0;

            for(int i = 0; i < query->getParams().size(); i++){
                //If parameter is a string/constant
                if(query->getParams().at(i)->getType() == 1){
                    Relation* selectRelation = copyRelation->select1(i,query->getParamsStringList().at(i));
                }

                //If parameter is an ID/variable
                if(query->getParams().at(i)->getType() == 2 && prevID ==  query->getParamsStringList().at(i)){
                    Relation* selectRelation = copyRelation->select2(prevIt,i);
                }
                else if(query->getParams().at(i)->getType() == 2){
                    //Store the first ID value and iterator
                    prevID = query->getParamsStringList().at(i);
                    prevIt = i;
                }
            }
        }
    }


};

#endif //INTERPRETER_H
