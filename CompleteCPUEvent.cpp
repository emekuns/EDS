#include <iostream>
#include "CompleteCPUEvent.h"
#include "Simulation.h"

CompleteCPUEvent::CompleteCPUEvent(int theTime, Process *theProcess, Simulation *theSim)
: Event(theTime, theProcess, theSim) {}

void CompleteCPUEvent::processEvent() {
	Process *process = getProcess();
	process->removeBurst();
	sim->dequeueCPU();
	sim->setCPUFree();
	cout << header() << " completes CPU burst.";
	if(process->hasMoreBursts()) {
		sim->waitForIO(process);
		cout << " Queueing for I/O." << endl;
	} else {
		cout << endl;
		sim->addExitEvent(process);
	}
	sim->scheduleWaitingForCPU();
	sim->scheduleWaitingForIO();
}// CompleteCPUEvent::processEvent