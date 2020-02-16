#pragma once

#include "Event.h"

class StartAssembly: public Event
{
public:
    StartAssembly();
    ~StartAssembly();
    void processEvent();
};// StartAssembly
