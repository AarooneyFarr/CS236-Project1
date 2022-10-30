//
// Created by TheAa on 10/29/2022.
//

#ifndef TUPLE_H
#define TUPLE_H

#include<string>
#include<vector>

using namespace std;

class Tuple{
private:
    vector<string> rowValues;
public:
    Tuple() = default;
    Tuple( vector<string> rowValues) {
        this->rowValues = rowValues;
    }

    bool operator<(const Tuple &otherTuple) const
    {
        if (rowValues < otherTuple.rowValues)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    vector<string> getValues(){ return rowValues; }
};

#endif //TUPLE_H
