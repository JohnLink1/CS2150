//John Link, jwl9vq@virginia.edu, 11/15/21, huffmanenc.cpp
#include <iostream>
#include "huffmanNode.h"
#include "heap.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <iterator>
#include <map>

using namespace std;

heap buildTree(string contents);

int main(int argc, char** argv){
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // ifstream stands for "input file stream"
    ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

    // read in characters one by one, until reading fails (we hit the end of the file)
    string conts;
    char g;
    while (file.get(g)) {
        conts += g;
    }

    // a nice pretty separator
    cout << "----------------------------------------" << endl;

    file.close();


heap storage = buildTree(conts);

    return 0;
}

heap buildTree(string contents){
    heap h;
    map<char, int> m;
    map<char, int>::iterator itr;
    for(char ch : contents){
        itr = m.find(ch);
        if(itr == m.end()){
            m.insert(pair<char, int>(ch, 1));
        }
        m[ch] = m[ch] + 1;
        cout << ch << endl;
    }
    for(pair<char, int> p : m){
        h.insert(new huffmanNode(p.first, p.second));
    }
    h.print();
}
