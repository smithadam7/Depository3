//Adam Smith
//Event struct
#ifndef EVENT_H
#define EVENT_H
#include <queue>
struct Event {
	Event();
	Event(int _type);
	int type;
	char eventType;//set a when event is arrival set d when event is departure
	int time;//arrival time
	int length;//transaction length
	bool operator <(Event other)const {//overloaded for priority queue to go the other way
		return time > other.time;
	}
	int customer;
};


#endif