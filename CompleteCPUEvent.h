/**** CompleteCPUEvent interface */
#ifndef __COMPLETECPUEVENT_H_INCLUDED__   
#define __COMPLETECPUEVENT_H_INCLUDED__

#include "Event.h"

class CompleteCPUEvent: public Event{
public:
	CompleteCPUEvent(int time, Process *process, Simulation* sim);
	void processEvent();
};

#endif