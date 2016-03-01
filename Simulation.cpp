/**** Simulation implementation */
#include <sstream>
#include <iostream>
#include <iomanip>
#include "Simulation.h"
#include "Event.h"
#include "ArrivalEvent.h"
#include "TimeOutEvent.h"
#include "StartCPUEvent.h"
#include "StartIOEvent.h"
#include "CompleteIOEvent.h"
#include "CompleteCPUEvent.h"
#include "ExitEvent.h"


Simulation::Simulation() {
	eventList = new PriorityQueue;
	processList = new PriorityQueue;
	CPUQueue = new Queue;
	IOQueue = new Queue;
	simulationTime = 0;
	CPUFree = true;
	IOFree = true;
}


void Simulation::runSimulation(char *fileName){
	Event *theEvent;

	// open the input file
	infile.open(fileName);
	// start the simulation by getting the first arrival
	getNextArrival();

	// process events while the event list is not empty
	while(!eventList->isEmpty()){
		theEvent = (Event *)(eventList->removeFirst());
		simulationTime = theEvent->getTime();
		theEvent->processEvent();
		delete theEvent;
	}// while
	infile.close();
}// runSimulation

void Simulation::getNextArrival(){
	// a buffer for reading a line from the file
#define MAX 100
	static char buffer[MAX];
	int arrivalTime;
	int burstTime;
	Event *arrival = NULL;
	infile.getline(buffer, MAX);
	if(!infile.eof()){
		// create a process
		Queue *bursts = new Queue();
		stringstream line(buffer);
		line >> arrivalTime;
		while(!line.eof()){
			line >> burstTime;
			bursts->enqueue(new Burst(burstTime));
		}
		Process *theProcess = new Process(nextProcessID, arrivalTime, bursts, this);
		processList->insert(theProcess);
		nextProcessID++;
		// create the Arrival event and add it to event list
		arrival = new ArrivalEvent(arrivalTime, theProcess, this);
		eventList->insert(arrival);
	}
}// getNextArrival

void Simulation::addStartCPUEvent(Process *process){
	int eventTime = simulationTime;
	Event *event = new StartCPUEvent(eventTime, process, this);
	eventList->insert(event);
}// addStartCPUEvent

void Simulation::addStartIOEvent(Process *process){
	int eventTime = simulationTime;
	Event *event = new StartIOEvent(eventTime, process, this);
	eventList->insert(event);
}// addStartIOEvent

void Simulation::addTimeOutEvent(Process *process){
	int eventTime = simulationTime + CPU_QUANTUM;
	Event *event = new TimeOutEvent(eventTime, process, this);
	eventList->insert(event);
}// addTimeOutEvent

void Simulation::addCompleteCPUEvent(Process *process){
	int eventTime = simulationTime + process->getBurst()->getBurstTime();
	Event *event = new CompleteCPUEvent(eventTime, process, this);
	eventList->insert(event);
}// addCompleteCPUEvent

void Simulation::addCompleteIOEvent(Process *process){
	int eventTime = simulationTime + -1 * process->getBurst()->getBurstTime();
	Event *event = new CompleteIOEvent(eventTime, process, this);
	eventList->insert(event);
}// addCompleteIOEvent

void Simulation::addExitEvent(Process *process){
	int eventTime = simulationTime;
	Event *event = new ExitEvent(eventTime, process, this);
	process->setExitTime(eventTime);
	eventList->insert(event);
}// addExitEvent


int Simulation::getSimulationTime(){ return simulationTime; }
void Simulation::setSimulationTime(int time){ simulationTime = time; }

bool Simulation::CPUAvailable(){ return CPUFree; }
bool Simulation::IOAvailable(){ return IOFree; }

void Simulation::waitForCPU(Process *process){
	CPUQueue->enqueue(process);
	process->setEnqueueTime();
}
void Simulation::waitForIO(Process *process){
	IOQueue->enqueue(process);
	process->setEnqueueTime();
}

void Simulation::scheduleWaitingForCPU(){
	if(!CPUQueue->isEmpty() && CPUAvailable()){
		setCPUBusy();
		Process *process = (Process *)(CPUQueue->getFront());
		Event *event = new StartCPUEvent(simulationTime, process, this);
		process->incrementWaitTime();
		eventList->insert(event);
	}
}// scheduleWaitingForCPU

void Simulation::scheduleWaitingForIO(){
	if(!IOQueue->isEmpty() && IOAvailable()){
		setIOBusy();
		Process *process = (Process *)(IOQueue->getFront());
		Event *event = new StartIOEvent(simulationTime, process, this);
		process->incrementWaitTime();
		eventList->insert(event);
	}
}// scheduleWaitingForIO

void Simulation::setCPUFree(){ CPUFree = true; }
void Simulation::setCPUBusy(){ CPUFree = false; }
void Simulation::dequeueCPU(){ CPUQueue->dequeue(); }
void Simulation::setIOFree(){ IOFree = true; }
void Simulation::setIOBusy(){ IOFree = false; }
void Simulation::dequeueIO(){ IOQueue->dequeue(); }

void Simulation::summary(){
	cout << "  Process   Arrival       CPU       I/O      Exit      Wait\n";
	cout << "        #      Time      Time      Time      Time      Time\n";
	cout << "-----------------------------------------------------------\n";
	while(!processList->isEmpty()){
		Process *process = (Process *)(processList->removeFirst());
		cout << setw(9) << process->getID();
		cout << setw(10) << process->getArrivalTime();
		cout << setw(10) << process->getCPUTime();
		cout << setw(10) << process->getIOTime();
		cout << setw(10) << process->getExitTime();
		cout << setw(10) << process->getWaitTime();
		cout << endl;
		delete process;
	}// while
}// summary