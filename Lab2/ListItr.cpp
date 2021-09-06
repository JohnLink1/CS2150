//John Link, jwl9vq@virginia.edu, 9/2/21, ListItr.cpp

#include <iostream>
#include "ListItr.h"

using namespace std;

ListItr::ListItr() : current(new ListNode){

}

ListItr::ListItr(ListNode* theNode) : current(theNode){

}

bool ListItr::isPastEnd() const{
    if(current->next == NULL){
        return true;
    }
    return false;
}

bool ListItr::isPastBeginning() const{
    if(current->previous == NULL){
        return true;
    }
    return false;
}

void ListItr::moveForward(){
    if(!isPastEnd()){
        current = current->next;
    }
}

void ListItr::moveBackward(){
    if(!isPastBeginning()){
        current = current->previous;
    }
}

int ListItr::retrieve() const{
    return current->value;
}

void printList(List& source, bool forward){
    if(forward){
        ListItr itr = source.first();
        while(!itr.isPastEnd()){
            cout << itr.retrieve() << " ";
            itr.moveForward();
        }
    cout << endl;
    return;
    }
    ListItr itr = source.last();
    while(!itr.isPastBeginning()){
        cout << itr.retrieve() << " ";
        itr.moveBackward();
    }
    cout << endl;
}
