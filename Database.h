//
// Created by TheAa on 10/29/2022.
//

#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <iostream>
#include "Relation.h"
#include <map>

using namespace std;

class Database{
private:
    map<std::string, Relation*> relations;

public:
    void addRelation(Relation* newRelation) {
        relations.insert({newRelation->getName(), newRelation});
    };

    Relation* getRelation(std::string relationName) {
        if(relations.find(relationName) != relations.end()){
            return relations[relationName];
        }
        else{
            cout << "Relation " << relationName << " not found" << endl;
        }
        return new Relation();
    };

    Relation* getRelationCopy(std::string relationName) {


        if(relations.find(relationName) != relations.end()){
            Relation* copy = new Relation(relations[relationName]->getName(), relations[relationName]->getHeader(), relations[relationName]->getTuples());
            return copy;
        }
        else{
            cout << "Relation " << relationName << " not found" << endl;
        }

        return new Relation();
    };

    void print(){
        for(pair<string, Relation*> relation: relations){
            for(string value : relation.second->getHeader().getValues()){
                cout << value << " ";
            }
            cout << endl;
            for(Tuple tuple : relation.second->getTuples()){
                for(string value : tuple.getValues()){
                    cout << value << " ";
                }
                cout << endl;
            }
        }
    }

    int getSize(){
        int size = 0;
        for(pair<string, Relation*> relation : relations){
            for(Tuple tuple : relation.second->getTuples()){
                size ++;
            }
        }

        return size;
    }

};
#endif //DATABASE_H
