//Adam Smith
#include "BSTree.h"

// Constructor
BSTree::BSTree() {
    root = nullptr;
}

// Destructor
BSTree::~BSTree() {
    if (root !=nullptr)
        freeNode(root);
}

// Free the node
void BSTree::freeNode(Node* leaf)
{
    if ( this->Root() == leaf)
    {
        
    }
    else if ( leaf != nullptr )
   
        {
        freeNode(leaf->Left());
        freeNode(leaf->Right());
        delete leaf;
        }
    
}

// Add a node
void BSTree::addNode(int key)
{
    // No elements. Add the root
    if ( root == nullptr ) {
        Node* n = new Node();
        n->setKey(key);
        root = n;
    }
    else {
        addNode(key, root);
    }
}

// Add a node (private)
void BSTree::addNode(int key, Node* leaf) {
    if ( key <= leaf->Key() )
    {
        if ( leaf->Left() != nullptr )
            addNode(key, leaf->Left());
        else {
            Node* n = new Node();
            n->setKey(key);
            n->setParent(leaf);
            leaf->setLeft(n);
        }
    }
    else
    {
        if ( leaf->Right() != nullptr )
            addNode(key, leaf->Right());
        else {
            Node* n = new Node();
            n->setKey(key);
            n->setParent(leaf);
            leaf->setRight(n);
        }
    }
}

// Find a node
Node* BSTree::findNode(int key, Node* node)//pass in root
{
	cout << node->Key();
	if (node == nullptr) {//when key is not found
		cout << key << " not found";
		return nullptr;
	}
	if (key == node->Key()) {//when found
		return node;//returns the search
	}
	else if (key < node->Key()) {//goes to left to search
		return findNode(key, node->Left());
	}
	else if (key > node->Key()) {//goes to right to search
		return findNode(key, node->Right());
	}
	else {
		cout << key << " not found";//when nothing is found
		return nullptr;
	}
}

// Print the BSTree
void BSTree::printPreorder(Node* node)
{
	if (node) {//goes through tree
		cout << node->Key() << " ";//prints out key
		printPreorder(node->Left());//then goes left
		printPreorder(node->Right());//then goes right
	}
}
void BSTree::printInorder(Node* node)
{
	if (node) {//goes through tree
		printInorder(node->Left());//goes left first
		cout << node->Key() << " ";//then prints key
		printInorder(node->Right());//then goes right
	}
    
}

void BSTree::printPostorder(Node* node)
{
    if ( node != nullptr)//if node is not at the end
    {
		printPostorder(node->Left());//go to left
		printPostorder(node->Right());//go to right
		cout << node->Key() << " ";//prints out key
            }
}

// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
Node* BSTree::min(Node* node)
{
    Node* tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Left() )
    {
        tempNode = min(node->Left());
    }
    else
        tempNode = node;
    
    return tempNode;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
Node* BSTree::max(Node* node)
{
    Node * tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Right() )
        tempNode = max(node->Right());
    else
        tempNode = node;
    
    return tempNode;
}

// Find successor to a node
// Find the node, get the node with max value
// for the right sub-BSTree to get the successor
Node* BSTree::successor(int key, Node *node)
{
    

    Node *successor = nullptr;
    Node *current  = root;
    if(root == nullptr)
        return NULL;
    
    while(current->Key() != key){
        /* If node value is greater than the node which are looking for, then go to left sub tree
         Also when we move left, update the successor pointer to keep track of lst left turn */
        
        if(current->Key() >key){
            successor = current;
            current= current->Left();
        }
        /* Else take right turn and no need to update successor pointer */
        else
            current = current->Right();
    }
    /*Once we reached at the node for which inorder successor is to be found, check if it has right sub tree, if yes then find the minimum in that right sub tree and return that node
     
     Else last left turn taken node is already stored in successor pointer and will be returned*/
    if(current && current->Right()){
        successor = min(current->Right());
    }
    
    return successor;
}

// Find predecessor to a node
// Find the node, get the node with max value
// for the left sub-BSTree to get the predecessor
Node* BSTree::predecessor(int key, Node *node)
{
    
    Node* current = findNode(key, node);

    if (current == nullptr)
        { return nullptr; }
    
    if (current->Left() !=nullptr)
    {
        return max(current->Left());
    } else
    
    {
        Node *tempParent = current->Parent();
        while (tempParent !=nullptr) {
            if (current == tempParent->Right() ){
                break;
            }
            current = tempParent;
            tempParent = current->Parent();
        }
        return tempParent;
    }
}


void BSTree::deleteNode(int key)
{
    if (deleteNode(Root(), key) == nullptr)
        setRoot(nullptr);
}

//deleteNode (Private)
Node* BSTree::deleteNode(Node* root,int key)
{
   
    /* Given a binary search tree and a key, this function deletes the key
     and returns the new root */

    
        if(root == nullptr) return root;
        else if(key < root->Key())
            root->setLeft( deleteNode(root->Left(),key));
        else if(key > root->Key())
            root->setRight( deleteNode(root->Right(), key) );
        else {
            // Case 1: No Child
            if(root->Left() == nullptr && root->Right() == nullptr){
                delete root;
                root = nullptr;
                // Case 2: one child
            } else if(root->Left() == nullptr){
                Node *temp = root;
                root = root->Right();
                delete temp;
            } else if(root->Right() == nullptr){
                Node *temp = root;
                root = root->Left();
                delete temp;
            } else{
                Node *temp = min(root->Right());
                root->setKey(temp->Key() );
                root->setRight(  deleteNode(root->Right(), temp->Key() ) );
            }
        }
        return root;
    
}
