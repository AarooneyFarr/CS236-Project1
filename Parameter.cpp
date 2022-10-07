//
// Created by TheAa on 10/5/2022.
//

#include "Parameter.h"

std::string Parameter::toString() {
    return this->value;
}

void Parameter::setValue(std::string value) {
    this->value = value;
}
