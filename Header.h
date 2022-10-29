//
// Created by TheAa on 10/29/2022.
//

#ifndef HEADER_H
#define HEADER_H
#include<string>
#include<vector>

using namespace std;

class Header{
private:
    vector<string> columnNames;
public:
    Header() = default;

    Header(vector<string> columnNames) {
        this->columnNames = columnNames;
    }

    vector<string> getValues(){ return columnNames; }
};
#endif //HEADER_H
