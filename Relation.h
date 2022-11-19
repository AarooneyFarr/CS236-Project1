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

        Relation* newRelation = new Relation(name, newColumnNames, newTuples);

//        this->print();
//        newRelation->print();

        return newRelation;
    };

    Relation* rename(vector<string> newColumnNames){
        Relation* newRelation = new Relation(name, newColumnNames, tuples);


        return newRelation;
    };

    string toString(){
        string relation;

        for(Tuple tuple : tuples){
            relation += "  ";

            for (long unsigned int col = 0; col < tuple.getValues().size() - 1; col++)
            {
                string one = columnNames.getValues().at(col);
                string two = tuple.getValues().at(col);

                relation += columnNames.getValues().at(col) + "=" + tuple.getValues().at(col) + ", ";
            }
            string id = columnNames.getValues().at(tuple.getValues().size() - 1);
            string dummyVars = tuple.getValues().at(tuple.getValues().size() - 1);
            string finalString =  id + "=" + dummyVars + "\n";
            relation += finalString;
        }

        return relation;
    };

    Relation* join(Relation* other){
        set<Tuple> newTuples;
        Header newHeader;
        newHeader.addValues(columnNames.getValues());
        newHeader.addValues(other->columnNames.getValues());
        int size = columnNames.getValues().size();
        vector<vector<int>> matchIndices;
        bool concatTuple = true;

        //get match index values from the headers
        for (long unsigned int i = 0; i < columnNames.getValues().size(); i++){
            for (long unsigned int j = 0; j < other->columnNames.getValues().size(); j++){
                if(columnNames.getValues().at(i) == other->columnNames.getValues().at(j)){
                    vector<int> match;
                    match.push_back(i);
                    match.push_back(j);
                    matchIndices.push_back(match);

                    newHeader.setValue(size + j, "dup" + other->columnNames.getValues().at(j));

                }
            }
        }

        //loop through the tuples on both tables to check for equality and add a new concat tuple if there is a full match
        for (Tuple homeTuple : tuples){
            Tuple newTuple;
            newTuple.addValues(homeTuple.getValues());

            for(Tuple otherTuple : other->tuples){
                for(vector<int> indexPair : matchIndices) {
                    if (homeTuple.getValues().at(indexPair.at(0)) != otherTuple.getValues().at(indexPair.at(1))) {
                        concatTuple = false;
                    }
                }
                if(concatTuple){
                    Tuple copyTuple;
                    copyTuple.addValues(newTuple.getValues());

                     newTuple.addValues(otherTuple.getValues());
                     newTuples.insert(newTuple);
                     newTuple = copyTuple;
                }
                concatTuple = true;
            }
        }

        return new Relation(name, newHeader, newTuples);
    }

    Relation* concat(Relation* other){
        int size = this->getTuples().size();
        int newSize;
        Relation* addedStuff = new Relation(name, columnNames, {});

        for(Tuple tuple : other->getTuples()){
            addTuple(tuple);
            newSize = this->getTuples().size();
            if(size != newSize){
                addedStuff->addTuple(tuple);
            }
            size = this->getTuples().size();
        }

        return addedStuff;
    };

    void print(){
        for(string value : columnNames.getValues()){
            cout << value << " ";
        }
        cout << endl;
        for(Tuple tuple : tuples){
            for(string value : tuple.getValues()){
                cout << value << " ";
            }
            cout << endl;
        }
    }

};

#endif //RELATION_H
