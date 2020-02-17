#include "PartArrival.h"
#include "Part.h"
#include <iostream>
using namespace std;

PartArrival::PartArrival(int theTime, Simulation *sim, Part *thePart): Event(theTime, sim), myPart(thePart){}

// todo: Add part to the respective queue
void PartArrival::processEvent()
{

}// processEvent

// todo: add a print statement
void PartArrival::print()
{
    cout << "At time " << getTime() << " Part P" << myPart->getPartNumber() << " arrives." << endl;
}// print

//destructor
PartArrival::~PartArrival(){}