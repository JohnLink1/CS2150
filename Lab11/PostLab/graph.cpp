//John Link, jwl9vq@virginia.edu, 11/30/21, graph.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
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
    else
        cout << "That operation is invalid" << endl;
}
