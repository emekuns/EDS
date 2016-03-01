/**** StartIOEvent interface */
#ifndef __STARTIOEVENT_H_INCLUDED__   
#define __STARTIOEVENT_H_INCLUDED__ 

#include "Event.h"

class StartIOEvent: public Event{
public:
	StartIOEvent(int time, Process *process, Simulation* sim);
	void processEvent();
};

#endif