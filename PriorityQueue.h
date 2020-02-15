#pragma once

class Node;
class OrderedItem;

class PriorityQueue {
private:
    Node *front; // front of the PriorityQueue
    int size; // size of the PriorityQueue
public:
    PriorityQueue();
    bool isEmpty();
    OrderedItem *getFront();
    void insert(OrderedItem *); // ordered insert of events
    void deleteHighest(); // remove from front the event that needs to be simulated
};// class PriorityQueue
