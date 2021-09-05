//John Link, jwl9vq@virginia.edu, 9/2/21, List.cpp

#include <iostream>
#include "List.h"

using namespace std;

List::List() : head(new ListNode), tail(new ListNode), count(0){
    (*head).next = tail;
    (*tail).previous = head;
}
List::List(const List& source) : head(new ListNode), tail(new ListNode), count(source.size()){
    
}

List::~List(){

}

List& List::operator=(const List& source){

}

bool List::isEmpty() const{
    return false;
}

void List::makeEmpty(){

}

ListItr List::last(){
    ListItr itr(tail);
    if(count == 0){
	return itr;
    }
    while(!itr.isPastEnd()){
        itr.moveForward();
    }
    itr.moveBackward();
    return itr;
}

ListItr List::first(){
    ListItr itr(head);
    if(count == 0){
        return itr;
    }
    while(!itr.isPastBeginning()){
        itr.moveBackward();
    }
    itr.moveForward();
    return itr;
}

void List::insertAfter(int x, ListItr position){

}

void List::insertBefore(int x, ListItr position){

}

void List::insertAtTail(int x){
    ListItr itr = last();
    itr.moveForward();
    (*itr.current).value = x;
    (*itr.current).next = new ListNode;
    (*(*itr.current).next).previous = itr.current;
    count++;
}

ListItr List::find(int x){

}

void List::remove(int x){

}

int List::size() const{
    return count;
}



