//Adam Smith
//Here are the function definitions for the readfile
//and 15 exact search functions and 15 contains search functions
//change the read file name to switch between the large and small data file
#include "functions.h"
//#include <thread>

//Multithreading
/*void task(Data* database,Node* n) {
	database->nodePtrVec.push_back(n);
}
void task2(Data* database, Node* n) {
	database->tree1->addNode(n->entry->ID,n);
}*/

//Reads in records from a file, **CHANGE NAME** of file to change database read in
void readFile(Data *database)
{
	ifstream infile;
	int id;
	int g=0;//counts records read
	infile.open("databasesmall.txt");//opens file
	if (infile.fail()) {
		throw FileIOException();//if the file can't be read
	}
	cout << "Reading Records\n";
	while (!infile.eof()) {
		Node* n = new Node();
		string temp;//temporary, like people
		getline(infile, temp);
		n->entry->ID = temp;
		getline(infile,temp);
		n->entry->firstName = temp;
		getline(infile, temp);
		n->entry->middleName = temp;
		getline(infile, temp);
		n->entry->lastName = temp;
		getline(infile, temp);
		n->entry->companyName = temp;
		getline(infile, temp);
		n->entry->homePhone = temp;
		getline(infile, temp);
		n->entry->officePhone = temp;
		getline(infile, temp);
		n->entry->email = temp;
		getline(infile, temp);
		n->entry->mobilePhone = temp;
		getline(infile, temp);
		n->entry->address = temp;
		getline(infile, temp);
		n->entry->city = temp;
		getline(infile, temp);
		n->entry->state = temp;
		getline(infile, temp);
		n->entry->zip = temp;
		getline(infile, temp);
		n->entry->country = temp;
		getline(infile, temp);
		while (temp != "|") {
			n->entry->affiliates.push_back(temp);
			getline(infile, temp);
		}
		//Added to the tree, just like me
		database->tree1->addNode(n->entry->ID, n);
		//Adds node pointer to vector
		database->nodePtrVec.push_back(n);
		//Counts records
		//cout << ++g<<endl;
		//thread t1(task,database,n);
		//thread t2(task2, database, n);
		//t1.join();
		//t2.join();
		//database->nodePtrVec.push_back(n);
	
	}
	//Testing:
	//database->sortFirstName(database->vecFirstName);
	
//	for (int i = 0; i < test.size(); i++) {
//		cout << test[i]->entry->middleName<<endl;
//	}
	//database->tree1->printInorder(database->tree1->Root());
	
	infile.close();
}


void searchID(Data *database)
{
	//Sorts vector accordingly
	database->sortID(database->nodePtrVec);
	//new database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter ID to search for: ";
	string search;
	//cin >> search;
	cin.ignore();
	getline(cin, search);
	//Pushes results to new database
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->ID == search) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//If vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Prints out results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	//if user input is incorrect
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Input must be a number\n";
		return;
	}
	int option;
	//Determines field to search by
	if (again == 1) {
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
		cout << "15. Affiliate\n";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			searchID(searchBase);
		else if (option == 2)
			searchFirstName(searchBase);
		else if (option == 3)
			searchMiddleName(searchBase);
		else if (option == 4)
			searchLastName(searchBase);
		else if (option == 5)
			searchCompanyName(searchBase);
		else if (option == 6)
			searchHomePhone(searchBase);
		else if (option == 7)
			searchOfficePhone(searchBase);
		else if (option == 8)
			searchEmail(searchBase);
		else if (option == 9)
			searchMobilePhone(searchBase);
		else if (option == 10)
			searchAddress(searchBase);
		else if (option == 11)
			searchCity(searchBase);
		else if (option == 12)
			searchState(searchBase);
		else if (option == 13)
			searchZip(searchBase);
		else if (option == 14)
			searchCountry(searchBase);
		else if (option == 15)
			searchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void searchFirstName(Data *database)
{
	database->sortFirstName(database->nodePtrVec);
	Data * searchBase = new Data();
	cout << "Enter first name to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->firstName == search) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	else 
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		cout << "15. Affiliate\n";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			searchID(searchBase);
		else if (option == 2)
			searchFirstName(searchBase);
		else if (option == 3)
			searchMiddleName(searchBase);
		else if (option == 4)
			searchLastName(searchBase);
		else if (option == 5)
			searchCompanyName(searchBase);
		else if (option == 6)
			searchHomePhone(searchBase);
		else if (option == 7)
			searchOfficePhone(searchBase);
		else if (option == 8)
			searchEmail(searchBase);
		else if (option == 9)
			searchMobilePhone(searchBase);
		else if (option == 10)
			searchAddress(searchBase);
		else if (option == 11)
			searchCity(searchBase);
		else if (option == 12)
			searchState(searchBase);
		else if (option == 13)
			searchZip(searchBase);
		else if (option == 14)
			searchCountry(searchBase);
		else if (option == 15)
			searchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void searchMiddleName(Data *database)
{
	//Sorts vector accordingly
	database->sortMiddleName(database->nodePtrVec);
	//new database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter middle name to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	//Pushes results to new database
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->middleName == search) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//If vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Prints out results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		cout << "15. Affiliate\n";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			searchID(searchBase);
		else if (option == 2)
			searchFirstName(searchBase);
		else if (option == 3)
			searchMiddleName(searchBase);
		else if (option == 4)
			searchLastName(searchBase);
		else if (option == 5)
			searchCompanyName(searchBase);
		else if (option == 6)
			searchHomePhone(searchBase);
		else if (option == 7)
			searchOfficePhone(searchBase);
		else if (option == 8)
			searchEmail(searchBase);
		else if (option == 9)
			searchMobilePhone(searchBase);
		else if (option == 10)
			searchAddress(searchBase);
		else if (option == 11)
			searchCity(searchBase);
		else if (option == 12)
			searchState(searchBase);
		else if (option == 13)
			searchZip(searchBase);
		else if (option == 14)
			searchCountry(searchBase);
		else if (option == 15)
			searchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void searchLastName(Data *database)
{//Sorts vector accordingly
	database->sortLastName(database->nodePtrVec);
	//new database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter last name to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	//Pushes results to new database
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->lastName == search) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//If vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Prints out results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;
			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		cout << "15. Affiliate\n";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			searchID(searchBase);
		else if (option == 2)
			searchFirstName(searchBase);
		else if (option == 3)
			searchMiddleName(searchBase);
		else if (option == 4)
			searchLastName(searchBase);
		else if (option == 5)
			searchCompanyName(searchBase);
		else if (option == 6)
			searchHomePhone(searchBase);
		else if (option == 7)
			searchOfficePhone(searchBase);
		else if (option == 8)
			searchEmail(searchBase);
		else if (option == 9)
			searchMobilePhone(searchBase);
		else if (option == 10)
			searchAddress(searchBase);
		else if (option == 11)
			searchCity(searchBase);
		else if (option == 12)
			searchState(searchBase);
		else if (option == 13)
			searchZip(searchBase);
		else if (option == 14)
			searchCountry(searchBase);
		else if (option == 15)
			searchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void searchCompanyName(Data *database)
{//Sorts vector accordingly
	database->sortCompanyName(database->nodePtrVec);
	//new database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter company name to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	//Pushes results to new database
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->companyName == search) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//If vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Prints out results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;
			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		cout << "15. Affiliate\n";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			searchID(searchBase);
		else if (option == 2)
			searchFirstName(searchBase);
		else if (option == 3)
			searchMiddleName(searchBase);
		else if (option == 4)
			searchLastName(searchBase);
		else if (option == 5)
			searchCompanyName(searchBase);
		else if (option == 6)
			searchHomePhone(searchBase);
		else if (option == 7)
			searchOfficePhone(searchBase);
		else if (option == 8)
			searchEmail(searchBase);
		else if (option == 9)
			searchMobilePhone(searchBase);
		else if (option == 10)
			searchAddress(searchBase);
		else if (option == 11)
			searchCity(searchBase);
		else if (option == 12)
			searchState(searchBase);
		else if (option == 13)
			searchZip(searchBase);
		else if (option == 14)
			searchCountry(searchBase);
		else if (option == 15)
			searchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void searchHomePhone(Data *database)
{//Sorts vector accordingly
	database->sortHomePhone(database->nodePtrVec);
	//new database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter home phone to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	//Pushes results to new database
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->homePhone == search) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//If vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Prints out results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;
			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		cout << "15. Affiliate\n";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			searchID(searchBase);
		else if (option == 2)
			searchFirstName(searchBase);
		else if (option == 3)
			searchMiddleName(searchBase);
		else if (option == 4)
			searchLastName(searchBase);
		else if (option == 5)
			searchCompanyName(searchBase);
		else if (option == 6)
			searchHomePhone(searchBase);
		else if (option == 7)
			searchOfficePhone(searchBase);
		else if (option == 8)
			searchEmail(searchBase);
		else if (option == 9)
			searchMobilePhone(searchBase);
		else if (option == 10)
			searchAddress(searchBase);
		else if (option == 11)
			searchCity(searchBase);
		else if (option == 12)
			searchState(searchBase);
		else if (option == 13)
			searchZip(searchBase);
		else if (option == 14)
			searchCountry(searchBase);
		else if (option == 15)
			searchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void searchOfficePhone(Data *database)
{//Sorts vector accordingly
	database->sortOfficePhone(database->nodePtrVec);
	//new database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter office phone to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	//Pushes results to new database
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->officePhone == search) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//If vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Prints out results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		cout << "15. Affiliate\n";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			searchID(searchBase);
		else if (option == 2)
			searchFirstName(searchBase);
		else if (option == 3)
			searchMiddleName(searchBase);
		else if (option == 4)
			searchLastName(searchBase);
		else if (option == 5)
			searchCompanyName(searchBase);
		else if (option == 6)
			searchHomePhone(searchBase);
		else if (option == 7)
			searchOfficePhone(searchBase);
		else if (option == 8)
			searchEmail(searchBase);
		else if (option == 9)
			searchMobilePhone(searchBase);
		else if (option == 10)
			searchAddress(searchBase);
		else if (option == 11)
			searchCity(searchBase);
		else if (option == 12)
			searchState(searchBase);
		else if (option == 13)
			searchZip(searchBase);
		else if (option == 14)
			searchCountry(searchBase);
		else if (option == 15)
			searchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void searchEmail(Data *database)
{//Sorts vector accordingly
	database->sortEmail(database->nodePtrVec);
	//new database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter email to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	//Pushes results to new database
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->email == search) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//If vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Prints out results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		cout << "15. Affiliate\n";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			searchID(searchBase);
		else if (option == 2)
			searchFirstName(searchBase);
		else if (option == 3)
			searchMiddleName(searchBase);
		else if (option == 4)
			searchLastName(searchBase);
		else if (option == 5)
			searchCompanyName(searchBase);
		else if (option == 6)
			searchHomePhone(searchBase);
		else if (option == 7)
			searchOfficePhone(searchBase);
		else if (option == 8)
			searchEmail(searchBase);
		else if (option == 9)
			searchMobilePhone(searchBase);
		else if (option == 10)
			searchAddress(searchBase);
		else if (option == 11)
			searchCity(searchBase);
		else if (option == 12)
			searchState(searchBase);
		else if (option == 13)
			searchZip(searchBase);
		else if (option == 14)
			searchCountry(searchBase);
		else if (option == 15)
			searchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void searchMobilePhone(Data *database)
{//Sorts vector accordingly
	database->sortMobilePhone(database->nodePtrVec);
	//new database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter mobile phone to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	//Pushes results to new database
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->mobilePhone == search) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//If vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Prints out results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		cout << "15. Affiliate\n";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			searchID(searchBase);
		else if (option == 2)
			searchFirstName(searchBase);
		else if (option == 3)
			searchMiddleName(searchBase);
		else if (option == 4)
			searchLastName(searchBase);
		else if (option == 5)
			searchCompanyName(searchBase);
		else if (option == 6)
			searchHomePhone(searchBase);
		else if (option == 7)
			searchOfficePhone(searchBase);
		else if (option == 8)
			searchEmail(searchBase);
		else if (option == 9)
			searchMobilePhone(searchBase);
		else if (option == 10)
			searchAddress(searchBase);
		else if (option == 11)
			searchCity(searchBase);
		else if (option == 12)
			searchState(searchBase);
		else if (option == 13)
			searchZip(searchBase);
		else if (option == 14)
			searchCountry(searchBase);
		else if (option == 15)
			searchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void searchAddress(Data *database)
{//Sorts vector accordingly
	database->sortAddress(database->nodePtrVec);
	//new database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter address to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	//Pushes results to new database
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->address == search) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//If vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Prints out results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		cout << "15. Affiliate\n";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			searchID(searchBase);
		else if (option == 2)
			searchFirstName(searchBase);
		else if (option == 3)
			searchMiddleName(searchBase);
		else if (option == 4)
			searchLastName(searchBase);
		else if (option == 5)
			searchCompanyName(searchBase);
		else if (option == 6)
			searchHomePhone(searchBase);
		else if (option == 7)
			searchOfficePhone(searchBase);
		else if (option == 8)
			searchEmail(searchBase);
		else if (option == 9)
			searchMobilePhone(searchBase);
		else if (option == 10)
			searchAddress(searchBase);
		else if (option == 11)
			searchCity(searchBase);
		else if (option == 12)
			searchState(searchBase);
		else if (option == 13)
			searchZip(searchBase);
		else if (option == 14)
			searchCountry(searchBase);
		else if (option == 15)
			searchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void searchCity(Data *database)
{//Sorts vector accordingly
	database->sortCity(database->nodePtrVec);
	//new database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter city to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	//Pushes results to new database
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->city == search) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//If vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Prints out results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		cout << "15. Affiliate\n";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			searchID(searchBase);
		else if (option == 2)
			searchFirstName(searchBase);
		else if (option == 3)
			searchMiddleName(searchBase);
		else if (option == 4)
			searchLastName(searchBase);
		else if (option == 5)
			searchCompanyName(searchBase);
		else if (option == 6)
			searchHomePhone(searchBase);
		else if (option == 7)
			searchOfficePhone(searchBase);
		else if (option == 8)
			searchEmail(searchBase);
		else if (option == 9)
			searchMobilePhone(searchBase);
		else if (option == 10)
			searchAddress(searchBase);
		else if (option == 11)
			searchCity(searchBase);
		else if (option == 12)
			searchState(searchBase);
		else if (option == 13)
			searchZip(searchBase);
		else if (option == 14)
			searchCountry(searchBase);
		else if (option == 15)
			searchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void searchState(Data *database)
{//Sorts vector accordingly
	database->sortState(database->nodePtrVec);
	//new database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter state to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	//Pushes results to new database
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->state == search) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//If vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Prints out results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		cout << "15. Affiliate\n";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			searchID(searchBase);
		else if (option == 2)
			searchFirstName(searchBase);
		else if (option == 3)
			searchMiddleName(searchBase);
		else if (option == 4)
			searchLastName(searchBase);
		else if (option == 5)
			searchCompanyName(searchBase);
		else if (option == 6)
			searchHomePhone(searchBase);
		else if (option == 7)
			searchOfficePhone(searchBase);
		else if (option == 8)
			searchEmail(searchBase);
		else if (option == 9)
			searchMobilePhone(searchBase);
		else if (option == 10)
			searchAddress(searchBase);
		else if (option == 11)
			searchCity(searchBase);
		else if (option == 12)
			searchState(searchBase);
		else if (option == 13)
			searchZip(searchBase);
		else if (option == 14)
			searchCountry(searchBase);
		else if (option == 15)
			searchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void searchZip(Data *database)
{//Sorts vector accordingly
	database->sortZip(database->nodePtrVec);
	//new database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter zip code to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	//Pushes results to new database
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->zip == search) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//If vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Prints out results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		cout << "15. Affiliate\n";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			searchID(searchBase);
		else if (option == 2)
			searchFirstName(searchBase);
		else if (option == 3)
			searchMiddleName(searchBase);
		else if (option == 4)
			searchLastName(searchBase);
		else if (option == 5)
			searchCompanyName(searchBase);
		else if (option == 6)
			searchHomePhone(searchBase);
		else if (option == 7)
			searchOfficePhone(searchBase);
		else if (option == 8)
			searchEmail(searchBase);
		else if (option == 9)
			searchMobilePhone(searchBase);
		else if (option == 10)
			searchAddress(searchBase);
		else if (option == 11)
			searchCity(searchBase);
		else if (option == 12)
			searchState(searchBase);
		else if (option == 13)
			searchZip(searchBase);
		else if (option == 14)
			searchCountry(searchBase);
		else if (option == 15)
			searchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void searchCountry(Data *database)
{//Sorts vector accordingly
	database->sortCountry(database->nodePtrVec);
	//new database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter country to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	//Pushes results to new database
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->country == search) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//If vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Prints out results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		cout << "15. Affiliate\n";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			searchID(searchBase);
		else if (option == 2)
			searchFirstName(searchBase);
		else if (option == 3)
			searchMiddleName(searchBase);
		else if (option == 4)
			searchLastName(searchBase);
		else if (option == 5)
			searchCompanyName(searchBase);
		else if (option == 6)
			searchHomePhone(searchBase);
		else if (option == 7)
			searchOfficePhone(searchBase);
		else if (option == 8)
			searchEmail(searchBase);
		else if (option == 9)
			searchMobilePhone(searchBase);
		else if (option == 10)
			searchAddress(searchBase);
		else if (option == 11)
			searchCity(searchBase);
		else if (option == 12)
			searchState(searchBase);
		else if (option == 13)
			searchZip(searchBase);
		else if (option == 14)
			searchCountry(searchBase);
		else if (option == 15)
			searchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void searchAfil(Data * database)
{
	Data * searchBase = new Data();
	cout << "Enter affiliate to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	cout << endl;
	//searches the vector for strings that contain the search
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		for (int j = 0; j < database->nodePtrVec[i]->entry->affiliates.size(); j++) {
			if (database->nodePtrVec[i]->entry->affiliates[j]==search) {
				searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
			}
		}
	}
	//If vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Prints out results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		cout << "15. Affiliate\n";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			searchID(searchBase);
		else if (option == 2)
			searchFirstName(searchBase);
		else if (option == 3)
			searchMiddleName(searchBase);
		else if (option == 4)
			searchLastName(searchBase);
		else if (option == 5)
			searchCompanyName(searchBase);
		else if (option == 6)
			searchHomePhone(searchBase);
		else if (option == 7)
			searchOfficePhone(searchBase);
		else if (option == 8)
			searchEmail(searchBase);
		else if (option == 9)
			searchMobilePhone(searchBase);
		else if (option == 10)
			searchAddress(searchBase);
		else if (option == 11)
			searchCity(searchBase);
		else if (option == 12)
			searchState(searchBase);
		else if (option == 13)
			searchZip(searchBase);
		else if (option == 14)
			searchCountry(searchBase);
		else if (option == 15)
			searchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void csearchID(Data * database)
{
	//Sorts vector accordingly
	database->sortFirstName(database->nodePtrVec);
	//New database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter ID to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	cout << endl;
	//searches the vector for strings that contain the search
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->ID.find(search) != std::string::npos) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//When the vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Displays the vector of results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			csearchID(searchBase);
		else if (option == 2)
			csearchFirstName(searchBase);
		else if (option == 3)
			csearchMiddleName(searchBase);
		else if (option == 4)
			csearchLastName(searchBase);
		else if (option == 5)
			csearchCompanyName(searchBase);
		else if (option == 6)
			csearchHomePhone(searchBase);
		else if (option == 7)
			csearchOfficePhone(searchBase);
		else if (option == 8)
			csearchEmail(searchBase);
		else if (option == 9)
			csearchMobilePhone(searchBase);
		else if (option == 10)
			csearchAddress(searchBase);
		else if (option == 11)
			csearchCity(searchBase);
		else if (option == 12)
			csearchState(searchBase);
		else if (option == 13)
			csearchZip(searchBase);
		else if (option == 14)
			csearchCountry(searchBase);
		else if (option == 15)
			csearchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void csearchFirstName(Data * database)
{
	//Sorts vector accordingly
	database->sortFirstName(database->nodePtrVec);
	//New database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter first name to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	cout << endl;
	//searches the vector for strings that contain the search
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->firstName.find(search) != std::string::npos) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//When the vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Displays the vector of results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			csearchID(searchBase);
		else if (option == 2)
			csearchFirstName(searchBase);
		else if (option == 3)
			csearchMiddleName(searchBase);
		else if (option == 4)
			csearchLastName(searchBase);
		else if (option == 5)
			csearchCompanyName(searchBase);
		else if (option == 6)
			csearchHomePhone(searchBase);
		else if (option == 7)
			csearchOfficePhone(searchBase);
		else if (option == 8)
			csearchEmail(searchBase);
		else if (option == 9)
			csearchMobilePhone(searchBase);
		else if (option == 10)
			csearchAddress(searchBase);
		else if (option == 11)
			csearchCity(searchBase);
		else if (option == 12)
			csearchState(searchBase);
		else if (option == 13)
			csearchZip(searchBase);
		else if (option == 14)
			csearchCountry(searchBase);
		else if (option == 15)
			csearchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void csearchMiddleName(Data * database)
{
	//Sorts vector accordingly
	database->sortMiddleName(database->nodePtrVec);
	//New database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter middle name to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	cout << endl;
	//searches the vector for strings that contain the search
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->middleName.find(search) != std::string::npos) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//When the vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Displays the vector of results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;

			// cout << field_names[i] << database->nodePtrVec[i]->entry->fields[i] << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			csearchID(searchBase);
		else if (option == 2)
			csearchFirstName(searchBase);
		else if (option == 3)
			csearchMiddleName(searchBase);
		else if (option == 4)
			csearchLastName(searchBase);
		else if (option == 5)
			csearchCompanyName(searchBase);
		else if (option == 6)
			csearchHomePhone(searchBase);
		else if (option == 7)
			csearchOfficePhone(searchBase);
		else if (option == 8)
			csearchEmail(searchBase);
		else if (option == 9)
			csearchMobilePhone(searchBase);
		else if (option == 10)
			csearchAddress(searchBase);
		else if (option == 11)
			csearchCity(searchBase);
		else if (option == 12)
			csearchState(searchBase);
		else if (option == 13)
			csearchZip(searchBase);
		else if (option == 14)
			csearchCountry(searchBase);
		else if (option == 15)
			csearchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void csearchLastName(Data * database)
{	//Sorts vector accordingly
	database->sortLastName(database->nodePtrVec);
	//New database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter last name to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	cout << endl;
	//searches the vector for strings that contain the search
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->lastName.find(search) != std::string::npos) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//When the vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Displays the vector of results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			csearchID(searchBase);
		else if (option == 2)
			csearchFirstName(searchBase);
		else if (option == 3)
			csearchMiddleName(searchBase);
		else if (option == 4)
			csearchLastName(searchBase);
		else if (option == 5)
			csearchCompanyName(searchBase);
		else if (option == 6)
			csearchHomePhone(searchBase);
		else if (option == 7)
			csearchOfficePhone(searchBase);
		else if (option == 8)
			csearchEmail(searchBase);
		else if (option == 9)
			csearchMobilePhone(searchBase);
		else if (option == 10)
			csearchAddress(searchBase);
		else if (option == 11)
			csearchCity(searchBase);
		else if (option == 12)
			csearchState(searchBase);
		else if (option == 13)
			csearchZip(searchBase);
		else if (option == 14)
			csearchCountry(searchBase);
		else if (option == 15)
			csearchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void csearchCompanyName(Data * database)
{
	//Sorts vector accordingly
	database->sortCompanyName(database->nodePtrVec);
	//New database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter company name to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	cout << endl;
	//searches the vector for strings that contain the search
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->companyName.find(search) != std::string::npos) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//When the vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Displays the vector of results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			csearchID(searchBase);
		else if (option == 2)
			csearchFirstName(searchBase);
		else if (option == 3)
			csearchMiddleName(searchBase);
		else if (option == 4)
			csearchLastName(searchBase);
		else if (option == 5)
			csearchCompanyName(searchBase);
		else if (option == 6)
			csearchHomePhone(searchBase);
		else if (option == 7)
			csearchOfficePhone(searchBase);
		else if (option == 8)
			csearchEmail(searchBase);
		else if (option == 9)
			csearchMobilePhone(searchBase);
		else if (option == 10)
			csearchAddress(searchBase);
		else if (option == 11)
			csearchCity(searchBase);
		else if (option == 12)
			csearchState(searchBase);
		else if (option == 13)
			csearchZip(searchBase);
		else if (option == 14)
			csearchCountry(searchBase);
		else if (option == 15)
			csearchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void csearchHomePhone(Data * database)
{
	//Sorts vector accordingly
	database->sortHomePhone(database->nodePtrVec);
	//New database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter home phone to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	cout << endl;
	//searches the vector for strings that contain the search
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->homePhone.find(search) != std::string::npos) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//When the vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Displays the vector of results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			csearchID(searchBase);
		else if (option == 2)
			csearchFirstName(searchBase);
		else if (option == 3)
			csearchMiddleName(searchBase);
		else if (option == 4)
			csearchLastName(searchBase);
		else if (option == 5)
			csearchCompanyName(searchBase);
		else if (option == 6)
			csearchHomePhone(searchBase);
		else if (option == 7)
			csearchOfficePhone(searchBase);
		else if (option == 8)
			csearchEmail(searchBase);
		else if (option == 9)
			csearchMobilePhone(searchBase);
		else if (option == 10)
			csearchAddress(searchBase);
		else if (option == 11)
			csearchCity(searchBase);
		else if (option == 12)
			csearchState(searchBase);
		else if (option == 13)
			csearchZip(searchBase);
		else if (option == 14)
			csearchCountry(searchBase);
		else if (option == 15)
			csearchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void csearchOfficePhone(Data * database)
{//Sorts vector accordingly
	database->sortOfficePhone(database->nodePtrVec);
	//New database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter office phone to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	cout << endl;
	//searches the vector for strings that contain the search
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->officePhone.find(search) != std::string::npos) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//When the vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Displays the vector of results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			csearchID(searchBase);
		else if (option == 2)
			csearchFirstName(searchBase);
		else if (option == 3)
			csearchMiddleName(searchBase);
		else if (option == 4)
			csearchLastName(searchBase);
		else if (option == 5)
			csearchCompanyName(searchBase);
		else if (option == 6)
			csearchHomePhone(searchBase);
		else if (option == 7)
			csearchOfficePhone(searchBase);
		else if (option == 8)
			csearchEmail(searchBase);
		else if (option == 9)
			csearchMobilePhone(searchBase);
		else if (option == 10)
			csearchAddress(searchBase);
		else if (option == 11)
			csearchCity(searchBase);
		else if (option == 12)
			csearchState(searchBase);
		else if (option == 13)
			csearchZip(searchBase);
		else if (option == 14)
			csearchCountry(searchBase);
		else if (option == 15)
			csearchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void csearchEmail(Data * database)
{//Sorts vector accordingly
	database->sortEmail(database->nodePtrVec);
	//New database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter email to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	cout << endl;
	//searches the vector for strings that contain the search
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->email.find(search) != std::string::npos) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//When the vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Displays the vector of results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			csearchID(searchBase);
		else if (option == 2)
			csearchFirstName(searchBase);
		else if (option == 3)
			csearchMiddleName(searchBase);
		else if (option == 4)
			csearchLastName(searchBase);
		else if (option == 5)
			csearchCompanyName(searchBase);
		else if (option == 6)
			csearchHomePhone(searchBase);
		else if (option == 7)
			csearchOfficePhone(searchBase);
		else if (option == 8)
			csearchEmail(searchBase);
		else if (option == 9)
			csearchMobilePhone(searchBase);
		else if (option == 10)
			csearchAddress(searchBase);
		else if (option == 11)
			csearchCity(searchBase);
		else if (option == 12)
			csearchState(searchBase);
		else if (option == 13)
			csearchZip(searchBase);
		else if (option == 14)
			csearchCountry(searchBase);
		else if (option == 15)
			csearchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void csearchMobilePhone(Data * database)
{//Sorts vector accordingly
	database->sortMobilePhone(database->nodePtrVec);
	//New database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter mobile phone to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	cout << endl;
	//searches the vector for strings that contain the search
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->mobilePhone.find(search) != std::string::npos) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//When the vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Displays the vector of results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			csearchID(searchBase);
		else if (option == 2)
			csearchFirstName(searchBase);
		else if (option == 3)
			csearchMiddleName(searchBase);
		else if (option == 4)
			csearchLastName(searchBase);
		else if (option == 5)
			csearchCompanyName(searchBase);
		else if (option == 6)
			csearchHomePhone(searchBase);
		else if (option == 7)
			csearchOfficePhone(searchBase);
		else if (option == 8)
			csearchEmail(searchBase);
		else if (option == 9)
			csearchMobilePhone(searchBase);
		else if (option == 10)
			csearchAddress(searchBase);
		else if (option == 11)
			csearchCity(searchBase);
		else if (option == 12)
			csearchState(searchBase);
		else if (option == 13)
			csearchZip(searchBase);
		else if (option == 14)
			csearchCountry(searchBase);
		else if (option == 15)
			csearchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void csearchAddress(Data * database)
{//Sorts vector accordingly
	database->sortAddress(database->nodePtrVec);
	//New database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter address to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	cout << endl;
	//searches the vector for strings that contain the search
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->address.find(search) != std::string::npos) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//When the vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Displays the vector of results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			csearchID(searchBase);
		else if (option == 2)
			csearchFirstName(searchBase);
		else if (option == 3)
			csearchMiddleName(searchBase);
		else if (option == 4)
			csearchLastName(searchBase);
		else if (option == 5)
			csearchCompanyName(searchBase);
		else if (option == 6)
			csearchHomePhone(searchBase);
		else if (option == 7)
			csearchOfficePhone(searchBase);
		else if (option == 8)
			csearchEmail(searchBase);
		else if (option == 9)
			csearchMobilePhone(searchBase);
		else if (option == 10)
			csearchAddress(searchBase);
		else if (option == 11)
			csearchCity(searchBase);
		else if (option == 12)
			csearchState(searchBase);
		else if (option == 13)
			csearchZip(searchBase);
		else if (option == 14)
			csearchCountry(searchBase);
		else if (option == 15)
			csearchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void csearchCity(Data * database)
{//Sorts vector accordingly
	database->sortCity(database->nodePtrVec);
	//New database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter city to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	cout << endl;
	//searches the vector for strings that contain the search
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->city.find(search) != std::string::npos) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//When the vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Displays the vector of results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			csearchID(searchBase);
		else if (option == 2)
			csearchFirstName(searchBase);
		else if (option == 3)
			csearchMiddleName(searchBase);
		else if (option == 4)
			csearchLastName(searchBase);
		else if (option == 5)
			csearchCompanyName(searchBase);
		else if (option == 6)
			csearchHomePhone(searchBase);
		else if (option == 7)
			csearchOfficePhone(searchBase);
		else if (option == 8)
			csearchEmail(searchBase);
		else if (option == 9)
			csearchMobilePhone(searchBase);
		else if (option == 10)
			csearchAddress(searchBase);
		else if (option == 11)
			csearchCity(searchBase);
		else if (option == 12)
			csearchState(searchBase);
		else if (option == 13)
			csearchZip(searchBase);
		else if (option == 14)
			csearchCountry(searchBase);
		else if (option == 15)
			csearchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void csearchState(Data * database)
{//Sorts vector accordingly
	database->sortState(database->nodePtrVec);
	//New database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter state to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	cout << endl;
	//searches the vector for strings that contain the search
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->state.find(search) != std::string::npos) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//When the vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Displays the vector of results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			csearchID(searchBase);
		else if (option == 2)
			csearchFirstName(searchBase);
		else if (option == 3)
			csearchMiddleName(searchBase);
		else if (option == 4)
			csearchLastName(searchBase);
		else if (option == 5)
			csearchCompanyName(searchBase);
		else if (option == 6)
			csearchHomePhone(searchBase);
		else if (option == 7)
			csearchOfficePhone(searchBase);
		else if (option == 8)
			csearchEmail(searchBase);
		else if (option == 9)
			csearchMobilePhone(searchBase);
		else if (option == 10)
			csearchAddress(searchBase);
		else if (option == 11)
			csearchCity(searchBase);
		else if (option == 12)
			csearchState(searchBase);
		else if (option == 13)
			csearchZip(searchBase);
		else if (option == 14)
			csearchCountry(searchBase);
		else if (option == 15)
			csearchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void csearchZip(Data * database)
{//Sorts vector accordingly
	database->sortZip(database->nodePtrVec);
	//New database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter zip code to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	cout << endl;
	//searches the vector for strings that contain the search
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->zip.find(search) != std::string::npos) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//When the vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Displays the vector of results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			csearchID(searchBase);
		else if (option == 2)
			csearchFirstName(searchBase);
		else if (option == 3)
			csearchMiddleName(searchBase);
		else if (option == 4)
			csearchLastName(searchBase);
		else if (option == 5)
			csearchCompanyName(searchBase);
		else if (option == 6)
			csearchHomePhone(searchBase);
		else if (option == 7)
			csearchOfficePhone(searchBase);
		else if (option == 8)
			csearchEmail(searchBase);
		else if (option == 9)
			csearchMobilePhone(searchBase);
		else if (option == 10)
			csearchAddress(searchBase);
		else if (option == 11)
			csearchCity(searchBase);
		else if (option == 12)
			csearchState(searchBase);
		else if (option == 13)
			csearchZip(searchBase);
		else if (option == 14)
			csearchCountry(searchBase);
		else if (option == 15)
			csearchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void csearchCountry(Data * database)
{//Sorts vector accordingly
	database->sortCountry(database->nodePtrVec);
	//New database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter country to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	cout << endl;
	//searches the vector for strings that contain the search
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		if (database->nodePtrVec[i]->entry->country.find(search) != std::string::npos) {
			searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
		}
	}
	//When the vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Displays the vector of results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			csearchID(searchBase);
		else if (option == 2)
			csearchFirstName(searchBase);
		else if (option == 3)
			csearchMiddleName(searchBase);
		else if (option == 4)
			csearchLastName(searchBase);
		else if (option == 5)
			csearchCompanyName(searchBase);
		else if (option == 6)
			csearchHomePhone(searchBase);
		else if (option == 7)
			csearchOfficePhone(searchBase);
		else if (option == 8)
			csearchEmail(searchBase);
		else if (option == 9)
			csearchMobilePhone(searchBase);
		else if (option == 10)
			csearchAddress(searchBase);
		else if (option == 11)
			csearchCity(searchBase);
		else if (option == 12)
			csearchState(searchBase);
		else if (option == 13)
			csearchZip(searchBase);
		else if (option == 14)
			csearchCountry(searchBase);
		else if (option == 15)
			csearchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}

void csearchAfil(Data * database)
{	//New database in case the user wants to search within
	Data * searchBase = new Data();
	cout << "Enter affiliate to search for: ";
	string search;
	cin.ignore();
	getline(cin, search);
	cout << endl;
	//searches the vector for strings that contain the search
	for (int i = 0; i < database->nodePtrVec.size(); i++) {
		for (int j = 0; j < database->nodePtrVec[i]->entry->affiliates.size(); j++) {
			if (database->nodePtrVec[i]->entry->affiliates[j].find(search) != std::string::npos) {
				searchBase->nodePtrVec.push_back(database->nodePtrVec[i]);
			}
		}
	}
	//When the vector is empty
	if (searchBase->nodePtrVec.empty()) {
		cout << search << " not found\n";
		return;
	}
	//Displays the vector of results
	else
		for (int i = 0; i < searchBase->nodePtrVec.size(); i++) {
			cout << "ID: " << searchBase->nodePtrVec[i]->Key() << endl;//then prints key
			cout << "First Name: " << searchBase->nodePtrVec[i]->entry->firstName << endl;
			cout << "Middle Name: " << searchBase->nodePtrVec[i]->entry->middleName << endl;
			cout << "Last Name: " << searchBase->nodePtrVec[i]->entry->lastName << endl;
			cout << "Company Name: " << searchBase->nodePtrVec[i]->entry->companyName << endl;
			cout << "Home Phone: " << searchBase->nodePtrVec[i]->entry->homePhone << endl;
			cout << "Office Phone: " << searchBase->nodePtrVec[i]->entry->officePhone << endl;
			cout << "Email: " << searchBase->nodePtrVec[i]->entry->email << endl;
			cout << "Mobile Phone: " << searchBase->nodePtrVec[i]->entry->mobilePhone << endl;
			cout << "Address: " << searchBase->nodePtrVec[i]->entry->address << endl;
			cout << "City: " << searchBase->nodePtrVec[i]->entry->city << endl;
			cout << "State: " << searchBase->nodePtrVec[i]->entry->state << endl;
			cout << "Zip Code: " << searchBase->nodePtrVec[i]->entry->zip << endl;
			cout << "Country: " << searchBase->nodePtrVec[i]->entry->country << endl;
			for (int j = 0; j < searchBase->nodePtrVec[i]->entry->affiliates.size(); j++) {
				cout << "Affiliates: " << searchBase->nodePtrVec[i]->entry->affiliates[j] << endl;

			}
			cout << endl;
		}
	//Allows user to search withing results
	cout << "Search within results?\n1. Yes\n2. No\n";
	int again;
	cin >> again;
	int option;
	//Determines field to search by
	if (again == 1) {
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
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "Input must be a number\n";
			return;
		}
		//Calls the function based on users input and searches the new vector
		if (option == 1)
			csearchID(searchBase);
		else if (option == 2)
			csearchFirstName(searchBase);
		else if (option == 3)
			csearchMiddleName(searchBase);
		else if (option == 4)
			csearchLastName(searchBase);
		else if (option == 5)
			csearchCompanyName(searchBase);
		else if (option == 6)
			csearchHomePhone(searchBase);
		else if (option == 7)
			csearchOfficePhone(searchBase);
		else if (option == 8)
			csearchEmail(searchBase);
		else if (option == 9)
			csearchMobilePhone(searchBase);
		else if (option == 10)
			csearchAddress(searchBase);
		else if (option == 11)
			csearchCity(searchBase);
		else if (option == 12)
			csearchState(searchBase);
		else if (option == 13)
			csearchZip(searchBase);
		else if (option == 14)
			csearchCountry(searchBase);
		else if (option == 15)
			csearchAfil(searchBase);
		else
			cout << "Invalid Option\n";
	}
}
