/**** StartCPUEvent interface */
#ifndef __STARTCPUEVENT_H_INCLUDED__   
#define __STARTCPUEVENT_H_INCLUDED__ 

#include "Event.h"

class StartCPUEvent: public Event{
public:
	StartCPUEvent(int time, Process *process, Simulation* sim);
	void processEvent();
};

#endif