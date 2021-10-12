//John Link, jwl9vq@virginia.edu, 10/10/21, hashTable.cpp
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cmath>
#include "hashTable.h"

using namespace std;

HashTable::HashTable(){
    num_ele = 200;
    table = new vector<string*>(num_ele);
    for(int x = 0; x < 30; x++){
        offsets[x] = (int)pow(37, x);
    }
}

HashTable::HashTable(int x){
    num_ele = x;
    table = new vector<string*>(num_ele);
    for(int x = 0; x < 30; x++){
        offsets[x] = (int)pow(37, x);
    }
}

HashTable::~HashTable(){
    delete table;
    table = NULL;
}

void HashTable::insert(string value){
    int h = hash(value);
    if(!find(value)){
        //vector<string>::const_iterator it = table->begin();
        table->insert(table->begin() + h - 1, new string(value));
    }
}

bool HashTable::find(string value){
    int h = hash(value);
    if(table->at(h) != NULL){
        return true;
    }
    return false;
}

int HashTable::hash(string value) const{
    int k = 0;
    for(int x = 0; x < value.length(); x++){
        k += (int)value.at(x) * offsets[x];
    }
    return k % num_ele;
}

void HashTable::remove(string value){
    int h = hash(value);
    if(!find(value)){
        //vector<string>::const_iterator it = table->begin();
        delete table->at(h);
        table->insert(table->begin() + h - 1, NULL);
    }
}
