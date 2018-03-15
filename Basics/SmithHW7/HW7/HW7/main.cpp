// Adam Smith
// HW7
// Last Modified 03-10-17
// Built and ran successfully on Visual Studio
#include <iostream>
#include <string>
#include<fstream>
#include<queue>
#include"event.h"
using namespace std;

bool tellerAvailable = true;
int departTime;
int currentTime;
int customerA;
double avgWait=8;
float t=0;
int main()
{
	void processArrival(Event & arrivalEvent, priority_queue<Event>& eventPriorityQueue, queue<int>& bankLine);
	void processDeparture(Event & departEvent, priority_queue<Event>& eventPriorityQueue, queue<int>& bankLine);
	priority_queue<Event> eventPriorityQueue;//creates the event priority queue
	queue<int> bankLine;//creates queue for the line in the bank waiting for the teller

	cout << "Simulation Begins\n";
	int arriveTime, processTime;//temporary variables to read from file
	ifstream infile;//read from file
	infile.open("input.txt");//open file with simulation
	while (!infile.eof()) {
		int g = 0;
		Event newArrivalEvent;//creates a new event for each one in the file
		newArrivalEvent.eventType = 'a';//sets as arrival event
		infile >> arriveTime;
		newArrivalEvent.time = arriveTime;//sets the arrive time in the event
		infile >> processTime;
		newArrivalEvent.length = processTime;//sets the transaction time in the event
		newArrivalEvent.customer = g;
		eventPriorityQueue.push(newArrivalEvent);//adds event to priority queue
		g++;//keeps track of the number of customers
	}
	infile.close();//closes the file

	int totalProcessed = eventPriorityQueue.size();//currently contains only arrival events
	while (!eventPriorityQueue.empty()) {//while priority queue is not empty
		Event newEvent = eventPriorityQueue.top();//creates a new event that is the front of the queue
		currentTime = newEvent.time;
		if (newEvent.eventType == 'a') {//if event is an arrival event
			cout << "Processing an arrival event at time:	" << currentTime << endl;
			processArrival(newEvent, eventPriorityQueue, bankLine);//calls process arrival function
		}
		else if (newEvent.eventType == 'd') {//if event is a departure event
			cout << "Processing a departure event at time:	" << currentTime << endl;
			processDeparture(newEvent, eventPriorityQueue, bankLine);//calls processDeparture function
		}
	}

	cout << "Simulation Ends\n";
	cout << "\nFinal Statistics:\n	Total number of people processed: " <<totalProcessed;
	cout << "\n	Average amount of time spent waiting: " << avgWait/totalProcessed;//calculates avgWait

	cout << "\nPress enter key to continue\n";
	string hold;
	getline(cin, hold);
	return 0;
}
void processArrival(Event & arrivalEvent, priority_queue<Event>& eventPriorityQueue, queue<int>& bankLine)
{
	eventPriorityQueue.pop();//takes front of queue out
	customerA = arrivalEvent.customer;//sets customerA equal to the one in the event
	if (bankLine.empty() && tellerAvailable) {//if bankline is empty and the teller isnt busy
		departTime = currentTime + arrivalEvent.length;//calc depart time
		Event newDepartureEvent;//creates new departure event based of arrival event
		newDepartureEvent.eventType = 'd';//the event is a departure event
		arrivalEvent.eventType = 'd';//the event is a departure event
		newDepartureEvent.time = departTime;//set the new event time to depart time
		newDepartureEvent.length = arrivalEvent.length;//set the length
		eventPriorityQueue.push(newDepartureEvent);//places the new event in the priority queue
		avgWait = (avgWait+departTime)-currentTime;//calc average wait
		tellerAvailable = false;//the teller is now busy
	}
	else
		bankLine.push(customerA);//add the customer to the back of the line
}
void processDeparture(Event & departEvent, priority_queue<Event>& eventPriorityQueue, queue<int>& bankLine)
{
	eventPriorityQueue.pop();//remove the front of the priority queue
	if (!bankLine.empty()) {//if there are customers in line
		customerA = bankLine.front();//front of the bankline
		bankLine.pop();//remove front of line
		departTime = currentTime + departEvent.length;//calc depart time
		Event newDepartEvent;//a new event for the event priority queue
		newDepartEvent.eventType = 'd';//it is a departure event
		departEvent.eventType = 'd';//it is a departure event
		newDepartEvent.time = departTime;//set the time of the new event
		newDepartEvent.length = departEvent.length;//set the transaction time of the new event
		eventPriorityQueue.push(newDepartEvent);//enqueue the new event to the priority queue
		avgWait = avgWait + departEvent.length;//calc avgWait
	}
	else
		tellerAvailable = true;//the teller is now available
}
/*
trees:

*/