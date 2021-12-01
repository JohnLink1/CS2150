//John Link, jwl9vq@virginia.edu, 12/1/21, graphNode.h
#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <string>
#include <iostream>
#include "graph.h"

using namespace std;

class GraphNode{
    public:
        Graph value;
        list<GraphNode*> children;
        GraphNode* parent;
        GraphNode();
        ~GraphNode();
};
#endif
