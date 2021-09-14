//John Link, jwl9vq@virginia.edu, 9/10/21, postfixCalculator.cpp

#include "postfixCalculator.h"
#include "stack.h"
#include <iostream>
#include <string>

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
    int x = 0;
    int y = 0;
    string temp = "";
    while(str.length() !=0){
	
	temp = "";
        while(str.substr(0, 1) != " " && str.length() !=0){
            temp = temp + str.substr(0, 1);
            str = str.substr(1);
        }
        if(str.length() != 0)
            str = str.substr(1);
        
        if(temp.length() == 1 && isOperator(temp)){
            if(temp == "~"){
		if(!staq.isEmpty()){
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
		if(!staq.isEmpty()){
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
            staq.push(maths(x, y, temp));
        }
        else{
            staq.push(stoi(temp));
        }
    }
    if(!staq.isEmpty()){
        return staq.top();
    }
    return -1;
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
