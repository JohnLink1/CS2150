//John Link, jwl9vq@virginia.edu, 9/10/21, testPostfixCalc.cpp

#include <iostream>
#include "postfixCalculator.h"
#include <string>

using namespace std;

int main(){
    PostFCalc pf;
    string input;
    getline(cin, input);
    cout << pf.calculate(input) << endl;
}
