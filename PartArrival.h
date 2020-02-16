#pragma once

#include "Event.h"
class Part;

class PartArrival: public Event
{
private:
    Part *myPart;
public:
    PartArrival();
    void print();
};// class PartArrival
