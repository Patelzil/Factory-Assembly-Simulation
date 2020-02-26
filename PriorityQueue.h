// CLASS: PriorityQueue.h
//
// Author: Patel Zil, 7876456
//
//-----------------------------------------

#pragma once

#include "ListItem.h"
class Node;
class OrderedItem;

class PriorityQueue: public ListItem {
private:
    Node *front; // front of the PriorityQueue
    int size; // size of the PriorityQueue
public:
    PriorityQueue();
    int getSize();
    bool isEmpty();
    OrderedItem *getFront();
    void insert(OrderedItem *); // ordered insert of events
    OrderedItem *deleteHighest(); // remove from front the event that needs to be simulated
    ~PriorityQueue();
};// class PriorityQueue
