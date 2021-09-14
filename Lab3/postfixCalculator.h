//John Link, jwl9vq@virginia.edu, 9/10/21, postfixCalculator.h
#ifndef POSTFIXCALCULATOR
#define POSTFIXCALCULATOR
#include "stack.h"

#include <string>

using namespace std;

class PostFCalc {
public:
    PostFCalc();
    PostFCalc(string str);
    ~PostFCalc();

    bool isOperator(string ch);
    int maths(int x, int y, string op);
    int calculate(string str);
    void print(int finval);

private:
    Stack staq;
};
#endif
