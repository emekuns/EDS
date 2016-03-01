/**** Node interface */
#ifndef __NODE_H_INCLUDED__   
#define __NODE_H_INCLUDED__ 

class ListItem;

class Node {
private:
	ListItem *item;
	Node *next;
public:
	Node();
	Node(ListItem *i, Node *n);
	Node *getNext();
	void setNext(Node *next);
	ListItem *getItem();
	void setItem(ListItem *i);
}; // class Node

#endif