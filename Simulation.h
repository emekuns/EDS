/**** Simulation interface */
#ifndef __SIMULATION_H_INCLUDED__   
#define __SIMULATION_H_INCLUDED__

#include <fstream>
#include "PriorityQueue.h"
#include "Queue.h"
#include "Process.h"

using namespace std;

class Simulation {
private:
	ifstream infile;
	static int nextProcessID;
	int simulationTime;
	PriorityQueue *eventList;
	PriorityQueue *processList;
	Queue *CPUQueue;
	Queue *IOQueue;
	bool CPUFree;
	bool IOFree;
public:
	static const int CPU_QUANTUM;
	Simulation();
	int getSimulationTime();
	void setSimulationTime(int time);

	void runSimulation(char *fileName);
	void summary();

	void getNextArrival();
	void addStartCPUEvent(Process *process);
	void addStartIOEvent(Process *process);
	void addTimeOutEvent(Process *process);
	void addCompleteCPUEvent(Process *process);
	void addCompleteIOEvent(Process *process);
	void addExitEvent(Process *process);

	void waitForCPU(Process *process);
	void waitForIO(Process *process);
	void scheduleWaitingForCPU();
	void scheduleWaitingForIO();
	void dequeueCPU();
	void dequeueIO();
	bool CPUAvailable();
	bool IOAvailable();
	void setCPUFree();
	void setCPUBusy();
	void setIOFree();
	void setIOBusy();
};// class Simulation

#endif