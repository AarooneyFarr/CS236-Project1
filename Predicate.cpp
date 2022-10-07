//
// Created by TheAa on 10/5/2022.
//

#include "Predicate.h"
//
//Predicate::Predicate() {
//
//}

std::string Predicate::toString() {
    std::string paramString = "";

    for(Parameter* param : this->params){
        if(this->params.back() == param){
            paramString += param->toString();
        }
        else{
            paramString += param->toString() + ",";
        }

    }

    std::string predString = this->id + "(" + paramString + ")";

    return predString;
}

void Predicate::addParam(Parameter *param) {
    this->params.push_back(param);
}

void Predicate::addId(std::string idString) {
    this->id = idString;
}


