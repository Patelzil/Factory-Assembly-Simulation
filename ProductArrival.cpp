#include <iostream>
#include "ProductArrival.h"
#include "Part.h"
using namespace std;

ProductArrival::ProductArrival(int theTime, Simulation *sim, Part *thePart) : Event(theTime, sim), myPart(thePart) {}

// todo:
void ProductArrival::processEvent()
{

}// processEvent

void ProductArrival::print()
{
    cout << "At time " << getTime() << " product arrives to be assembled by Finishing Station." << endl;
}// print

ProductArrival::~ProductArrival() {}