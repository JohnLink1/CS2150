//John Link, jwl9vq@virginia.edu, 11/1/21, threexinput.cpp

#include <iostream>
#include "timer.h"
using namespace std;

extern "C" int collatz(int x);

int main() {

    int value;
    // prompt for a number
    cout << "Enter a number: ";
    cin >> value;

    int itr;
    // prompt for a number
    cout << "Enter iterations of subroutine: ";
    cin >> itr;
    timer t;
    int steps = collatz(value);

    t.start();
    for(int x = 0; x < itr; x++){
        collatz(value);
    }
    t.stop();
    //cout << (t.getTime()* 1000000000) / itr << " nanoseconds" << endl;
    cout << "Steps: " << steps << endl;

    return 0;

}
