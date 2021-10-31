//John Link, jwl9vq@virginia.edu, 10/29/21, mathfun.cpp
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);

int  main () {

    // delcare the local variables
    long  n1, n2, prod, pow;

    // how big is the array we want to use?
    cout << "Enter integer 1: ";
    cin >> n1;
    cout << "Enter integer 2: ";
    cin >> n2;

    // sanity check the array size
    if (n1 < 0 && n2 < 0) {
        cerr << "Numbers must be greater than zero.\n";
        return 1;
    }

    // sum up the array and print out results
    prod = product(n1, n2);
    cout << "Product: " << prod << endl;

    pow = power(n1, n2);
    cout << "Power: " << pow << endl;

    return 0;
}
