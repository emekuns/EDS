#include <iostream>
#include "CompleteIOEvent.h"
#include "Simulation.h"

CompleteIOEvent::CompleteIOEvent(int theTime, Process *theProcess, Simulation *theSim)
: Event(theTime, theProcess, theSim) {}

void CompleteIOEvent::processEvent() {
	Process *process = getProcess();
	process->removeBurst();
	sim->dequeueIO();
	sim->setIOFree();
	cout << header() << " completes I/O burst.";
	if(process->hasMoreBursts()) {
		sim->waitForCPU(process);
		cout << " Queueing for CPU." << endl;
	} else {
		cout << endl;
		sim->addExitEvent(process);
	}
	sim->scheduleWaitingForCPU();
	sim->scheduleWaitingForIO();
}// CompleteIOEvent::processEvent