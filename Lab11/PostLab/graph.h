//John Link, jwl9vq@virginia.edu, 11/30/21, graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>

using namespace std;

class Graph{
    public:
        
        Graph(int input[9]);
        ~Graph();
        void swap(int pos1, int pos2);
        void print();

    private:
        int graph[3][3];
        

};
#endif
