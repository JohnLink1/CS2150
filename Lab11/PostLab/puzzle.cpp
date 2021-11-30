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
Graph readInGrid();

int main(){
    Graph g = readInGrid();
    g.print();
    return 0;
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
