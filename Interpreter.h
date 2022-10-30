//
// Created by TheAa on 10/29/2022.
//

#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "DatalogProgram.h"
#include "Database.h"

class Interpreter{
private:
    DatalogProgram* program;
    Database database;

public:
    Interpreter(DatalogProgram* program) {
        this->program = program;
    }

    void run(){
        InterpretSchemes();
        InterpretFacts();

        InterpretQueries();
    }

    void InterpretSchemes() {
        for (Predicate* scheme : program->getSchemes()){
            Relation* newRelation = new Relation(scheme->getId(), Header(scheme->getParamsStringList()));
            database.addRelation(newRelation);
        }
    }

    void InterpretFacts() {
        for (Predicate* fact : program->getFacts()) {
            database.getRelation(fact->getId())->addTuple(Tuple(fact->getParamsStringList()));
        }
    }

    //void InterpretRules();
    void InterpretQueries() {
        for (Predicate* query : program->getQueries()) {
            evaluatePredicate(query);
        }



    }

    Relation* evaluatePredicate(Predicate* query){
        Relation* copyRelation = database.getRelationCopy(query->getId());

        map<string,int> trackerMap;
        vector<int> firstIndex;
        vector<string> variables;

        bool alreadyExists = false;

        //Run all selects
        for (long unsigned int i = 0; i < query->getParams().size(); i++)
        {
            int queryType = query->getParams().at(i)->getType();
            string paramValue = query->getParamsStringList().at(i);

            //If parameter is a string/constant
            if(queryType == 1){
                copyRelation = copyRelation->select1(i,query->getParamsStringList().at(i));
                continue;
            }

            //Check if we have seen ID/variable before
            for(string id : variables){
                alreadyExists = (id == query->getParamsStringList().at(i)) ? true : alreadyExists;
            }

            //If parameter is an ID/variable
            if(queryType == 2 && alreadyExists){
                copyRelation = copyRelation->select2(trackerMap[paramValue],i);
            }
            else if(queryType == 2){
                //Variable is new so add it to tracker lists
                variables.push_back(paramValue);
                firstIndex.push_back(i);
                trackerMap[paramValue] = i;
            }

            alreadyExists = false;
        }

        copyRelation = copyRelation->project(firstIndex);
        copyRelation = copyRelation->rename(variables);

        string headerString = query->toString() + "? ";
        string extra;

        //Check if there is anything to return
        if(copyRelation->getTuples().empty()){
            headerString += "No\n";
        }
        else{
            headerString += "Yes(" + to_string(copyRelation->getTuples().size()) + ")";
            extra = copyRelation->toString();
        }

        cout << headerString << extra;

        return copyRelation;
    };


};

#endif //INTERPRETER_H
