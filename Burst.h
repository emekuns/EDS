/**** Burst interface */
#ifndef __BURST_H_INCLUDED__   
#define __BURST_H_INCLUDED__ 

#include "ListItem.h"

class Burst: public ListItem {
private:
	int burstTime;
public:
	Burst(int time);
	int compareTo(ListItem *other);
	int getBurstTime();
	void setBurstTime(int time);
	~Burst();
}; // class Burst

#endif