// Adam Smith
// HW7
// Last Modified 03-20-17
// Built and ran successfully on Visual Studio
#include <iostream>
#include <string>
#include "BSTree.h"
using namespace std;

int main()
{
	BSTree *tree1 = new BSTree();//creates the new binary search tree

	//Adds some numbers to the tree
	cout << "Adding 300\n";
	tree1->addNode(300);
	cout << "Adding 100\n";
	tree1->addNode(100);
	cout << "Adding 200\n";
	tree1->addNode(200);
	cout << "Adding 400\n";
	tree1->addNode(400);

	//Prints the tree in different ways
	cout << "Preorder Print:\n";
	tree1->printPreorder(tree1->Root());
	cout << endl<<"\nInorder Print:\n";
	tree1->printInorder(tree1->Root());
	cout << endl<<"\nPostorder Print\n";
	tree1->printPostorder(tree1->Root());

	//Searches the tree 
	cout << endl<<endl;
	tree1->findNode(500, tree1->Root());
	cout << endl;
	tree1->findNode(600, tree1->Root());

	//MIN and Max in tree
	cout << "\nMIN: ";
	cout << tree1->min(tree1->Root())->Key();
	cout << "\nMAX: ";
	cout << tree1->max(tree1->Root())->Key();

	//Successor and Predecessor
	cout << endl << "\nSuccessor to 300=" << tree1->successor(300, tree1->Root())->Key();
	cout << "\nPredecessor to 300=" << tree1->predecessor(300, tree1->Root())->Key();

	//Delete node
	cout << "\nDeleting 300\n";
	tree1->deleteNode(300);//this is private in the class

	//Print preorder after delete
	cout << "\nPreorder Print:\n";
	tree1->printPreorder(tree1->Root());

	cout << "\n\nDeleting Entire Tree Pointer\nPress enter key to continue\n";
	//deletes the tree
	delete tree1;

	string hold;
	getline(cin, hold);
	return 0;
}