//John Link, jwl9vq@virginia.edu, 11/23/21, topological.cpp
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

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
    
    string s1, s2;
    file >> s1;
    file >> s2;
    
    

    return 0;
}
