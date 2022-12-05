//
// Created by TheAa on 12/3/2022.
//

#ifndef PROJECT1_STARTER_CODE_NODE_H
#define PROJECT1_STARTER_CODE_NODE_H

#include <vector>
#include <set>

using namespace std;

class Node{
private:
    int id;
    bool visited;
    bool sink;
    set<int> adjacentNodes;

public:
    Node() = default;
    Node(int id){
        this->id = id;
        this->sink = true;
    }
    Node(int id, set<int> adjacentNodes){
        this->id = id;
        this->adjacentNodes = adjacentNodes;
        this->sink = false;
    }

    bool isVisited() { return visited; }
    bool hasAdjNode() { return this->sink; }
    int getId(){ return id; }
    set<int> getAdjNodes(){ return adjacentNodes; }

    void setVisited(bool newVisited){ this->visited = visited; }
    void setId(int newId){ this->id = id; }
    void setAdjNodes(set<int> nodes){
        this->adjacentNodes = nodes;
        this->sink = false;
    }

    void addAdjNode(int nodeId){
        this->adjacentNodes.insert(nodeId);
        this->sink = false;
    }

    void addAdjNodes(set<int> newNodes){
        adjacentNodes.insert(newNodes.begin(), newNodes.end());
    }

    int getFirstAdj() { return *(this->adjacentNodes.begin()); }


};

#endif //PROJECT1_STARTER_CODE_NODE_H
