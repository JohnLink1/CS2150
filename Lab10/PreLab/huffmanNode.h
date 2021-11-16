//John Link, jwl9vq@virginia.edu, 11/15/21, huffmanNode.h
#include <iostream>
#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

using namespace std;

class huffmanNode{
    public:
        huffmanNode();
        huffmanNode(char ch, int prio);
        ~huffmanNode();

    private:
        char letter;
        int priority;
        friend class heap;
        friend class huffmanenc;
};
#endif
