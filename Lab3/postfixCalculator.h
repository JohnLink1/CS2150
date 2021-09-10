//John Link, jwl9vq@virginia.edu, 9/10/21, postfixCalculator.h
#ifndef POSTFIXCALCULATOR
#define POSTFIXCALCULATOR
#include <stack>
#include <string>
#include <vector>

using namespace std;

class PostFCalc {
public:
    PostFCalc();
    PostFCalc(string str);
    ~PostFCalc();

    bool isOperator(string ch);
    vector<string> toVector(string str);
    int maths(int x, int y, string op);
    int calculate(string str);
    void print(int finval);

private:
    stack<int> staq;
};
#endif
