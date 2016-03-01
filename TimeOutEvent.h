/**** TimeOutEvent interface */
#ifndef __TIMEOUTEVENT_H_INCLUDED__   
#define __TIMEOUTEVENT_H_INCLUDED__

#include "Event.h"

class TimeOutEvent: public Event{
public:
	TimeOutEvent(int time, Process *process, Simulation* sim);
	void processEvent();
};

#endif