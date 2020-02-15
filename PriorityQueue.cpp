#include "PriorityQueue.h"
#include "Node.h"
#include "OrderedItem.h"

PriorityQueue::PriorityQueue() : front(nullptr), size(0) {}
int PriorityQueue::getSize() {return size; }
bool PriorityQueue::isEmpty() {return size == 0;}

OrderedItem *PriorityQueue::getFront()
{
    OrderedItem *result = nullptr;
    if(front != nullptr){
        result = dynamic_cast<OrderedItem *> (front->getItem());
    }
    return result;
}// getFront

void PriorityQueue::insert(OrderedItem *newItem )
{
    Node *curr = front;
    Node *prev = nullptr;

    // search for the position at which the newItem will be placed in the priority queue
    // condition equal to zero so that an event with similar eventTime is added later as it came after the already present event
    while(curr != nullptr && ((dynamic_cast<OrderedItem *>(curr->getItem()))->compareTo(newItem) <= 0))
    {
        prev = curr;
        curr = curr->getNext();
    }

    // insert the newItem into the Priority queue
    if(prev != nullptr)
    {
        prev->setNext(new Node(newItem, curr));
    }
    else // special case: adding to empty priority queue
    {
        front = new Node(newItem, nullptr);
    }
    size++;
}

void PriorityQueue::deleteHighest()
{
    size--;
}

// destructor
PriorityQueue::~PriorityQueue() {}