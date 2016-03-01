/**** Burst implementation */
#include <cstdlib>
#include "Burst.h"

Burst::Burst(int time) : burstTime(time) {}
Burst::~Burst() {}
int Burst::getBurstTime(){ return burstTime; }
void Burst::setBurstTime(int time){ burstTime = time; }
int Burst::compareTo(ListItem *other){
	int theResult = 0;
	Burst *otherBurst = dynamic_cast<Burst *>(other);
	if(otherBurst != NULL)
		theResult = this->burstTime - otherBurst->burstTime;
	return theResult;
}