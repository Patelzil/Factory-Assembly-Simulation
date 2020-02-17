#include "Part.h"
#include <iostream>
using namespace std;

Part::Part(int newPartNum, int newTime) :partNumber(newPartNum), arrivalTime(newTime), departTime(0), waitTime(0){}

int Part::getPartNumber() { return partNumber; }

void Part::print()
{
    cout << "Part: P" << partNumber << "   Arrival time: " << arrivalTime << "   Wait time: " << waitTime << "   Departure time: " << endl;
}// print

// destructor
Part::~Part() {}