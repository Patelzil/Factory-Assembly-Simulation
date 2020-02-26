// CLASS: Part.cpp
//
// Author: Patel Zil, 7876456
//
// REMARKS: Part objects for different stations:
//          P0 and P1 for main station
//          P2 and P3(Partial Product) for finishing station
//          contains part num, its arrival time and processing time.
//
//-----------------------------------------

#include "Part.h"

Part::Part(int newPartNum, int newTime) :partNumber(newPartNum), arrivalTime(newTime), endProcessTime(0){}

int Part::getPartNumber() { return partNumber; }
int Part::getEndProcessTime() {return endProcessTime; }
int Part::getArrivalTime() { return arrivalTime; }
void Part::setEndProcessTime(int time) { endProcessTime = time; }
// destructor
Part::~Part() {}