#include <iostream>
#include "StartCPUEvent.h"
#include "Simulation.h"

StartCPUEvent::StartCPUEvent(int theTime, Process *theProcess, Simulation *theSim)
: Event(theTime, theProcess, theSim) {}

void StartCPUEvent::processEvent() {
	Process *process = getProcess();
	Burst *burst = process->getBurst();
	int burstTime = burst->getBurstTime();
	sim->setCPUBusy();
	cout << header() << " begins CPU burst of length " << burstTime << ".\n";
	if(burstTime <= Simulation::CPU_QUANTUM){
		process->incrementCPUTime(burstTime);
		sim->addCompleteCPUEvent(process);
	} else {
		burst->setBurstTime(burstTime - Simulation::CPU_QUANTUM);
		process->incrementCPUTime(Simulation::CPU_QUANTUM);
		sim->addTimeOutEvent(process);
	}
}// StartCPUEvent::processEvent