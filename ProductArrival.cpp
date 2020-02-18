#include <iostream>
#include "ProductArrival.h"
#include "Part.h"
#include "Simulation.h"
#include "Queue.h"
#include "StartAssembly.h"
using namespace std;

ProductArrival::ProductArrival(int theTime, Simulation *sim, Part *thePart) : Event(theTime, sim), myPart(thePart) {}

void ProductArrival::processEvent()
{
    // P2 is waiting and finishing station not busy
    if(!sim->getPartQueues(2)->isEmpty() && !sim->isFinishingBusy())
    {
        cout << "At time " << sim->getSimulationTime() << ": Product arrives to be assembled by Finishing Station." << endl;
        StartAssembly *newStart = new StartAssembly(sim->getSimulationTime(), sim, dynamic_cast<Part *>(sim->getPartQueues(2)->getFront()), sim->getPartialProduct());
        sim->addEvent(newStart);
    }
    else
    {
        cout << "At time " << getTime() << ": Part P3 arrives in Finishing Station. (Waiting in queue)." << endl;
        sim->addPartialProduct(myPart); //add to partial products queue
    }
}// processEvent

ProductArrival::~ProductArrival() {}