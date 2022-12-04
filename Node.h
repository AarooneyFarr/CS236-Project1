//
// Created by TheAa on 12/3/2022.
//

#ifndef PROJECT1_STARTER_CODE_NODE_H
#define PROJECT1_STARTER_CODE_NODE_H

#include <vector>

class Node{
private:
    int id;
    bool visited;
    set<int> adjacentNodes;

public:
    Node() = default();
    Node(int id){
        this->id = id;
    }
    Node(int id, vector<int> adjacentNodes){
        this->id = id;
        this->adjacentNodes = adjacentNodes;
    }

    bool isVisited() { return visited; }
    int getId(){ return id; }
    vector<int> getAdjNodes(){ return adjacentNodes; }

    void setVisited(bool visited){ this->visited = visited; }
    void setId(int id){ this->id = id; }
    void setAdjNodes(vector<int> nodes){ this->adjacentNodes = nodes; }

    void addAdjNode(int nodeId){ this->adjacentNodes.insert(nodeId); }
    int getFirstAdj() { return *(this->adjacentNodes.begin()); }


};

#endif //PROJECT1_STARTER_CODE_NODE_H
