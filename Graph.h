//
// Created by TheAa on 12/3/2022.
//

#ifndef PROJECT1_STARTER_CODE_GRAPH_H
#define PROJECT1_STARTER_CODE_GRAPH_H

#include <vector>;
#include <algorithm>
#include "Node.h"

using namespace std;

class Graph{
private:
    vector<Node*> adjList;
    vector<Node*> revAdjList;

    vector<int> postOrder;
    vector<int> preOrder;
    vector<vector<int>> sccList;

public:
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

};

#endif //PROJECT1_STARTER_CODE_GRAPH_H
