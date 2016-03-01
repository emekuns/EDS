/**** PriorityQueue interface */
#ifndef __PRIORITYQUEUE_H_INCLUDED__   
#define __PRIORITYQUEUE_H_INCLUDED__ 

#include "Node.h"
#include "ListItem.h"

class PriorityQueue {
private:
	Node *first;
	int size;
public:
	PriorityQueue();
	int getSize();
	bool isEmpty();
	void insert(ListItem *item);
	ListItem *removeFirst();
}; // class PriorityQueue

#endif