/**** Queue interface */
#ifndef __QUEUE_H_INCLUDED__   
#define __QUEUE_H_INCLUDED__ 

#include "Node.h"
class ListItem;

class Queue {
private:
	Node *front;
	Node *back;
	int size;
public:
	Queue();
	int getSize();
	bool isEmpty();
	void enqueue(ListItem *item);
	ListItem *getFront();
	ListItem *dequeue();
}; // class Queue

#endif