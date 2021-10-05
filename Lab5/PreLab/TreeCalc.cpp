//John Link, jwl9vq@virginia.edu, 9/29/21, TreeCalc.cpp
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
}


// Destructor - frees memory
TreeCalc::~TreeCalc() {
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
    if(tree->left != NULL && tree->right != NULL){
        cleanTree(tree->left);
        cleanTree(tree->right);
    }
    else if(tree->left != NULL){
        cleanTree(tree->left);
    }
    else if(tree->right != NULL)
        cleanTree(tree->right);
    delete tree;
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    if(val == "/" || val == "*" || val == "-" || val == "+"){
        TreeNode * tree = new TreeNode(val);
        if(!expressionStack.empty()){
            tree->right = expressionStack.top();
            expressionStack.pop();
        }
        if(!expressionStack.empty()){
            tree->left = expressionStack.top();
            expressionStack.pop();
        }
        expressionStack.push(tree);
    }
    else
        expressionStack.push(new TreeNode(val));
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
    if(tree->left != NULL && tree->right != NULL){
        cout << tree->value << " ";
        printPrefix(tree->left);
        cout << " ";
        printPrefix(tree->right);
    }
    else if(tree->left != NULL){
        cout << tree->value << " ";
        printPrefix(tree->left);
    }
    else if(tree->right != NULL){
        cout << tree->value << " ";
        printPrefix(tree->right);
    }
    else
        cout << tree->value;
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
    if(tree->left != NULL && tree->right != NULL){
        cout << "(";
        printInfix(tree->left);
        cout << " " << tree->value << " ";
        printInfix(tree->right);
        cout << ")";
    }
    else if(tree->left != NULL){
        cout << "(";
        printInfix(tree->left);
        cout << " " << tree->value;
    }
    else if(tree->right != NULL){
        cout << tree->value << " ";
        printInfix(tree->right);
        cout << ")";
    }
    else
        cout << tree->value;
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
    if(tree->left != NULL && tree->right != NULL){
        printPostfix(tree->left);
        cout<< " ";
        printPostfix(tree->right);
        cout << " " << tree->value;
    }
    else if(tree->left != NULL){
        printPostfix(tree->left);
        cout << " " << tree->value;
    }
    else if(tree->right != NULL){
        printInfix(tree->right);
        cout << " " << tree->value;
    }
    else
        cout << tree->value;
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
    if(tree->left == NULL && tree->right == NULL){
        return stoi(tree->value, nullptr);
    }
    if(tree->value == "+"){
        return calculate(tree->left) + calculate(tree->right);
    }
    if(tree->value == "/"){
        return calculate(tree->left) / calculate(tree->right);
    }
    if(tree->value == "*"){
        return calculate(tree->left) * calculate(tree->right);
    }
    if(tree->value == "-"){
        return calculate(tree->left) - calculate(tree->right);
    }

    return 0;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
    int count = 0;
    if(!expressionStack.empty()){
        TreeNode* tree = expressionStack.top();
        expressionStack.pop();
        count = calculate(tree);
        cleanTree(tree);
    }
    return count;
}
