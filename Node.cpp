/**** Node implementation */
#include <cstdlib>
#include "Node.h"

Node::Node() :item(NULL), next(NULL)  {}
Node::Node(ListItem *i, Node *n) :item(i), next(n) {}
Node *Node::getNext() {return next;}
void Node::setNext(Node *n) {next=n;}
ListItem *Node::getItem() {return item;}