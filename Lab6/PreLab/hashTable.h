//John Link, jwl9vq@virginia.edu, 10/10/21, hashTable.h
#include <iostream>
#include <string>
#include <list>

using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

class HashNode {
    public:
        HashNode();
        HashNode(int x, string y);
        ~HashNode();
    private:
        int key;
        string value;
};


class HashTable {

public:
    HashTable();
    HashTable(int x);
    ~HashTable();
    void insert(int key, string value);
    void remove(int key);

private:
    list<HashNode*> *table;
    int num_ele;
    int hash(int key) const;

};
#endif
