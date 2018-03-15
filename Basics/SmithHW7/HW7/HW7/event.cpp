//Adam Smith
//Implementation of event struct
#include"event.h"
#include<queue>
using namespace std;
Event::Event()
{}

Event::Event(int _type)//custom constructor to set event as arrival or departure
{
	type = _type;
}

