#pragma once

#include "Event.h"
class Part;

class EndAssembly: public Event
{
private:
    Part *myPart;
public:
    EndAssembly(int, Simulation *, Part *);
    ~EndAssembly();
    void processEvent();
};// class EndAssembly
