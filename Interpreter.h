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
        InterpretRules();
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

    void InterpretRules(){
        int ogDataSize = database.getSize();
        int newDataSize = ogDataSize + 1;
        int runThroughCount = 0;

        cout << "Rule Evaluation" << endl;

        while(ogDataSize != newDataSize) {
            ogDataSize = database.getSize();

            for (Rule *rule : program->getRules()) {
                    string headId = rule->getHead()->getId();
                    int predCount = rule->getPredicates().size();
                    Relation *f1;

                    //Join all predicates
                    if (predCount > 1) {
                        f1 = runTwo(rule->getPredicates().at(predCount - 2), rule->getPredicates().at(predCount - 1));
                        predCount--;

                        while (predCount > 1) {
                            f1 = runTwo(f1, rule->getPredicates().at(predCount - 2));
                            predCount--;
                        }
                    }
                    else {
                        f1 = database.getRelationCopy(rule->getPredicates().at(0)->getId());
                        f1->rename(rule->getPredicates().at(0)->getParamsStringList());
                    }

                    //Project new Relation
                    vector<int> newColumns;

                    for (string param : rule->getHead()->getParamsStringList()) {
                        for (int i = 0; i < f1->getHeader().getValues().size(); i++) {

                            if (param == f1->getHeader().getValues().at(i)) {
                                newColumns.push_back(i);

                            }
                        }
                    }
                    Relation *f2 = f1->project(newColumns);

                    //Rename new Relation to match database
                    Relation *f3 = f2->rename(database.getRelation(headId)->getHeader().getValues());

                    //Concat new data to OG database relation
                    Relation* newStuff = database.getRelation(headId)->concat(f3);

                    //print evaluation

                    string headerString = rule->toString() + ".";
                    string extra;

                    //Check if there is anything to return
                    if (newStuff->getTuples().empty()) {

                    }
                    else {
                        extra = newStuff->toString();
                    }

                    cout << headerString << endl << extra;

            }
            newDataSize = database.getSize();
            runThroughCount++;
        }

        cout << endl << "Schemes populated after " << runThroughCount << " passes through the Rules." << endl << endl << "Query Evaluation" << endl;



    };

    Relation* runTwo(Predicate* p1, Predicate* p2){
        Relation* r1 = database.getRelationCopy(p1->getId());
        Relation* r2 = database.getRelationCopy(p2->getId());

        r1 = r1->rename(p1->getParamsStringList());
        r2 = r2->rename(p2->getParamsStringList());

        return r1->join(r2);
    };

    Relation* runTwo(Relation* r1, Predicate* p2){
        Relation* r2 = database.getRelationCopy(p2->getId());

        r2 = r2->rename(p2->getParamsStringList());

        return r1->join(r2);
    };

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
        else if(variables.empty()){
            headerString += "Yes(" + to_string(copyRelation->getTuples().size()) + ")\n";

        }
        else{
            headerString += "Yes(" + to_string(copyRelation->getTuples().size()) + ")\n";
            extra = copyRelation->toString();
        }

        cout << headerString << extra;

        return copyRelation;
    };


};

#endif //INTERPRETER_H
