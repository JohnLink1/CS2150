//John Link, jwl9vq@virginia.edu, 10/10/21, hashTable.cpp
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cmath>
#include "hashTable.h"

using namespace std;

HashTable::HashTable() : num_ele(54779){
    table = new vector<string>(num_ele);
    for(int x = 0; x < 30; x++){
        offsets[x] = (unsigned int)pow(37, x);
    }
    for(int x = 0; x < num_ele; x++){
        table->push_back("");
    }
}

HashTable::HashTable(int x){
    num_ele = x;
    table = new vector<string>(num_ele);
    for(int x = 0; x < 30; x++){
        offsets[x] = (unsigned int)pow(37, x);
    }
    for(int x = 0; x < num_ele; x++){
        table->push_back("");
    }
}

HashTable::~HashTable(){
    delete table;
    table = NULL;
}

void HashTable::insert(string value){
    int h = hash(value);
    table->at(h) = "," + value + "," + table->at(h);
}

bool HashTable::find(string value){
    int h = hash(value);
    if(table->at(h) != "" && table->at(h).find("," + value + ",") != string::npos){
        return true;
    }
    return false;
}

string HashTable::retrieve(string value){
    int h = hash(value);
    if(find(value)){
        string str = table->at(h);
	return str.substr(str.find(value), str.length() + str.find(value));
    }
    return NULL;
}

int HashTable::hash(string value) const{
    unsigned int k = 0;
    for(int x = 0; x < value.length(); x++){
        k += ((unsigned int)value.at(x)) * offsets[x];
    }
    return (int)(k % num_ele);
}

void HashTable::remove(string value){
    int h = hash(value);
    if(find(value)){
        string str = table->at(h);
        str = str.substr(0, str.find("," + value)) + str.substr(str.find(value) + str.length());
        table->at(h) = str;
    }
}
