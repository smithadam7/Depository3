#ifndef BSTREE_
#define BSTREE_
#include <iostream>
using namespace std;
#include "Node.h"

// Binary Search Tree class
class BSTree {
private:
    Node* root;
    void addNode(string key, Node* leaf,Node*x);
    Node* deleteNode(Node* node, string key);
    void freeNode(Node* leaf);
public:
    BSTree();
    ~BSTree();
    Node* Root() { return root; }
    void setRoot(Node * _root) {root = _root;}
    void addNode(string key,Node*x);
    Node* findNode(string key, Node* parent);
    void printPreorder(Node* node);
    void printInorder(Node* node);
    void printPostorder(Node* node);
    

    void deleteNode(string key);

    Node* min(Node* node);
    Node* max(Node* node);
    Node* successor(string key, Node* parent);
    Node* predecessor(string key, Node* parent);
	//Custom functions:
	Node* findNodeEdit(string key, Node*parent);

};
#endif  //BST
