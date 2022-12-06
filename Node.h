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
    vector<int> adjNodeVector;

public:
    //Node() = default;
    Node(){
        this->sink = true;
        this->visited = false;
    }
    Node(int id){
        this->id = id;
        this->sink = true;
        this->visited = false;
    }
    Node(int id, set<int> adjacentNodes){
        this->id = id;
        this->adjacentNodes = adjacentNodes;
        this->sink = false;
    }

    bool isVisited() { return visited; }
    bool isSink() { return sink; }
    bool hasAdjNode() { return !this->sink; }
    int getId(){ return id; }
    set<int> getAdjNodes(){ return adjacentNodes; }

    void setVisited(bool newVisited){ this->visited = newVisited; }
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
        this->sink = false;
    }

    int getFirstAdj() { return *(this->adjacentNodes.begin()); }

    int getNextAdj(vector<Node*> nodeAdjList){
        vector<int> v(adjacentNodes.begin(), adjacentNodes.end());
        adjNodeVector = v;

        for(long unsigned int i = 0; i < v.size(); i++){
            if(nodeAdjList.at(v.at(i))->visited == false){
                return v.at(i);
            }
        }

            return -1;
    }

    void printAdjNodesInfo(){
        for(int i : adjacentNodes){
            cout << i << " ";
        }
        cout << "   ---------------   ";
    }

    void printNodeInfo(){
        cout << "Node " << id << ": ";
        printAdjNodesInfo();
        cout << "Sink: " << ((sink) ? "true" : "false");
        cout << "   ---------------   ";
        cout << "Visited: " << ((visited) ? "true" : "false") << endl << endl;
    }

    void printAdjNodes(){
        string adjString;
        for(int i : adjacentNodes){
            adjString = adjString + "R" + to_string(i) + ",";
        }
        string st = adjString.substr(0, adjString.size()-1);
        cout << adjString << endl;
    }

    void printNode(){
        cout << "R" << id << ":";
        printAdjNodes();

    }


};

#endif //PROJECT1_STARTER_CODE_NODE_H
