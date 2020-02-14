#include "Event.h"

Event::Event(int theTime, Simulation *theSim) :eventTime(theTime), sim (theSim) {}
Event::~Event() {}
int Event::getTime(){ return eventTime; }

int Event::compareTo(OrderedItem *other){
	return -1; // you must implement this.
}// compareTo
