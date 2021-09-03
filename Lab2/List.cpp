//John Link, jwl9vq@virginia.edu, 9/2/21, List.cpp

#include <iostream>
#include "List.h"

using namespace std;

List::List(const List::List& source == null) : head(source), tail(null), count(0){

}

List::isEmpty(){
    if(count == 0){
        return true;
    }
    return false;
}

List::makeEmpty(){

}
