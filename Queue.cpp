/**** Queue implementation */
#include <cstdlib>
#include "Queue.h"

Queue::Queue() :front(NULL), back(NULL), size(0) {}
int Queue::getSize(){ return size; }
bool Queue::isEmpty(){ return size == 0; }

void Queue::enqueue(ListItem *item){
	// special case: adding to empty queue
	if(front == NULL){
		front = new Node(item, NULL);
		back = front;
	} else {
		back->setNext(new Node(item, NULL));
		back = back->getNext();
	}
	size++;
}// enqueue

ListItem *Queue::dequeue(){
	ListItem *theItem = NULL;
	Node *theNode = front;
	if(front != NULL){
		theItem = front->getItem();
		// special case: removing last item
		if(front == back){
			front = back = NULL;
		} else {
			front = front->getNext();
		}
		size--;
		delete(theNode);
	}
	return theItem;
}// dequeue


ListItem *Queue::getFront(){
	ListItem *theItem = NULL;
	//Node *theNode = front;
	if(front != NULL){
		theItem = front->getItem();
	}
	return theItem;
}// getFront