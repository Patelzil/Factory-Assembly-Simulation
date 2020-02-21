#include "PartArrival.h"
#include "Part.h"
#include "Simulation.h"
#include "StartAssembly.h"
#include "Queue.h"
#include <iostream>
using namespace std;

PartArrival::PartArrival(int theTime, Simulation *sim, Part *thePart): Event(theTime, sim), myPart(thePart){}

// todo: Add part to the respective queue
void PartArrival::processEvent()
{
    // add part to the respective queue
    sim->addPart(myPart->getPartNumber(), myPart);

    // both P0 and P1 are waiting and main station is not busy
    if(myPart->getPartNumber() == 0 || myPart->getPartNumber() == 1)
    {
        // print part arrival
        if(myPart->getPartNumber() == 0)
        {
            cout << "At time " << getTime() << ": P0 arrived." << endl;
        }
        else
        {
            cout << "At time " << getTime() << ": P1 arrived." << endl;
        }

        if(!sim->getPartQueues(0)->isEmpty() && !sim->getPartQueues(1)->isEmpty() && !sim->isMainBusy())
        {
            StartAssembly *newStart = new StartAssembly(getTime(), sim, dynamic_cast<Part *>(sim->getPartQueues(0)->getFront()), dynamic_cast<Part *>(sim->getPartQueues(1)->getFront())); // start assemblying  P0
            sim->addEvent(newStart);
        }
    }
    else if(myPart->getPartNumber() == 2)
    {
        cout << "At time " << getTime() << ": P2 arrived." << endl;
        if(!sim->getPartQueues(2)->isEmpty() && !sim->getProductQueue()->isEmpty() && !sim->isFinishingBusy())
        {
            StartAssembly *newStart = new StartAssembly(sim->getSimulationTime(), sim, dynamic_cast<Part *>(sim->getPartQueues(2)->getFront()), dynamic_cast<Part *>(sim->getPartialProduct())); // start assemblying  P0
            sim->addEvent(newStart);
        }
    }

    sim->getNextArrival();
}// processEvent

void PartArrival::print()
{
    cout << "At time " << getTime() << " Part P" << myPart->getPartNumber() << " arrives." << endl;
}// print

//destructor
PartArrival::~PartArrival(){}