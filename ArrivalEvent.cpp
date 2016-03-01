#include <iostream>
#include "ArrivalEvent.h"
#include "Simulation.h"

ArrivalEvent::ArrivalEvent(int theTime, Process *theProcess, Simulation *theSim)
: Event(theTime, theProcess, theSim) {}

void ArrivalEvent::processEvent(){
	sim->getNextArrival();
	Process *process = getProcess();
	cout << header() << " arrives in system: ";
	sim->waitForCPU(process);
	if(sim->CPUAvailable()){
		cout << "CPU is free (process begins execution)." << endl;
		sim->scheduleWaitingForCPU();
	} else {
		cout << "CPU is busy (process will be queued)." << endl;
	}
}// ArrivalEvent::processEvent