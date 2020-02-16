#pragma once

#include "Event.h"

class StartAssembly: public Event
{
public:
    StartAssembly(int theTime, Simulation *sim);
    ~StartAssembly();
    void processEvent();
};// StartAssembly
