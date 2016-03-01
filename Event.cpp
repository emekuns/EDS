/**** Event implementation */
#include <iomanip>
#include <sstream>
#include "Event.h"
#include "ArrivalEvent.h"
#include "TimeOutEvent.h"

using namespace std;

Event::Event(int theTime, Process *theProcess, Simulation *theSim) :eventTime(theTime), process(theProcess), sim (theSim) {}
Event::~Event() {}
int Event::getTime(){ return eventTime; }
Process *Event::getProcess(){ return process; }

int Event::compareTo(ListItem *other){
	int theResult = 0;
	Event *otherEvent = dynamic_cast<Event *>(other);
	if(otherEvent != NULL){
		theResult = eventTime - otherEvent->eventTime;
		if(theResult == 0){
			// see if we are comparing an ArrivalEvent and a TimeOutEvent
			if(dynamic_cast<ArrivalEvent *>(this) && dynamic_cast<TimeOutEvent *>(other))
				theResult = -1;
			else if(dynamic_cast<TimeOutEvent *>(this) && dynamic_cast<ArrivalEvent *>(other))
				theResult = 1;
			else
				theResult = this->process->getID() - otherEvent->process->getID();
		}
	}
	return theResult;
}// compareTo

string Event::header(){
	ostringstream s, sTime, sID;
	sTime << setw(4) << eventTime;
	sID << setw(3) << process->getID();
	s << "Time  " << sTime.str() << ": Process " << sID.str();
	return s.str();
}// header