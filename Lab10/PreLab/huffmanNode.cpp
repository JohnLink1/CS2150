//John Link, jwl9vq@virginia.edu, 11/15/21, huffmanNode.cpp
#include <iostream>
#include "huffmanNode.h"

using namespace std;

huffmanNode::huffmanNode(){

}

huffmanNode::huffmanNode(char ch, int prio){
   letter = ch;
   priority = prio;
}

huffmanNode::~huffmanNode(){
}
