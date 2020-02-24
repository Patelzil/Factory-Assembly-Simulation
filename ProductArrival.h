#pragma once

#include "Event.h"
class Part;

class ProductArrival: public Event
{
private:
    Part *myPart;
public:
    ProductArrival(int, Simulation *, Part *);
    ~ProductArrival();
    void processEvent();
};// class ProductArrival
