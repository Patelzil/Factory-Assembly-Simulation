// CLASS: Part.h
//
// Author: Patel Zil, 7876456
//
//-----------------------------------------

#pragma once

#include "ListItem.h"

class Part: public ListItem
{
private:
    int partNumber; // what part is it? 0,1 or 2?
    int arrivalTime; // when will the part arrive?
    int endProcessTime; // when is the part going to be processed?
public:
    Part(int part, int time);
    int getPartNumber();
    int getArrivalTime();
    int getEndProcessTime();
    void setEndProcessTime(int time);
    ~Part();
};// class Part
