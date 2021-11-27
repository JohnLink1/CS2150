//John Link, jwl9vq@virginia.edu, 11/23/21, topological.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <queue>
#include <map>
#include <stack>
#include <list>

using namespace std;
/**
 * @brief Class to store the Graph - called node for some reason
 *
 * Class stores Verticies and their respective indexes in the parallel visit and list<string> arrays
 *
 *
 */
class Node {
    int size;
    map<string, int> idx;
    list<string>* adj;
    bool* visit;
    void preSort(string str);

public:
    string first;
    Node(int i);
    ~Node();
    void edge(string str1, string str2);
    void sort();
};


/**
 * @brief Creates an empty graph of size <= i
 *
 * This function computes the average using the standard accepted
 * formula for doing so.
 *
 * @return The average of the two passed values.
 * @param x The first value to average.
 * @param y The second value to average.
 * @todo Need to write acceptance tests for this function
 */
Node::Node(int i){
    size = 0;
    adj = new list<string>[i+1];
    visit = new bool[i+1];
}
Node::~Node(){
    //delete adj;
    //delete visit;
 }

void Node::edge(string str1, string str2){
    if(idx.count(str1) == 0){
        idx.insert(pair<string, int>(str1, size));
        size++;
    }
    if(idx.count(str2) == 0){
        idx.insert(pair<string, int>(str2, size));
        size++;
    }
    adj[idx[str1]].push_back(str2);
    //cout << idx[str1] << " " << idx[str2] << endl;
}

void Node::preSort(string str){
    visit[idx[str]] = true;

    for(string s : adj[idx[str]]){
        if(!visit[idx[s]]){
            cout << s << " ";
        }
    }
    for(string s : adj[idx[str]]){
        if(!visit[idx[s]]){
            preSort(s);
        }
    }
}

/**
 * @brief Preforms setup and sorting operations on the graph
 *
 * Sorts a preassembled graph by traversing though a list of verticies and edges
 *
 *
 * @return void
 */

void Node::sort(){
    stack<string> starts;
    for(int x = 0; x < size; x++){
        visit[x] = false;
    }
    
    for(pair<string, int> p : idx){
        for(string s : adj[p.second]){
            visit[idx[s]] = true;
        }
    }
    for(pair<string, int> p : idx){
        if(!visit[p.second])
            starts.push(p.first);
    }

    for(int x = 0; x < size; x++){
        visit[x] = false;
    } 
    while(!starts.empty()){
        cout << starts.top() << " ";
        preSort(starts.top());
        starts.pop();
    }

    cout << endl;
    //cout << size << endl;
}
/**
 * @brief Organizes the file input, sorting, and desired output
 *
 * This function computes the average using the standard accepted
 * formula for doing so.
 *
 * @return Error codes
 * @param argc The number of command line parameters.
 * @param argv Stored parameters.
 *
 */
int main(int argc, char** argv){

    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1], ifstream::binary);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }
    string s1 = "";
    string s2 = "";
    queue<string> str1;
    queue<string> str2;
    int count = 0;
    while(true){
        file >> s1;
        file >> s2;
        if(s1 == "0" && s2 == "0")
           break;
        str1.push(s1);
        str2.push(s2);
        count++;
    }
    Node node(count);
    for(int x = 0; x < count; x++){
        node.edge(str1.front(), str2.front());
        //cout << str1.front() << " " << str2.front() << endl;
        str1.pop();
        str2.pop();
    }
    
    node.sort();
    return 0;
}
