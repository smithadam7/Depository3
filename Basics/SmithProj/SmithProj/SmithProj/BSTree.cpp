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
void BSTree::addNode(string key,Node*x)
{
    // No elements. Add the root
    if ( root == nullptr ) {
		x->setKey(key);
		root = x;
    }
    else {
        addNode(key, root,x);
    }
}

// Add a node (private)
void BSTree::addNode(string key, Node* leaf,Node*x) {
    if ( key <= leaf->Key() )
    {
        if ( leaf->Left() != nullptr )
            addNode(key, leaf->Left(),x);
        else {
			x->setKey(key);
			x->setParent(leaf);
			leaf->setLeft(x);
        }
    }
    else
    {
        if ( leaf->Right() != nullptr )
            addNode(key, leaf->Right(),x);
        else {
			x->setKey(key);
			x->setParent(leaf);
			leaf->setRight(x);
        }
    }
}

// Find a node
Node* BSTree::findNode(string key, Node* node)//pass in root
{
	if (node == nullptr) {//when key is not found
		cout << key << " not found\n";
		return nullptr;
	}
	if (key == node->Key()) {//when found
		cout << "ID: " << node->Key() << endl;//then prints key
		cout << "First Name: " << node->entry->firstName << endl;
		cout << "Middle Name: " << node->entry->middleName << endl;
		cout << "Last Name: " << node->entry->lastName << endl;
		cout << "Company Name: " << node->entry->companyName << endl;
		cout << "Home Phone: " << node->entry->homePhone << endl;
		cout << "Office Phone: " << node->entry->officePhone << endl;
		cout << "Email: " << node->entry->email << endl;
		cout << "Mobile Phone: " << node->entry->mobilePhone << endl;
		cout << "Address: " << node->entry->address << endl;
		cout << "City: " << node->entry->city << endl;
		cout << "State: " << node->entry->state << endl;
		cout << "Zip Code: " << node->entry->zip << endl;
		cout << "Country: " << node->entry->country << endl;
		for (int i = 0; i < node->entry->affiliates.size(); i++) {
			cout << "Affiliates: " << node->entry->affiliates[i] << endl;

		}
		cout << endl;
		return node;//returns the search
	}
	else if (key < node->Key()) {//goes to left to search
		return findNode(key, node->Left());
	}
	else if (key > node->Key()) {//goes to right to search
		return findNode(key, node->Right());
	}
	else {
		cout << key << " not found\n";//when nothing is found
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
	//	cout << "ID: " <<node->Key() <<endl;//then prints key
		cout << "ID: " << node->entry->ID << endl;//then prints key
		cout << "First Name: " << node->entry->firstName<<endl;
		cout << "Middle Name: " << node->entry->middleName << endl;
		cout << "Last Name: " << node->entry->lastName << endl;
		cout << "Company Name: " << node->entry->companyName << endl;
		cout << "Home Phone: " << node->entry->homePhone << endl;
		cout << "Office Phone: " << node->entry->officePhone << endl;
		cout << "Email: " << node->entry->email << endl;
		cout << "Mobile Phone: " << node->entry->mobilePhone << endl;
		cout << "Address: " << node->entry->address << endl;
		cout << "City: " << node->entry->city << endl;
		cout << "State: " << node->entry->state << endl;
		cout << "Zip Code: " << node->entry->zip << endl;
		cout << "Country: " << node->entry->country << endl;
		for (int i = 0; i < node->entry->affiliates.size(); i++) {
			cout << "Affiliates: " << node->entry->affiliates[i] << endl;
			
		}
		cout << endl;
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
Node* BSTree::successor(string key, Node *node)
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
Node* BSTree::predecessor(string key, Node *node)
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

Node* BSTree::findNodeEdit(string key, Node * node)
{
	if (node == nullptr) {//when key is not found
		cout << key << " not found\n";
		return nullptr;
	}
	if (key == node->Key()) {//when found
		int option;
		string temp;
		cout << "What would you like to modify?\n";
		cout << "1. ID\n";
		cout << "2. First Name\n";
		cout << "3. Middle Name\n";
		cout << "4. Last Name\n";
		cout << "5. Company Name\n";
		cout << "6. Home Phone\n";
		cout << "7. Office Phone\n";
		cout << "8. Email\n";
		cout << "9. Mobile Phone\n";
		cout << "10. Address\n";
		cout << "11. City\n";
		cout << "12. State\n";
		cout << "13. Zip\n";
		cout << "14. Country\n";
		cout << "15. New Affiliate\n";
		cout << "16. Delete Affiliate\n";
		cin >> option;
		cin.ignore();
		if (option == 1) {
			cout << "Enter ID: ";
			getline(cin, temp);
			node->setKey(temp);
			node->entry->ID = temp;
		}
		else if (option == 2) {
			cout << "Enter First name: ";
			getline(cin, temp);
			node->entry->firstName = temp;
		}
		else if (option == 3) {
			cout << "Enter Middle Name: ";
			getline(cin, temp);
			node->entry->middleName = temp;
		}
		else if (option == 4) {
			cout << "Enter Last Name: ";
			getline(cin, temp);
			node->entry->lastName = temp;
		}
		else if (option == 5) {
			cout << "Enter Company Name: ";
			getline(cin, temp);
			node->entry->companyName = temp;
		}
		else if (option == 6) {
			cout << "Enter Home Phone: ";
			getline(cin, temp);
			node->entry->homePhone = temp;
		}
		else if (option == 7) {
			cout << "Enter Office Phone: ";
			getline(cin, temp);
			node->entry->officePhone = temp;
		}
		else if (option == 8) {
			cout << "Enter Email: ";
			getline(cin, temp);
			node->entry->email = temp;
		}
		else if (option == 9) {
			cout << "Enter Mobile Phone: ";
			getline(cin, temp);
			node->entry->mobilePhone = temp;
		}
		else if (option == 10) {
			cout << "Enter Address: ";
			getline(cin, temp);
			node->entry->address = temp;
		}
		else if (option == 11) {
			cout << "Enter City: ";
			getline(cin, temp);
			node->entry->city = temp;
		}
		else if (option == 12) {
			cout << "Enter State: ";
			getline(cin, temp);
			node->entry->state = temp;
		}
		else if (option == 13) {
			cout << "Enter Zip: ";
			getline(cin, temp);
			node->entry->zip = temp;
		}
		else if (option == 14) {
			cout << "Enter Country: ";
			getline(cin, temp);
			node->entry->country = temp;
		}
		else if (option == 15) {
			cout << "Enter New Affiliate: ";
			getline(cin, temp);
			node->entry->affiliates.push_back(temp);
		}
		else if (option == 16) {
			cout << "Enter Index of Affiliate to Delete: ";
			int afilindex;
			cin >> afilindex;
			if (cin.fail()) {
				cout << "incorrect input\n";
			}
			if(afilindex<node->entry->affiliates.size()+1 && afilindex >0)
			node->entry->affiliates[afilindex-1].erase();
		}
		else cout << "Invalid Input\n";
		cout << endl;
		return node;//returns the search
	}
	else if (key < node->Key()) {//goes to left to search
		return findNodeEdit(key, node->Left());
	}
	else if (key > node->Key()) {//goes to right to search
		return findNodeEdit(key, node->Right());
	}
	else {
		cout << key << " not found\n";//when nothing is found
		return nullptr;
	}
}


void BSTree::deleteNode(string key)
{
    if (deleteNode(Root(), key) == nullptr)
        setRoot(nullptr);
}

//deleteNode (Private)
Node* BSTree::deleteNode(Node* root,string key)
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
