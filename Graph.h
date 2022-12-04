//
// Created by TheAa on 12/3/2022.
//

#ifndef PROJECT1_STARTER_CODE_GRAPH_H
#define PROJECT1_STARTER_CODE_GRAPH_H

#include <vector>;
#include "Node.h"

class Graph{
private:
    vector<Node*> adjList;
    vector<Node*> revAdjList;

    vector<int> postOrder;
    vector<vector<int>> sccList;

public:
    void dfsForest(){
        for(Node* : revAdjList){
            if(node->isVisited == false){
                
            }
        }
    }

    void dfsForest(vector<int> postOrder){
        
    }

    void populateReverseGraph(){
        for(Node* node : adjList){
            revAdjList.insert(node->getId(), new Node(node->getId()));
        }

        for(int i = 0; i < revAdjList.size(), i++){
            for(int id : adjList.at(i)){
                revAdjList.at(id).addAdjNode(i);
            }

        }
    }

};

#endif //PROJECT1_STARTER_CODE_GRAPH_H
