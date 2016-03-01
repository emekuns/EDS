/**** CompleteIOEvent interface */
#ifndef __COMPLETEIOEVENT_H_INCLUDED__   
#define __COMPLETEIOEVENT_H_INCLUDED__

#include "Event.h"

class CompleteIOEvent: public Event{
public:
	CompleteIOEvent(int time, Process *process, Simulation* sim);
	void processEvent();
};

#endif