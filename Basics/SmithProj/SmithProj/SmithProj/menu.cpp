//Adam Smith
//The menu functions

#include <iostream>
#include "menu.h"
#include "data.h"
#include "functions.h"
using namespace std;

Data * database = new Data();//creates new tree and vector of node pointers
void mainMenu()
{
	int userOption;
	try {
		readFile(database);//seeds board from file
	}
	catch (FileIOException) {//if it fails to open the file
		cout << "File could not be opened!\n";
		return;//exits
	}
	cout << "Database Read From File.\n";
	do//This will be the menu for the database
	{
		cout << "Please Choose an Option\n"
			<< endl << "1: Add Record\n2: Delete Record\n3: Search For Record\n4: Modify Record\n5: Output to file\n6: Display Records\n7: Exit\n";
		cin >> userOption;
		//Checks for invalid input
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
		}
		if (userOption == 1)// add record
		{
			addRecord(database);
		}
		else if (userOption == 2)//delete record
		{
			deleteRecord(database);
		}
		else if (userOption == 3)// search for record
		{
			searchforRecord();
		}
		else if (userOption == 4)//modify record
		{
			//database->sortID(database->nodePtrVec);
			modifyRecord();
			//database->sortFirstName(database->vecFirstName);
			//database->tree1->printInorder(database->tree1->Root());
			//database->sortFirstName(database->nodePtrVec);
			//for (int i = 0; i < database->nodePtrVec.size(); i++) {
			//	cout << database->nodePtrVec[i]->entry->firstName<<endl;
		//	}
		}
		else if (userOption == 5)//write database to file
		{
			//database->tree1->printInorder(database->tree1->Root());
			outputRecord();
			//return;// exits the menu
		}
		else if (userOption == 6)// exit
		{
			//Traverses tree and displays by ID key
			database->tree1->printInorder(database->tree1->Root());
		}
		else if (userOption == 7) {
			return;//Exits menu
		}
		else if(userOption>7||userOption<1)
		{
			cout << userOption << " is not a valid option\n";// if the user puts a different number
		}
	} while (true);// For the menu

}

void addRecord(Data *database)
{
	//go through every field and then add it to tree
	//creates new node to add to tree
	Node* n = new Node();
	int id,numOfAfil;
	string temp;
	cout << "Input ID number:";
	cin.ignore();
	getline(cin,temp);
	n->setKey(temp);
	n->entry->ID = temp;
	cout << "Input First Name:";
	getline(cin, temp);
	n->entry->firstName = temp;
	cout << "Input Middle Name:";
	getline(cin, temp);
	n->entry->middleName = temp;
	cout << "Input Last Name:";
	getline(cin, temp);
	n->entry->lastName = temp;
	cout << "Input Company name:";
	getline(cin, temp);
	n->entry->companyName = temp;
	cout << "Input Home Phone:";
	getline(cin, temp);
	n->entry->homePhone = temp;
	cout << "Input Office Phone:";
	getline(cin, temp);
	n->entry->homePhone = temp;
	cout << "Input Email:";
	getline(cin, temp);
	n->entry->email = temp;
	cout << "Input Mobile Phone:";
	getline(cin, temp);
	n->entry->mobilePhone = temp;
	cout << "Input Address:";
	getline(cin, temp);
	n->entry->address = temp;
	cout << "Input City:";
	getline(cin, temp);
	n->entry->city = temp;
	cout << "Input State:";
	getline(cin, temp);
	n->entry->state = temp;
	cout << "Input Zip Code:";
	getline(cin, temp);
	n->entry->zip = temp;
	cout << "Input Country:";
	getline(cin, temp);
	n->entry->country = temp;
	cout << "Input Number of Affiliates: ";
	cin >> numOfAfil;
	//if user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	for (int i = 0; i < numOfAfil; i++) {
		cout << "\nInput Affiliate name, phone, and email: ";
		cin.ignore();
		getline(cin, temp);
		n->entry->affiliates.push_back(temp);
		cout << "Affiliate Added.\n";
	}
	//Adds node to tree
	database->tree1->addNode(n->entry->ID, n);
	//Addes node to vector
	database->nodePtrVec.push_back(n);
	cout << "Record added to database.\n";
}

void deleteRecord(Data *database)
{
	//Deletes by number because thats all people are
	string tempID;
	cout << "Which Item would you like to delete? Insert ID Number: ";
	cin >> tempID;
	//search for record and delete
	//erases node from vector
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if(database->nodePtrVec[i]->entry->ID==tempID)
		database->nodePtrVec.erase(database->nodePtrVec.begin()+i);
	}
	//removes person from tree 
	database->tree1->deleteNode(tempID);
	cout << "\nRecord Deleted\n";
}

void searchforRecord()
{
	//Searches tree by user specifications
	int method;
	int option;
	cout << "What would you like to search with?\n";
	cout << "1. Exact Search\n";
	cout << "2. Contains Search\n";
	cin >> method;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	cout << "What would you like to search by?\n";
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
	cout << "15. Affiliates\n";
	cin >> option;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	//method 1 is exact search
	//method 2 is contains search
	if (method == 1 && option == 1) {
		searchID(database);
	}
	else if (method == 1 && option == 2) {
		searchFirstName(database);
	}
	else if (method == 1 && option == 3) {
		searchMiddleName(database);
	}
	else if (method == 1 && option == 4) {
		searchLastName(database);
	}
	else if (method == 1 && option == 5) {
		searchCompanyName(database);
	}
	else if (method == 1 && option == 6) {
		searchHomePhone(database);
	}
	else if (method == 1 && option == 7) {
		searchOfficePhone(database);
	}
	else if (method == 1 && option == 8) {
		searchEmail(database);
	}
	else if (method == 1 && option == 9) {
		searchMobilePhone(database);
	}
	else if (method == 1 && option == 10) {
		searchAddress(database);
	}
	else if (method == 1 && option == 11) {
		searchCity(database);
	}
	else if (method == 1 && option == 12) {
		searchState(database);
	}
	else if (method == 1 && option == 13) {
		searchZip(database);
	}
	else if (method == 1 && option == 14) {
		searchCountry(database);
	}
	else if (method == 1 && option == 15) {
		searchAfil(database);
	}
	else if (method == 2 && option == 1) {
		csearchID(database);
	}
	else if (method == 2 && option == 2) {
		csearchFirstName(database);
	}
	else if (method == 2 && option == 3) {
		csearchMiddleName(database);
	}
	else if (method == 2 && option == 4) {
		csearchLastName(database);
	}
	else if (method == 2 && option == 5) {
		csearchCompanyName(database);
	}
	else if (method == 2 && option == 6) {
		csearchHomePhone(database);
	}
	else if (method == 2 && option == 7) {
		csearchOfficePhone(database);
	}
	else if (method == 2 && option == 8) {
		csearchEmail(database);
	}
	else if (method == 2 && option == 9) {
		csearchMobilePhone(database);
	}
	else if (method == 2 && option == 10) {
		csearchAddress(database);
	}
	else if (method == 2 && option == 11) {
		csearchCity(database);
	}
	else if (method == 2 && option == 12) {
		csearchState(database);
	}
	else if (method == 2 && option == 13) {
		csearchZip(database);
	}
	else if (method == 2 && option == 14) {
		csearchCountry(database);
	}
	else if (method == 2 && option == 15) {
		csearchAfil(database);
	}
	else
		cout << "Not Valid Input\n";
	//searchID(database);
	//ask user to search for exact or contains
	//then ask which field to search with
}

void modifyRecord()
{
	//search for record and modify
	//searches by number because thats all people are
	string tempID;
	cout << "Which item would you like to edit? Insert ID Number: ";
	cin >> tempID;
	//Displays Record to edit
	cout << "\nRecord: \n";
	database->tree1->findNode(tempID, database->tree1->Root());
	//Calls edit function
	database->tree1->findNodeEdit(tempID, database->tree1->Root());

	cout << "\nRecord Modified \n";
}

void outfile(string filename)
{
	// const int MAX_FIELD = 14;
	//string fields[MAX_FIELD];
	int option;
	ofstream outfile;
	//Opens file based on name or creates file with specified name
	outfile.open(filename);
	//Asks user how to sort output
	cout << "How would you like to sort output?\n";
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
	cin >> option;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	//Sorts vector based on user request
	if (option == 1) {
		database->sortID(database->nodePtrVec);
	}
	else if (option == 2) {
		database->sortFirstName(database->nodePtrVec);
	}
	else if (option == 3) {
		database->sortMiddleName(database->nodePtrVec);
	}
	else if (option == 4) {
		database->sortLastName(database->nodePtrVec);
	}
	else if (option == 5) {
		database->sortCompanyName(database->nodePtrVec);
	}
	else if (option == 6) {
		database->sortHomePhone(database->nodePtrVec);
	}
	else if (option == 7) {
		database->sortOfficePhone(database->nodePtrVec);
	}
	else if (option == 8) {
		database->sortEmail(database->nodePtrVec);
	}
	else if (option == 9) {
		database->sortMobilePhone(database->nodePtrVec);
	}
	else if (option == 10) {
		database->sortAddress(database->nodePtrVec);
	}
	else if (option == 11) {
		database->sortCity(database->nodePtrVec);
	}
	else if (option == 12) {
		database->sortState(database->nodePtrVec);
	}
	else if (option == 13) {
		database->sortZip(database->nodePtrVec);
	}
	else if (option == 14) {
		database->sortCountry(database->nodePtrVec);
	}
	else {
		cout << "Invalid Option\n";
		return;//leaves
	}

	//User decides output fields
	int field;
	//Vector of bools to keep track of wanted fields
	vector<bool>fields;
	cout << "Include ID in output? 1.Yes, 2.No : ";
	cin >> field;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	//Field is wanted
	if (field == 1)fields.push_back(true);
	//Field is not wanted
	else fields.push_back(false);
	//Repeat for every field
	cout << "Include First Name in output? 1.Yes, 2.No : ";
	cin >> field;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	if (field == 1)fields.push_back(true);
	else fields.push_back(false);
	cout << "Include Middle Name in output? 1.Yes, 2.No : ";
	cin >> field;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	if (field == 1)fields.push_back(true);
	else fields.push_back(false);
	cout << "Include Last Name in output? 1.Yes, 2.No : ";
	cin >> field;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	if (field == 1)fields.push_back(true);
	else fields.push_back(false);
	cout << "Include Company Name in output? 1.Yes, 2.No : ";
	cin >> field;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	if (field == 1)fields.push_back(true);
	else fields.push_back(false);
	cout << "Include Home Phone in output? 1.Yes, 2.No : ";
	cin >> field;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	if (field == 1)fields.push_back(true);
	else fields.push_back(false);
	cout << "Include Office Phone in output? 1.Yes, 2.No : ";
	cin >> field;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	if (field == 1)fields.push_back(true);
	else fields.push_back(false);
	cout << "Include Email in output? 1.Yes, 2.No : ";
	cin >> field;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	if (field == 1)fields.push_back(true);
	else fields.push_back(false);
	cout << "Include Mobile Phone in output? 1.Yes, 2.No : ";
	cin >> field;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	if (field == 1)fields.push_back(true);
	else fields.push_back(false);
	cout << "Include Address in output? 1.Yes, 2.No : ";
	cin >> field;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	if (field == 1)fields.push_back(true);
	else fields.push_back(false);
	cout << "Include City in output? 1.Yes, 2.No : ";
	cin >> field;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	if (field == 1)fields.push_back(true);
	else fields.push_back(false);
	cout << "Include State in output? 1.Yes, 2.No : ";
	cin >> field;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	if (field == 1)fields.push_back(true);
	else fields.push_back(false);
	cout << "Include Zip Code in output? 1.Yes, 2.No : ";
	cin >> field;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	if (field == 1)fields.push_back(true);
	else fields.push_back(false);
	cout << "Include Country in output? 1.Yes, 2.No : ";
	cin >> field;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	if (field == 1)fields.push_back(true);
	else fields.push_back(false);
	cout << "Include Affiliates in output? 1.Yes, 2.No : ";
	cin >> field;
	//When user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	if (field == 1)fields.push_back(true);
	else fields.push_back(false);

	//Steps through vector
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		//If field is wanted, then the field is printed to file
		if(fields[0]==true)
		outfile << database->nodePtrVec[i]->entry->ID<<endl;
		if (fields[1] == true)
			outfile << database->nodePtrVec[i]->entry->firstName << endl;
		if (fields[2] == true)
			outfile << database->nodePtrVec[i]->entry->middleName<< endl;
		if (fields[3] == true)
			outfile << database->nodePtrVec[i]->entry->lastName << endl;
		if (fields[4] == true)
			outfile << database->nodePtrVec[i]->entry->companyName << endl;
		if (fields[5] == true)
			outfile << database->nodePtrVec[i]->entry->homePhone << endl;
		if (fields[6] == true)
			outfile << database->nodePtrVec[i]->entry->officePhone << endl;
		if (fields[7] == true)
			outfile << database->nodePtrVec[i]->entry->email << endl;
		if (fields[8] == true)
			outfile << database->nodePtrVec[i]->entry->mobilePhone << endl;
		if (fields[9] == true)
			outfile << database->nodePtrVec[i]->entry->address << endl;
		if (fields[10] == true)
			outfile << database->nodePtrVec[i]->entry->city << endl;
		if (fields[11] == true)
			outfile << database->nodePtrVec[i]->entry->state << endl;
		if (fields[12] == true)
			outfile << database->nodePtrVec[i]->entry->zip << endl;
		if (fields[13] == true)
			outfile << database->nodePtrVec[i]->entry->country << endl;
		if (fields[14] == true) {
			for (int j = 0; j < database->nodePtrVec[i]->entry->affiliates.size(); j++) {
				outfile << database->nodePtrVec[i]->entry->affiliates[j] << endl;
			}
		}
		//Else nothing was wanted to be output, so nothing will be output
		outfile << "|\n";
	}
	cout << "\nOutput File Saved. Goodbye!\n";
	outfile.close();//Closes file
}


void outputRecord()
{
	//change the overwrite function based on input file
	int option=0;
	int first = 1;
	int last = 2;
	cout << "Do you want to overwrite current file or new file?\n";
	cout << "1. Overwrite database File\n";
	cout << "2. New File\n";
	//option = userFail(first, last);
	cin >> option;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}

	if (option == 1) {
		cout << "Enter sort method: ";
		outfile("databaselarge.txt");
		//outfile("databasesmall.txt");
	}
	else if (option == 2) {
		cout << "Enter new file name: ";
		string fileName;
		cin >> fileName;
		outfile(fileName);
	}
	else cout << "Invalid Input\n";
	//ask user to overwrite database file or create a new one
	//if creating a new one ask for name
}