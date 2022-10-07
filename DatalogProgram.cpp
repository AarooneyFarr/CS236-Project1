//
// Created by TheAa on 10/4/2022.
//

#include "DatalogProgram.h"
#include <algorithm>

DatalogProgram::DatalogProgram() {

}

std::string DatalogProgram::toString() {
    std::string datalogString = "";
    std::string schemesString = "";
    std::string factsString = "";
    std::string rulesString = "";
    std::string queriesString = "";
    std::string domainsString = "";

    //Schemes
    std::string schemes = "";
    for(Predicate* pred : this->schemes){
        schemes += "  " + pred->toString() + "\n";
    }
    schemesString = "Schemes(" + std::to_string(this->schemes.size()) + "):\n" + schemes;

    //Facts
    std::string facts = "";
    for(Predicate* pred : this->facts){
        facts += "  " + pred->toString() + ".\n";
    }
    factsString = "Facts(" + std::to_string(this->facts.size()) + "):\n" + facts;

    //Rules - TODO check if there are any rules?
    std::string rules = "";
    for(Rule* rule : this->rules){
        rules += "  " + rule->toString() + ".\n";
    }
    rulesString = "Rules(" + std::to_string(this->rules.size()) + "):\n" + rules;

    //Queries - TODO check if there are queries?
    std::string queries = "";
    for(Predicate* pred : this->queries){
        queries += "  " + pred->toString() + "?\n";
    }
    queriesString = "Queries(" + std::to_string(this->queries.size()) + "):\n" + queries;

    //Domains
    std::string domains = "";

    //std::sort(this->domains.begin(), this->domains.end());

    for(std::string domain : this->domains){
        domains += "  " + domain + "\n";
    }
    domainsString = "Domains(" + std::to_string(this->domains.size()) + "):\n" + domains;

    datalogString = schemesString + factsString + rulesString + queriesString + domainsString;

    return datalogString;
}
