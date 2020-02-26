// CLASS: Event.cpp
//
// Author: Patel Zil, 7876456
//
// REMARKS: Parent class to all the events.
//        Compares 2 events according to its time,
//          used before insertion to priority queue
//
//-----------------------------------------

#include "Event.h"

Event::Event(int theTime, Simulation *theSim) :eventTime(theTime), sim (theSim) {}
Event::~Event() {}
int Event::getTime(){ return eventTime; }

/* compareTo(OrderedItem *)
 *
 * compares the eventTime of two events
 * Returns: 0 if the eventTimes are equal
 *          +ve number if the first eventTime is later than the second one
 *          -ve number if the second eventTime is later than the first one
 */
int Event::compareTo(OrderedItem *other)
{
    Event *myEvent = dynamic_cast<Event *>(other);
	return ((this->eventTime) - (myEvent->eventTime));
}// compareTo
