//
// Created by TheAa on 12/3/2022.
//

#ifndef PROJECT1_STARTER_CODE_GRAPH_H
#define PROJECT1_STARTER_CODE_GRAPH_H

#include <vector>
#include <algorithm>
#include <map>
#include "Node.h"
#include "Rule.h"

using namespace std;

class Graph{
private:
    vector<Node*> adjList;
    vector<Node*> revAdjList;

    vector<int> postOrder;
    vector<int> preOrder;
    vector<vector<int>> sccList;

    void dfsForest(){
        for(Node* node: revAdjList){
            if(node->isVisited() == false){
                vector<int> newGrouping;
                newGrouping.push_back(node->getId());
                Node* nextNode = revAdjList.at(node->getFirstAdj());

                while(nextNode->hasAdjNode() && nextNode->isVisited() == false){
                    newGrouping.push_back(nextNode->getId());
                    nextNode = revAdjList.at(nextNode->getFirstAdj());
                }

                reverse(newGrouping.begin(), newGrouping.end());

                for(int nodeId : newGrouping){
                    postOrder.push_back(nodeId);
                }
            }
        }
    }

    void dfsForestPostOrder(){
        preOrder = postOrder;
        reverse(preOrder.begin(), preOrder.end());

        for(int nodeIt = 0; nodeIt < preOrder.size(); nodeIt++){
            Node* node = adjList.at(preOrder.at(nodeIt));

            if(node->isVisited() == false){
                vector<int> newGrouping;
                newGrouping.push_back(node->getId());
                Node* nextNode = adjList.at(node->getFirstAdj());

                while(nextNode->hasAdjNode() && nextNode->isVisited() == false){
                    newGrouping.push_back(nextNode->getId());
                    nextNode = adjList.at(nextNode->getFirstAdj());
                }

                sccList.push_back(newGrouping);
            }
        }
    }

    void populateReverseGraph(){
        for(Node* node : adjList){
            revAdjList.insert(revAdjList.begin(),node->getId(),new Node(node->getId()));
        }

        for(int i = 0; i < revAdjList.size(); i++){
            for(int id = 0; id < revAdjList.at(i)->getAdjNodes().size(); id++){
                revAdjList.at(id)->addAdjNode(i);
            }

        }
    }

public:
    Graph() = default;

    vector<vector<int>> runGraphOptimization(vector<Rule*> rules){
        /**
         * Each index corresponds to a rule # and contains a list (including the current rule index)
         * of all of the other rules with the same name
         */
        vector<vector<int>> ruleNames;
        //TODO delete ^^ if map works
        map<string, set<int>> ruleMap;

        //Populate ruleNames
        for(int i = 0; i < rules.size(); i++){
            vector<int> otherRules;
            set<int> mapRules;

            for(int j = 0; j < rules.size(); j++){
                if(rules.at(i)->getHead()->getId() == rules.at(j)->getHead()->getId()){
                    otherRules.push_back(j);
                    mapRules.insert(j);
                }
            }

            ruleNames.push_back(otherRules);
            ruleMap[rules.at(i)->getHead()->getId()] = mapRules;
        }

        //Add each rule as a node
        for(int i = 0; i<rules.size(); i++){
            adjList.push_back(new Node(i));
        }

        //Add adjacency to nodes - loop through rules
        for(int i = 0; i < rules.size(); i++){
            //Loop through each predicate in rule and add adjNodes
            for(Predicate* pred : rules.at(i)->getPredicates()){
                adjList.at(i)->addAdjNodes(ruleMap.at(pred->getId()));
            }
        }

        //Run algorithms
        populateReverseGraph();
        dfsForest();
        dfsForestPostOrder();

        return sccList;
    }



};

#endif //PROJECT1_STARTER_CODE_GRAPH_H
