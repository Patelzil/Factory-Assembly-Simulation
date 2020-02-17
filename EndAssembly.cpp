#include "EndAssembly.h"
#include "Part.h"
#include <iostream>
using namespace std;

EndAssembly::EndAssembly(int theTime, Simulation *sim, Part *thePart): Event(theTime,sim), myPart(thePart){}

// todo:
//  1) For the main station, create ProductArrival event.
//     If main station available & P0,P1 are waiting schedule StartAssembly.
//  2) For the finishing station calculate statistics for the assembly of product.
void EndAssembly::processEvent()
{

}// end processEvent

void EndAssembly::print()
{
    cout << "At time " << getTime() << " Part P" << myPart->getPartNumber() << " has been assembled." << endl;
}// print

EndAssembly::~EndAssembly() {}