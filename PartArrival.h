#pragma once

#include "Event.h"
class Part;

class PartArrival: public Event
{
private:
    Part *myPart;
public:
    PartArrival(int, Simulation *, Part *);
    void print();// prints arrival of a part
    void processEvent(); // processes arrival
    ~PartArrival();
};// class PartArrival
