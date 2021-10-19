//John Link, jwl9vq@virginia.edu, 10/10/21, hashTable.h
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashTable {

public:
    HashTable();
    HashTable(int x);
    ~HashTable();
    void insert(string value);
    void remove(string value);
    bool find(string value);
    string retrieve(string value);
    string at(int idx);

private:
    vector<string>* table;
    unsigned int offsets[30];
    int num_ele;
    int hash(string value) const;

};
#endif
