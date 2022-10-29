//
// Created by TheAa on 10/29/2022.
//

#ifndef RELATION_H
#define RELATION_H
#include <string>
#include <vector>
#include <set>
#include "Header.h"
#include "Tuple.h"

using namespace std;

class Relation{
private:
    string name;
    Header columnNames;
    set<Tuple> tuples;

public:
    Relation() =default;
    Relation(string name, Header columnNames, set<Tuple> tuples = {}) {
        this->name = name;
        this->columnNames = columnNames;
        this->tuples = tuples;
    }

    string getName() { return name; }
    Header getHeader() { return columnNames; }
    set<Tuple> getTuples() { return tuples; }

    void addTuple(Tuple newTuple) { tuples.insert(newTuple); }

    Relation* select1(int columnIndex, string value) {
        set<Tuple> newTuples;
        for (Tuple tuple : tuples){
            if(tuple.getValues().at(columnIndex) == value){
                newTuples.insert(tuple);
            }
        }

        return new Relation(name, columnNames, newTuples);
    };

    Relation* select2(int columnIndex1, int columnIndex2) {
        set<Tuple> newTuples;
        for (Tuple tuple : tuples){
            if(tuple.getValues().at(columnIndex1) == tuple.getValues().at(columnIndex2)){
                newTuples.insert(tuple);
            }
        }

        return new Relation(name, columnNames, newTuples);
    };

    Relation* project(vector<int> columnsToProject) {
        set<Tuple> newTuples;
        vector<string> newColumnNames;


        for(int column : columnsToProject){
            newColumnNames.push_back(columnNames.getValues().at(column));
        }

        for (Tuple tuple : tuples){
            vector<string> newTupleValues;
            for(int column : columnsToProject){
                newTupleValues.push_back(tuple.getValues().at(column));
            }
            newTuples.insert(Tuple(newTupleValues));
        }

        return new Relation(name, newColumnNames, newTuples);
    };

    Relation* rename(vector<string> newColumnNames){
        return new Relation(name, newColumnNames, tuples);
    };

    //Join()


};

#endif //RELATION_H
