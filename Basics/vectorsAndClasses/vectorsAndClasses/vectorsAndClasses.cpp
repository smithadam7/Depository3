#include "stdafx.h"
/*This program demonstrates the use of vectors with classes, defines operator functions,
uses the pointer defererencing (->) operator.*/
//Adam Smith
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class Employee {
public:     /*Place the default constructor declaration below */     
	Employee();
	void setName(string &_name){name=_name;}
	string getName() {return name;} 
	void setID(string _id) {id = _id;} 
	/*Fill in the code for getID */   
	string getID() {return id;}
	void setSupervisorName(string _name)  
	{         /*Set supervisor's name to _name.  Remember: this is a pointer
			  so you have to use the arrow pointer-deference operator */  
			  //     
	 supervisor -> name=_name;
	// supervisor = new Employee();
	}             
	string getSupervisorName()     {         /*Return supervisor's name */         
											 // 
		return supervisor->name;
	}   
	void setSupervisorID(string _ID)
	{             
		supervisor->id = _ID;
	}
	string getSupervisorID() {       
		return supervisor->id;
	}
	void setSupervisor(Employee *_supervisor)
	{supervisor = _supervisor; }
	/*Create an Employee Operator as a friend function prototype */     
	//   
	friend class inputEmployee;
private:     
	string name; 
	string id;         /*Define a pointer to an Employee type called supervisor */ 
	Employee*supervisor;
};
			 /*Define the default constructor definition */ 
			 //
Employee::Employee()
{    
	name = "";
	id = -1;
	supervisor = nullptr;
}
/*Define a the operator << function allowing Employee to be streamed. 
Remember to return ostream& */ // 
ostream& operator << (ostream &out, Employee _Employee)
{
	out << "Name: " << _Employee.getName() << endl;
	out << "ID: " << _Employee.getID() << endl;
	out << "Supervisor: " << _Employee.getSupervisorName() << endl;
	out << "SupervisorID: " << _Employee.getSupervisorID() << endl;
	return out;
}
/*Note that the input Employee function was not defined 
as a friend function to the Employee class, so you must use Mutator and Accessor functions*/
void inputEmployee(Employee &_employee) {
	string employeeName, supervisorName, id,supervisorID;
	Employee * supervisor = new Employee;
	cout << "Employee Name: ";  
	//getline(cin, employeeName);
	cin >> employeeName;
	/*Set the name for _employee to employeeName*/ 
	_employee.setName(employeeName);
	cout <<"Employee ID: ";
	//getline (cin, id);
	cin >> id;
	_employee.setID(id); 
	cout <<"Supervisor Name: ";
	//getline (cin, supervisorName);
	cin >> supervisorName;
	_employee.setSupervisor(supervisor);
	_employee.setSupervisorName(supervisorName); 
	cout << "Supervisor ID: ";
	cin >> supervisorID;
	_employee.setSupervisorID(supervisorID);
}
	/*Note:  The ostream works for cout AND for ofstream objects*/
void printVector(ostream& out, vector<Employee> &employeeVector) 
{ for (int i = 0; i < employeeVector.size(); i++) 
{ out << employeeVector[i] << endl << endl;
cout << employeeVector[i] << endl << endl;
} 
}

void readFromFile(Employee &_employee,ifstream& infile, vector<Employee> &employeeVector) {
	//infile.open("input.txt");
	string employeeName, supervisorName,supervisorID;
	string id;
	Employee temp;
	Employee * supervisorptr = new Employee();
	while (!infile.eof()) {
		//infile.ignore();
		getline(infile, employeeName);
		//infile >> employeeName;
		_employee.setName(employeeName);
		//infile.ignore();
		getline(infile, id);
		//infile >> id;
		_employee.setID(id);
		//infile.ignore();
		getline(infile, supervisorName);
		//infile >> supervisorName;
		//supervisorptr->setSupervisorName(supervisorName);
		//_employee.setSupervisorName = supervisorptr;
		_employee.setSupervisor(supervisorptr);
		_employee.setSupervisorName(supervisorName);
		getline(infile, supervisorID);
		_employee.setSupervisorID(supervisorID);
		employeeVector.push_back(Employee(_employee));
	}
	infile.close();
	cout << "File Read Successfully" << endl;
}

int main() {
		vector <int> intVector; 
	/* create a vector of Employees called employeeVector */     //
		vector <Employee> employeeVector;
		Employee employee1;  
		char menu='z';   
		ifstream infile("input.txt");
		ofstream outfile("output.txt");    
		while (menu != 'e') {
			cout << "a. add employee" << endl;
			cout << "b. print all employees to screen" << endl; 
			cout << "c. print all employees to file" << endl; 
			cout << "e. exit" << endl; 
			cout << "d. read from file" << endl;
			cin >> menu;
			switch (menu) {
			case 'a':  
				inputEmployee(employee1);        
				/*add employee1 to the employee Vector */ 
				//     
				employeeVector.push_back(employee1);
				break;
			case 'b':     
				/*call the function printvector outputing to the monitor */  
				//     
				printVector( outfile,employeeVector);
				break; 
			case 'c':  
				/*call the function printvector outputing to the outfile */      
				//         
				printVector(outfile, employeeVector);
				break;  
			case 'e':
				exit(0);  
				break;  
			case 'd':
				readFromFile(employee1, infile, employeeVector);
				//employeeVector.push_back(employee1);
				break;
			default:break; 
			}      
		}   
		return 0; 
	}
