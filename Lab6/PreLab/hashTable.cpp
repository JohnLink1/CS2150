//John Link, jwl9vq@virginia.edu, 10/10/21, hashTable.cpp
#include <iostream>
#include <string>
#include <list>
#include "hashTable.h"

using namespace std;

HashNode::HashNode(){

}

HashNode::HashNode(int x, string y){
    key = x;
    value = y;
}

HashTable::HashTable(){
    num_ele = 0;
    table = NULL;
}

HashTable::HashTable(int x){
    num_ele = x;
    table = new list<HashNode*>[num_ele];
}

HashTable::~HashTable(){
    delete table;
    table = NULL;
}

void HashTable::insert(int key, string value){
    table[hash(key)].push_back(new HashNode(key, value));
}

int HashTable::hash(int key) const{
    return key % num_ele;
}

void HashTable::remove(int key){

}
