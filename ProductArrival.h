#pragma once

#include "Event.h"

class ProductArrival: public Event
{
public:
    ProductArrival();
    ~ProductArrival();
    void processEvent();
};// class ProductArrival
