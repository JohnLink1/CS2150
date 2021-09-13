//John Link, jwl9vq@virginia.edu, 9/13/21, stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>

#include "stackNode.h"

using namespace std;


class Stack {
  public:
    Stack();                // constructor
    ~Stack();               // destructor
    bool isEmpty() const;   // checks for empty
    void push(int value);   // push value onto stack
    void pop();             // pop top of stack
    int top() const;        // returns topOfStack
    

  private:
    StackNode *head;        // like a ListNode...
};
#endif
