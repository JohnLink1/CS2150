//John Link, jwl9vq@virginia.edu, 10/10/21, wordPuzzle.cpp
#include <iostream>
#include <string>
#include <fstream>
#include "hashTable.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];
unsigned long long gen[23] = {1, 7, 49, 343, 2401, 16807, 117649, 823543, 5764801, 40353607, 282475249, 1977326743, 13841287201, 96889010407, 678223072849, 4747561509943, 33232930569601, 232630513987207, 1628413597910449, 11398895185373144, 79792266297612000, 558545864083284000, 3909821048582988000};
void addWordstoDict();
string getWordInGrid(int startRow, int startCol, int dir, int len, int numRws, int numCols);
bool readInGrid(string filename, int& rows, int& cols);
int getKey(string s);


int main(int argc, char **args){
argc = 2;
if(args[1] == NULL || args[2] == NULL){
    cout << "Invalid arguments given should be: output dictionary.txt grid.txt" << endl;
    abort();
}
HashTable t(20000);
string dicfile = args[1];
string gridfile = args[2];
//set cin file to dictionary
string instr;
ofstream file;
file.open(dicfile);
while(cin.good()){
    cin >> instr;
    if(instr.length() > 2){
        t.insert(getKey(instr), instr);
    }
}
file.close();

file.open(gridfile);

//set cin file to grid
string gridConts;
cin >> instr;
int rows = stoi(instr);
cin >> instr;
int cols = stoi(instr);
cin >> gridConts;
    
file.close();

readInGrid(gridConts, rows, cols);


}

int getKey(string s){
    int k = 0;
    for(int x = 0; x < s.length(); x++){
        k += s.at(x) * gen[x];
    }
    return k;
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
