#pragma once

#include "Event.h"

class EndAssembly: public Event
{
public:
    EndAssembly();
    ~EndAssembly();
    void processEvent();
};// class EndAssembly
