//John Link, jwl9vq@virginia.edu, 9/10/21, postfixCalculator.cpp

#include "postfixCalculator.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

PostFCalc::PostFCalc() : staq() {

}

PostFCalc::PostFCalc(string str) : staq(){

    calculate(str);

}

PostFCalc::~PostFCalc(){

}

bool PostFCalc::isOperator(string ch){
    if(ch == "+" || ch == "-" || ch == "*" || ch == "/" || ch == "~"){
        return true;
    }

    return false;
}

int PostFCalc::calculate(string str){

    vector<string> vec = toVector(str);
    int val = 0;
    int x = 0;
    int y = 0;
    for(int itr = 0; itr < vec.size(); itr++){
        if(vec.at(itr).length() == 1 && isOperator(vec.at(itr))){
            if(vec.at(itr) == "~"){
		if(!staq.empty()){
                    x = staq.top();
                    staq.pop();
                    y = 0;
		}
		else{
		    cout << "Error, empty stack, cannot pop" << endl;
		    return -1;
		}
		    
            }
            else{
		if(!staq.empty()){
                    x = staq.top();
                    staq.pop();
                    y = staq.top();
                    staq.pop();
		}
		else{
		    cout << "Error, empty stack cannot pop" << endl;
		    return -1;
		}
            }
            staq.push(maths(x, y, vec.at(itr)));
        }
        else{
            val = stoi(vec.at(itr));
            staq.push(val);
        }
    }
    if(!staq.empty()){
        return staq.top();
    }
    return -1;
}
vector<string> PostFCalc::toVector(string str){
    vector<string> vec;
    string temp = "";
    while(str.length() != 0){
        temp = "";
        while(str.substr(0, 1) != " " && str.length() !=0){
            temp = temp + str.substr(0, 1);
            str = str.substr(1);
        }
        vec.push_back(temp);
        if(str.length() != 0)
            str = str.substr(1);
    }
    return vec;
}

int PostFCalc::maths(int x, int y, string op){
    if(op == "+"){
        return x + y;
    }
    else if(op == "-"){
        return y - x;
    }
    else if(op == "*"){
        return x * y;
    }
    else if(op == "/"){
        return y / x;
    }
    else if(op == "~"){
        return x * -1;
    }

    return 0;
}

void PostFCalc::print(int x){
    cout << x << endl;
}
