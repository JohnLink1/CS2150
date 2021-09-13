//John Link, jwl9vq@virginia.edu, 9/13/21, stackNode.cpp

#include "stackNode.h"
#include "stack.h"
#include <iostream>

using namespace std;

StackNode::StackNode() : next(NULL){

}

StackNode::StackNode(int val) : value(val), next(NULL){

}

