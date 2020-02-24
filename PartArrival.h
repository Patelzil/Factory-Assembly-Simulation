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
