//John Link, jwl9vq@virginia.edu, 11/28/21, puzzle.cpp
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include "graph.h"

using namespace std;

// Forward declarations
vector<GraphNode> table;
GraphNode* root = new GraphNode();
int complete[3][3] = {{1, 2, 3,}, {4, 5, 6}, {7, 8, 0}};

int main(){
    root->value = readInGrid();
    table.push_back(root->value);
    buildTree(root);
    return 0;
}

void buildTree(GraphNode*& root){
    root->nbors = root->value.findNeighbors(root.parent);
    if(root->nbors == NULL || root->value.graph == complete)
        return;
    for(GraphNode gn : root->nbors){
        buildTree(gn);
    }
}

Graph readInGrid(){
    int input[9];
    string temp;
    for(int x = 0; x < 9; x++){
        cin >> temp;
        input[x] = stoi(temp);
    }
    Graph g(input);
    return g;
}
