//John Link, jwl9vq@virginia.edu, 10/05/2021, AVLTree.cpp
#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

// insert finds a position for x in the tree and places it there, rebalancing
// as necessary.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
    if(find(x))
        return;
    insert(root, x);
}

void AVLTree::insert(AVLNode*& root, const string& x){
    if(root == NULL){
        root = new AVLNode();
        root->value = x;
        root->height = 0;
    }
    else if(root->value.compare(x) > 0){
        insert(root->left, x);
        root->height = depth(root);
        balance(root);
    }
    else if(root->value.compare(x) < 0){
        insert(root->right, x);
        root->height = depth(root);
        balance(root);
    }
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
    balance(root);
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    if(!find(x))
        return "";
    return pathTo(root, x);
}

string AVLTree::pathTo(AVLNode* root, const string& x) const{
    if(root == NULL){
        return "";
    }
    if(root->value.compare(x) == 0){
        return root->value;
    }
    if(root->value.compare(x) > 0){
        return root->value + " " + pathTo(root->left, x);
    }
    if(root->value.compare(x) < 0)
        return root->value + " " + pathTo(root->right, x);
    return "";
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
    return find(root, x);
}

bool AVLTree::find(AVLNode* root, const string& x) const {
    if(root == NULL){
        return false;
    }
    if(root->value == x){
        return true;
    }
    if(root->value.compare(x) > 0){
        return find(root->left, x);
    }
    if(root->value.compare(x) < 0)
        return find(root->right, x);
    return false;
}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
    return numNodes(root);
}

int AVLTree::numNodes(AVLNode* root) const {
    if(root == NULL){
        return 0;
    }
    return 1 + numNodes(root->left) + numNodes(root->right);
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    if(balanceFactor(n) >= 2){
        if(balanceFactor(n->right) < 0){
            n->right = rotateRight(n->right);
            //cout << "lright" << endl;
        }
        n = rotateLeft(n);
        //cout << "left" << endl;
    }
    else if(balanceFactor(n) <= -2){
        if(balanceFactor(n->left) > 0){
            n->left = rotateLeft(n->left);
            //cout << "rleft" << endl;
        }
        n = rotateRight(n);
        //cout << "right" << endl;
    }
     printTree();
}

int AVLTree::balanceFactor(AVLNode* x) const{
    if(x == NULL)
        return 0;
    //cout << depth(x->right) - depth(x->left) << endl;
    return height(x->right) - height(x->left);
}

int AVLTree::depth(AVLNode* x) const{
    if(x == NULL)
        return 0;
    if(x->left == NULL && x->right == NULL)
        return 0;
    return max(depth(x->left), depth(x->right)) + 1;
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode* x = n->right;
    n->right = x->left;
    x->left = n;
    x->height += 1;
    n->height -= 1;
    return x;
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) {
    // YOUR IMPLEMENTATION GOES HERE
    AVLNode* x = n->left;
    n->left = x->right;
    x->right = n;
    x->height += 1;
    n->height -= 1;
    return x;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
