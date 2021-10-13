//John Link, jwl9vq@virginia.edu, 10/10/21, wordPuzzle.cpp
#include <iostream>
#include <string>
#include <fstream>
#include "hashTable.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];
string getWordInGrid(int startRow, int startCol, int dir, int len, int numRws, int numCols);
bool readInGrid(string filename, int& rows, int& cols);
string getDir(int x);

int main(int argc, char **args){
argc = 2;
if(args[1] == NULL || args[2] == NULL){
    cout << "Invalid arguments given should be: output dictionary.txt grid.txt" << endl;
    abort();
}
HashTable* t = new HashTable();
string dicfile = args[1];
string gridfile = args[2];
//set cin file to dictionary
cout << "pre add dict" << endl;
string instr;
ifstream file;
file.open(dicfile);
while(file.good()){
    file >> instr;
    cout << instr << endl;
    if(instr.length() > 2 && instr.length() < 25){
        t->insert(instr);
    }
}
file.close();
cout << "added to dict" << endl;
file.open(gridfile);

//set cin file to grid
string gridConts;
file >> instr;
int rows = stoi(instr);
file >> instr;
int cols = stoi(instr);
file >> gridConts;
    
file.close();
cout << "read grid file" << endl;
readInGrid(gridConts, rows, cols);
cout << "created grid" << endl;
string word = "";
    for(int x = 0; x < rows; x++){
        for(int y = 0; y < cols; y++){
            for(int i = 0; i < 8; i++){
                for(int j = 3; j < 22; j++){
                    if(word == getWordInGrid(x, y, i, j, rows, cols)){
                        break;
                    }
                    word = getWordInGrid(x, y, i, j, rows, cols);
                    if(t->find(word)){
                        cout << getDir(i) << "\t(" << x << ", " << y << "):\t" << word << endl;;
                    }
                }
            }
        }
    }


}

bool readInGrid(string data, int& rows, int& cols) {
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            cout << grid[r][c];
        }
        cout << endl;
    }
    return true;
}

string getDir(int x){
        switch (x) { // assumes grid[0][0] is in the upper-left
            case 0:
                return "N";
            case 1:
                return "NE";
            case 2:
                return "E";
            case 3:
                return "SE";
            case 4:
                return "S";
            case 5:
                return "E";
            case 6:
                return "W";
            case 7:
                return "NW";
        }
    return "";
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}
