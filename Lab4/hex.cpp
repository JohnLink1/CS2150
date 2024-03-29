// This should be compiled with the -m32 flag, so as to make the
// pointer a 32-bit memory address.

#include <iostream>
using namespace std;

union foo {
    double f;
    int *x;
} bar;

int main() {
    bar.f = 1;
    int* g = NULL;
    cout << *g << endl;
    cout << bar.x << endl; // prints in big-endian
    return 0;
}
