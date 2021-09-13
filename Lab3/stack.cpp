//John Link jwl9vq@virginia.edu, 9/13/21, stack.cpp

#include "stack.h"
#include "stackNode.h"

using namespace std;

Stack::Stack() : head(NULL){

}

Stack::~Stack(){

}

bool Stack::isEmpty() const{
    if(head == NULL){
        return true;
    }
    return false;
}

void Stack::push(int val){
    StackNode* node = new StackNode(val);
    node->next = head;
    head = node;
}

void Stack::pop(){
    StackNode* next = head->next;
    delete head;
    head = next;
}

int Stack::top() const{
    return head->value;
}
