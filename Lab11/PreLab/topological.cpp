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
    int size; /*@var Number of verticies. */
    map<string, int> idx; /*@var Storage of string verticies to respective indicies. */
    list<string>* adj; /*@var Storage list of edges for each vertex. */
    bool* visit; /*@var Storage array for visited verticies. */
    void preSort(string str); 

public:
    string first;
    Node(int i, map<string, int>);
    ~Node();
    void edge(string str1, string str2);
    void sort();
};


/**
 * @class Node
 * @brief Creates an empty graph of size <= i
 *
 * This function computes the average using the standard accepted
 * formula for doing so.
 *
 * @return A Node object
 * @param i Number of verticies.
 * @param m The passed string to index map.
 *
 */
Node::Node(int i, map<string, int> m){
    size = i;
    idx = m;
    adj = new list<string>[i];
    visit = new bool[i];
}
/**
 * @brief Default destructor for Node class.
 *
 *
 *
 *
 * @return Nothing
 *
 */
Node::~Node(){
    //delete adj;
    //delete visit;
 }

/**
 * @brief Inserts an edge connection.
 *
 * Adds the second string to the connections list of the first string.
 *
 * @return void
 * @param str1 Starting vertex.
 * @param str2 Ending vertex.
 *
 */
void Node::edge(string str1, string str2){
    adj[idx[str1]].push_back(str2);
    //cout << idx[str1] << " " << idx[str2] << endl;
}

/**
 * @brief Traverses through the graph
 *
 * Prints out the list items in a traversed order.
 *
 * @return void
 * @param str Starting vertex.
 *
 *
 */
void Node::preSort(string str){
    visit[idx[str]] = true;

    for(string s : adj[idx[str]]){
        if(!visit[idx[s]]){
            cout << s << " ";
        }
    }
    for(string st : adj[idx[str]]){
        if(!visit[idx[st]]){
            preSort(st);
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
    queue<string> starts;
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
    string temp;

    while(!starts.empty()){
        temp = starts.front();
        if(visit[idx[temp]] == false)
            cout << temp << " ";
        //print(temp);
        starts.pop();
        for(string s1 : adj[idx[temp]]){
            if(visit[idx[s1]] == false){
                visit[idx[s1]] = true;
                cout << s1 << " ";
                starts.push(s1);
            }
        }
    }

    cout << endl;
    //cout << size << endl;
}
/**
 * @brief Organizes the file input, sorting, and desired output
 *
 * Takes in file organized verticies and edges, assigns edges to starting verticies, then sorts topologically and prints them out.
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
    map<string, int> m;
    int count = 0;
    while(true){
        file >> s1;
        file >> s2;
        if(s1 == "0" && s2 == "0")
           break;
        str1.push(s1);
        str2.push(s2);
        if(m.count(s1) == 0){
            m.insert(pair<string, int>(s1, count));
            count++;
        }
        if(m.count(s2) == 0){
            m.insert(pair<string, int>(s2, count));
            count++;
        }
    }
    Node node(count, m);
    for(int x = 0; x < count; x++){
        node.edge(str1.front(), str2.front());
        //cout << str1.front() << " " << str2.front() << endl;
        str1.pop();
        str2.pop();
    }
    
    node.sort();
    return 0;
}
