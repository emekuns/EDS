/**** ListItem abstract interface */
#ifndef __LISTITEM_H_INCLUDED__   
#define __LISTITEM_H_INCLUDED__ 

class ListItem {
public:
	virtual int compareTo(ListItem *other) = 0;
	virtual ~ListItem();
}; // class ListItem

#endif