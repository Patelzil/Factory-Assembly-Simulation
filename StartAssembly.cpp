#include "StartAssembly.h"
#include <iostream>
using namespace std;

// constructor
StartAssembly::StartAssembly(int theTime, Simulation *sim, Part *thePart) : Event(theTime, sim), myPart(thePart) {}

// todo: End Assembly to be scheduled.
//       Set main station to busy
void StartAssembly::processEvent()
{

}// processEvent

void StartAssembly::print()
{
    cout << "At time " << getTime() << " Part P" << myPart->getPartNumber() << " starts to be assembled."
}// print

// destructor
StartAssembly::~StartAssembly() {}