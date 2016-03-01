/**** PriorityQueue implementation */
#include <cstdlib>
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() :first(NULL), size(0) {}
int PriorityQueue::getSize(){ return size; }
bool PriorityQueue::isEmpty(){ return size == 0; }

void PriorityQueue::insert(ListItem *item){
	Node *prev = NULL;
	Node *curr = first;
	// find the spot to insert this item
	while(curr != NULL && item->compareTo(curr->getItem()) > 0){
		prev = curr;
		curr = curr->getNext();
	}
	// special case: adding to front
	if(prev == NULL){
		first = new Node(item, curr);
	} else {
		prev->setNext(new Node(item, curr));
	}
	size++;
}// insert

ListItem *PriorityQueue::removeFirst(){
	Node *theNode = first;
	ListItem *theItem = NULL;
	if(first != NULL){
		theItem = first->getItem();
		first = first->getNext();
		delete theNode;
		size--;
	}
	return theItem;
}// removeFirst