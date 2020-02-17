#pragma once

#include "Event.h"
class Part;

class StartAssembly: public Event
{
private:
    Part *myPart;
public:
    StartAssembly(int , Simulation *, Part *);
    ~StartAssembly();
    void processEvent();
    void print();
};// StartAssembly
