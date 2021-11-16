// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository
// Used by John Link, jwl9vq@virginia.edu, 11/15/21, store_heap.cpp
#include <iostream>
#include "heap.h"
#include "huffmanNode.h"
using namespace std;

// default constructor
heap::heap() : heap_size(0) {
    store_heap.push_back(new huffmanNode());
}

// builds a store_heap from an unsorted vector
heap::heap(vector<huffmanNode> vec) : heap_size(vec.size()) {
    store_heap = vec;
    store_heap.push_back(store_heap[0]);
    store_heap[0] = NULL;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(huffmanNode h) {
    // a vector push_back will resize as necessary
    store_heap.push_back(h);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    huffmanNode x = store_heap[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (x.priority < store_heap[hole/2].priority); hole /= 2) {
        store_heap[hole] = store_heap[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    store_heap[hole] = x;
}

huffmanNode heap::deleteMin() {
    // make sure the store_heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    huffmanNode ret = store_heap[1];
    // move the last inserted position into the root
    store_heap[1] = store_heap[heap_size--];
    // make sure the vector knows that there is one less element
    store_heap.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    huffmanNode x = store_heap[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (store_heap[child+1].priority < store_heap[child].priority)) {
            child++;
        }
        // if the child is greater than the node...
        if (x.priority > store_heap[child].priority) {
            store_heap[hole] = store_heap[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    store_heap[hole] = x;
}

huffmanNode heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return store_heap[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    store_heap.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << store_heap[0].letter << ") ";
    for (int i = 1; i <= heap_size; i++) {
        cout << store_heap[i].letter << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}
