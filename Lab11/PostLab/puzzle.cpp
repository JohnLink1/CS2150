//John Link, jwl9vq@virginia.edu, 11/28/21, puzzle.cpp
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

// Forward declaration
map<string, list<string>> combos;
string str = " 12345678";
string readInGrid();
list<string> generateNeighbors(string s);

int main(){
    string init = readInGrid();
    do{
        combos.insert(pair<string, list<string>>(str, generateNeighbors(str)));
    } while(next_permutation(str.begin(), str.end()));
    
    return 0;
}

list<string> generateNeighbors(string s){
    list<string> l;
    string temp = s;
    int spos = s.find(" ");
    int xpos = spos/3;
    int ypos = spos%3;
    if(xpos + 1 < 3){
        swap(temp[spos], temp[ypos + 3*(xpos + 1)]);
        l.push_back(temp);
        temp = s;
    }
    if(ypos + 1 < 3){
        swap(temp[spos], temp[ypos + 1 + 3*xpos]);
        l.push_back(temp);
        temp = s;
    }
    if(xpos - 1 > 0){
        swap(temp[spos], temp[ypos + 3*(xpos - 1)]);
        l.push_back(temp);
        temp = s;
    }
    if(ypos - 1 > 0){
        swap(temp[spos], temp[ypos - 1 + 3*xpos ]);
        l.push_back(temp);
        temp = s;
    }
    return l;
}

string readInGrid(){
    string temp;
    string order;
    for(int x = 0; x < 9; x++){
        cin >> temp;
        order+= temp;
    }
    return order;
}
