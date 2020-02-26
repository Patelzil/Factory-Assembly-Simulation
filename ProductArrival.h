// CLASS: ProductArrival.h
//
// Author: Patel Zil, 7876456
//
//-----------------------------------------

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
