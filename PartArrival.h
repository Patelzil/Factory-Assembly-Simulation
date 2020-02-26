// CLASS: PartArrival.h
//
// Author: Patel Zil, 7876456
//
//-----------------------------------------

#pragma once

#include "Event.h"
class Part;

class PartArrival: public Event
{
private:
    Part *myPart;
public:
    PartArrival(int, Simulation *, Part *);
    void processEvent(); // processes arrival
    ~PartArrival();
};// class PartArrival
