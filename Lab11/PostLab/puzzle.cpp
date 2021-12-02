//John Link, jwl9vq@virginia.edu, 11/28/21, puzzle.cpp
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

/*! @mainpage Graph Solver Code
 *
 * boom.... solved
 *
 */


// Forward declaration
map<string, list<string>> combos; /* @var hashtable to store next possible moves*/
map<string, bool> visit; /* @var hashtable to store if the specific combination has been visited already*/
map<string, int> nums; /* @var hashtable to store path length so far*/
string str = " 12345678";
string ans = "12345678 ";
string readInGrid();
list<string> generateNeighbors(string s);
int findPath(string s);
void print(string s);

/**
 * @brief Main method to organize input and output of the puzzle solver
 *
 *
 * @return Exit code
 *
 */
int main(){
    cout << "Enter puzzle" << endl;
    string init = readInGrid();
    cout << "Solving puzzle" << endl;
    do{
        combos.insert(pair<string, list<string>>(str, generateNeighbors(str)));
        visit.insert(pair<string, bool>(str, false));
        nums.insert(pair<string, int>(str, 0));
    } while(next_permutation(str.begin(), str.end()));
    int path = findPath(init);
    cout << path << endl;
    return 0;
}

/**
 * @brief Method to convert 9 char string to 3x3 array
 *
 *
 * @return void
 * @param s Input string.
 */
void print(string s){
    for(int x = 0; x<3; x++){
        for(int y = 0; y<3; y++)
            cout << s.at(x*3 + y) << " ";
        cout << endl;
    }
}

/**
 * @brief Calculates the shortest path to the answer.
 *
 * Utilizes breadth-first search to count its way through the tree of possible paths
 *
 * @return Path length
 * @param s Starting grid.
 */
int findPath(string s){
    queue<string> q;
    visit[s] = true;
    q.push(s);
    string temp;
    while(!q.empty()){
        temp = q.front();
        //print(temp);
        q.pop();
        if(temp == ans)
            return nums[temp];
        for(string s1 : combos[temp]){
            if(visit[s1] == false){
                visit[s1] = true;
                nums[s1] = nums[temp] + 1;
                q.push(s1);
            }
        }
    }
    return -1;
}

/**
 * @brief Calculates all possible next moves that could be played.
 *
 * Puts all posible moves into a list of strings to be stored in the combos map.
 *
 * @return List of all posible moves.
 * @param s Starting grid.
 */
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
    if(xpos - 1 >= 0){
        swap(temp[spos], temp[ypos + 3*(xpos - 1)]);
        l.push_back(temp);
        temp = s;
    }
    if(ypos - 1 >= 0){
        swap(temp[spos], temp[ypos - 1 + 3*xpos ]);
        l.push_back(temp);
        temp = s;
    }
    return l;
}

/**
 * @brief Reads user input to build the grid..
 *
 * Reads in a string and converts spaces to 0s.
 *
 * @return Starting grid.
 *
 */
string readInGrid(){
    string temp;
    string order;
    for(int x = 0; x < 9; x++){
        cin >> temp;
        if(temp == "0")
            order+=" ";
        else
            order+= temp;
    }
    return order;
}
