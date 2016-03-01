/**** ExitEvent interface */
#ifndef __EXITEVENT_H_INCLUDED__   
#define __EXITEVENT_H_INCLUDED__

#include "Event.h"

class ExitEvent: public Event{
public:
	ExitEvent(int time, Process *process, Simulation* sim);
	void processEvent();
};

#endif