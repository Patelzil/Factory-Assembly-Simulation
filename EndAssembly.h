#pragma once

#include "Event.h"
class Part;

class EndAssembly: public Event
{
private:
    Part *myPart;
    Part *mySecPart;
public:
    EndAssembly(int, Simulation *, Part *, Part *);
    ~EndAssembly();
    void processEvent();
};// class EndAssembly
