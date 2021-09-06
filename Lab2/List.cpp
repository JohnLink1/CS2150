//John Link, jwl9vq@virginia.edu, 9/2/21, List.cpp

#include <iostream>
#include "List.h"

using namespace std;

List::List() : head(new ListNode), tail(new ListNode), count(0){
    head->next = tail;
    tail->previous = head;
}
List::List(const List& source) : head(new ListNode), tail(new ListNode), count(source.size()){
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List(){

}

List& List::operator=(const List& source){
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
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
    (itr.current)->value = x;
    (itr.current)->next = new ListNode;
    ((itr.current)->next)->previous = itr.current;
    tail = (itr.current)->next;
    count++;
}

ListItr List::find(int x){
    ListItr itr(head);
    while(!itr.isPastEnd() && (itr.current)->value != x){
        itr.moveForward();
    }
    if((itr.current)->value == x)
        return itr;
    return itr;
}

void List::remove(int x){

}

int List::size() const{
    return count;
}



