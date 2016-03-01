/**** Process interface */
#ifndef __PROCESS_H_INCLUDED__   
#define __PROCESS_H_INCLUDED__ 

#include "Queue.h"
#include "ListItem.h"
#include "Burst.h"

class Simulation;

class Process: public ListItem{
private:
	int ID;
	int arrivalTime;
	int CPUTime;
	int IOTime;
	int waitTime;
	int exitTime;
	int enqueueTime;
	Queue *bursts;
	Simulation * sim;
public:
	Process(int n, int a, Queue *b, Simulation* theSim);
	int getArrivalTime( );
	int getWaitTime( );
	int getCPUTime( );
	int getIOTime( );
	int getExitTime( );
	void setEnqueueTime( );
	void setExitTime(int time);
	void incrementWaitTime( );
	void incrementCPUTime(int time);
	void incrementIOTime(int time);
	int getID();
	int compareTo(ListItem *other);
	Burst *getBurst();
	void removeBurst();
	bool hasMoreBursts();
	int numberOfBursts();
};// class Process

#endif