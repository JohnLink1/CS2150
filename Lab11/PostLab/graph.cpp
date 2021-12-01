//John Link, jwl9vq@virginia.edu, 11/30/21, graph.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include "graph.h"

using namespace std;

Graph::Graph(int input[9]){
    for(int i = 0; i < 9; i++){
        graph[i / 3][i % 3] = input[i];
    }
}

Graph::~Graph(){

}

void Graph::print(){
    for(int i = 0; i < 3; i++){
        for(int x = 0; x < 3; x++)
            cout << graph[i][x] << " ";
        cout << endl;
    }
}
void Graph::swap(int pos1, int pos2){
    if((graph[pos1/3][pos1%3] == 0 || graph[pos2/3][pos2%3] == 0) && abs((pos1 / 3) - (pos2 / 3)) <= 1 && abs((pos1 % 3) - (pos2 % 3)) <= 1){
        int temp = graph[pos2/3][pos2%3];
        graph[pos2/3][pos2%3] = graph[pos1/3][pos1%3];
        graph[pos1/3][pos1%3] = temp;
    }
}
void Graph::swap(int x1, int y1, int x2, int y2){
    if((graph[x1][y1] == 0 || graph[x2][y2] == 0) && (abs(x1-x2)+abs(y1-y2)) == 1){
        int temp = graph[x1][y1];
        graph[x1][y1] = graph[x2][y2];
        graph[x2][y2] = temp;
    }
}
int Graph::zeroPos(){
    for(int x = 0; x < 3, x++){
        for(int y = 0; y < 3; y++){
            if(graph[x][y] == 0){
                return y + 3*x;
            }
        }
    }
}

vector<Graph> Graph::generateNeighbors(vector<GraphNode>& gn, Graph prev){
    vector<Graph> l;
    int zpos = zeroPos();
    int xpos = zpos/3;
    int ypos = zpos%3;
    if(xpos + 1 < 3){
        if(prev.zeroPos() != ypos + 3*xpos){
            l.push_back(Graph
        }
    }
    if(ypos + 1 < 3){

    }
    if(xpos - 1 > 0){

    }
    if(ypos - 1 > 0){

    }
}
