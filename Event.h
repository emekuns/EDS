/**** Event abstract interface */
#ifndef __EVENT_H_INCLUDED__   
#define __EVENT_H_INCLUDED__ 

#include <string>
#include "Process.h"

using namespace std;

class ListItem;

class Event: public ListItem {
private:
	int eventTime;
	Process *process;
protected:
	Simulation *sim;
public:
	Event(int theTime, Process *theProcess, Simulation* sim);
	virtual void processEvent() = 0;
	virtual ~Event();
	int getTime();
	Process *getProcess();
	int compareTo(ListItem *other);
	string header();
};// class Event

#endif