#include <iostream>
#include "TimeOutEvent.h"
#include "Simulation.h"

TimeOutEvent::TimeOutEvent(int theTime, Process *theProcess, Simulation *theSim)
: Event(theTime, theProcess, theSim) {}

void TimeOutEvent::processEvent() {
	Process *process = getProcess();
	int remainingTime = process->getBurst()->getBurstTime();
	cout << header() << " exhausts its time quantum (requires " ;
	cout << remainingTime << " units more)." << endl;
	sim->dequeueCPU();
	sim->setCPUFree();
	sim->waitForCPU(process);
	sim->scheduleWaitingForCPU();
}// TimeOutEvent::processEvent