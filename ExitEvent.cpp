#include <iostream>
#include "ExitEvent.h"
#include "Simulation.h"

ExitEvent::ExitEvent(int theTime, Process *theProcess, Simulation *theSim)
: Event(theTime, theProcess, theSim) {}

void ExitEvent::processEvent() {
	int time = getTime();
	Process *process = getProcess();
	process->setExitTime(time);
	cout << header() << " complete. Total wait time is: " << process->getWaitTime() << endl;
}// ExitEvent::processEvent