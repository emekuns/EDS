#include <iostream>
#include "StartIOEvent.h"
#include "Simulation.h"

StartIOEvent::StartIOEvent(int theTime, Process *theProcess, Simulation *theSim)
: Event(theTime, theProcess, theSim) {}

void StartIOEvent::processEvent() {
	Process *process = getProcess();
	int burstTime = -1 * process->getBurst()->getBurstTime();
	process->incrementIOTime(burstTime);
	sim->setIOBusy();
	cout << header() << " begins I/O burst of length " << burstTime << ".\n";
	sim->addCompleteIOEvent(process);
}// StartIOEvent::processEvent