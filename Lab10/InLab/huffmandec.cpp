// This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.
//John Link, jwl9vq@virginia.edu, 11/17/21, huffmandec.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
//#include <map>
#include "heap.h"
#include <iterator>
#include <cstdlib>
#include <iomanip>

using namespace std;

//map<string, char> codes;
void insertTree(huffmanNode*& root, char ch, string str);
void decodeBits(huffmanNode* root, string str);

// main(): we want to use parameters
int main (int argc, char** argv) {
    huffmanNode* root = new huffmanNode();
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        insertTree(root, character.at(0), prefix);
        //codes.insert(pair<string, char>(prefix, character.at(0)));
    }

    // read in the second section of the file: the encoded message
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        //cout << codes[bits];
        decodeBits(root, bits);
    }

    // at this point, all the bits are in the 'allbits' string
    // close the file before exiting
    file.close();
    cout << endl;

    return 0;
}

void decodeBits(huffmanNode* root, string str){
    if(str.length() > 0){
        if(str.at(str.length() - 1) == '0'){
            decodeBits(root->left, str.substr(0, str.length()-1));
        }
        else if(str.at(str.length() - 1) == '1'){
            decodeBits(root->right, str.substr(0, str.length()-1));
        }
    }
    else{
        cout << root->letter;
    }
}

void insertTree(huffmanNode*& root, char ch, string str){
    if(str.length() > 0){
        if(str.at(str.length() - 1) == '0'){
            if(root->left == NULL)
                root->left = new huffmanNode();
            insertTree(root->left, ch, str.substr(0, str.length()-1));
        }
        else if(str.at(str.length() - 1) == '1'){
            if(root->right == NULL)
                root->right = new huffmanNode();
            insertTree(root->right, ch, str.substr(0, str.length()-1));
        }
    }
    else{
        root->letter = ch;
    }
}
