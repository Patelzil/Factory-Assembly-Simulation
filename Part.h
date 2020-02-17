#pragma once

#include "ListItem.h"

class Part: public ListItem
{
private:
    int partNumber; // what part is it? 0,1 or 2?
    int arrivalTime; // when will the part arrive?
    int departTime; // when is the part going to depart?
    int waitTime; // how long a part waited in the queue before assembly started
    int startAssyTime;
public:
    Part(int, int);
    int getPartNumber();
    void print();
    ~Part();
};// class Part
