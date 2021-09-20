// This should be compiled with the -m32 flag, so as to make the
// pointer a 32-bit memory address.

#include <iostream>
using namespace std;

union foo {
    double* f = NULL;
    int *x;
} bar;

int main() {
    
    cout << bar.x << endl; // prints in big-endian
    return 0;
}
