/**** Process implementation */
#include <cstdlib>
#include "Process.h"
#include "Simulation.h"

Process::Process(int n, int a, Queue *b, Simulation* theSim)
:ID(n), arrivalTime(a), bursts(b), CPUTime(0), IOTime(0),
 enqueueTime(0), waitTime(0), exitTime(0), sim(theSim) {}
int Process::getCPUTime(){ return CPUTime; }
int Process::getIOTime(){ return IOTime; }
int Process::getWaitTime(){ return waitTime; }
int Process::getExitTime(){ return exitTime; }
int Process::getArrivalTime(){ return arrivalTime; }
int Process::getID(){ return ID; }
void Process::setEnqueueTime(){ enqueueTime = sim->getSimulationTime(); }
void Process::setExitTime(int time){ exitTime = time; }
void Process::incrementCPUTime(int time){ CPUTime += time; }
void Process::incrementIOTime(int time){ IOTime += time; }
bool Process::hasMoreBursts( ){ return !bursts->isEmpty(); }
void Process::incrementWaitTime(){
	waitTime += sim->getSimulationTime() - enqueueTime;
}
Burst *Process::getBurst(){ return (Burst *)bursts->getFront(); }
void Process::removeBurst(){ bursts->dequeue(); }
int Process::numberOfBursts(){ return bursts->getSize(); }
int Process::compareTo(ListItem *other){
	int result = 0;
	Process *otherProcess = dynamic_cast<Process *>(other);
	if(otherProcess != NULL){
		result = this->ID - otherProcess->ID;
	}
	return result;
}// compareTo