//John Link, jwl9vq@virginia.edu, 11/15/21, huffmanenc.cpp
#include <iostream>
#include "huffmanNode.h"
#include "heap.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <iterator>
#include <map>
#include <iomanip>

using namespace std;

heap buildHeap(string contents);
huffmanNode* buildTree(heap h);
map<char, string> getCodes(huffmanNode* root);
map<char, int> frequency;
bool find(huffmanNode* root, char ch);
string pathTo(huffmanNode* root, char ch);

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
        if(int(g) >= 32 && int(g) <= 126)
            conts += g;
    }

    file.close();
    heap storage = buildHeap(conts);
    huffmanNode* root = buildTree(storage);
    map<char, string> codes = getCodes(root);
    string encoded = "";
    for(char ch : conts){
        encoded += codes[ch];
    }
    // a nice pretty separator
    cout << "----------------------------------------" << endl;
    cout << encoded << endl;
    // a nice pretty separator
    cout << "----------------------------------------" << endl;
    double oribits = conts.length() * 8;
    double encbits = encoded.length();
    double comprto = oribits / encbits;
    double cost = encbits / conts.length();
    cout << "There are a total of " << conts.length() << " symbols that are encoded." << endl;
    cout << "There are " << codes.size() << " distinct symbols used." << endl;
    cout << "There were " << oribits << " bits in the original file." << endl;
    cout << "There were " << encbits << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << setprecision(6) << comprto << "." << endl;
    cout << "The cost of the Huffman tree is " << setprecision(6) << cost << " bits per character." << endl;

    return 0;
}

map<char, string> getCodes(huffmanNode* root){
    map<char, string> codes;
    for(pair<char, int> p : frequency){
        codes.insert(pair<char, string>(p.first, pathTo(root, p.first)));
        if(p.first == ' ')
            cout << "space " << codes[p.first] << endl;
        else
            cout << p.first << " " << codes[p.first] << endl;
    }
    return codes;
}
string pathTo(huffmanNode* root, char ch){
    if(root == NULL)
        return "";
    if(root->letter == ch)
        return "";
    if(find(root->left, ch))
        return "0" + pathTo(root->left, ch);
    if(find(root->right, ch))
        return "1" + pathTo(root->right, ch);
    return "";
}


bool find(huffmanNode* root, char ch){
    if(root == NULL)
        return false;
    if(root->letter == ch)
        return true;
    if(root->left != NULL and root->right != NULL)
        return find(root->left, ch) || find(root->right, ch);
    if(root->left != NULL)
        return find(root->left, ch);
    if(root->right != NULL)
        return find(root->right, ch);
    return false;
}

heap buildHeap(string contents){
    heap h;
    map<char, int> m;
    map<char, int>::iterator itr;
    for(char ch : contents){
        itr = m.find(ch);
        if(itr == m.end()){
            m.insert(pair<char, int>(ch, 1));
        }
        m[ch] = m[ch] + 1;
    }
    frequency = m;
    for(pair<char, int> p : m){
        h.insert(new huffmanNode(p.first, p.second));
    }
    return h;
}

huffmanNode* buildTree(heap h){
    while(!h.isEmpty()){
        huffmanNode* top = new huffmanNode();
        if(h.size() == 1)
            return h.deleteMin();
        top->left = h.deleteMin();
        top->right = h.deleteMin();
        top->priority = top->left->priority + top->right->priority;
        h.insert(top);
    }
    return new huffmanNode();
}
