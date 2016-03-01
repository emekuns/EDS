/**** ArrivalEvent interface */
#ifndef __ARRIVALEVENT_H_INCLUDED__   
#define __ARRIVALEVENT_H_INCLUDED__ 

#include "Event.h"

class ArrivalEvent: public Event{
public:
	ArrivalEvent(int time, Process *process, Simulation* sim);
	void processEvent();
};

#endif