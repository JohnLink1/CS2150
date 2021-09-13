//John Link, jwl9vq@virginia.edu, 9/13/21, stackNode.h

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

using namespace std;

class StackNode {
public:
    StackNode();
    StackNode(int val);

private: 
    int value;
    StackNode* next;
    friend class Stack;

};
#endif
