#include <iostream>
#include "ProductArrival.h"
#include "Part.h"
#include "Simulation.h"
#include "Queue.h"
#include "StartAssembly.h"
using namespace std;

ProductArrival::ProductArrival(int theTime, Simulation *sim, Part *thePart) : Event(theTime, sim), myPart(thePart) {}

// todo:
void ProductArrival::processEvent()
{
    // P2 is waiting and finishing station not busy
    if(!sim->getPartQueues(2)->isEmpty() && !sim->isFinishingBusy())
    {
        cout << "At time " <<  << ": Product arrives to be assembled by Finishing Station." << endl;
        StartAssembly *newStart = new StartAssembly(sim->getSimulationTime(), sim, dynamic_cast<Part *>(sim->getPartQueues(2)->getFront()));
        StartAssembly *secondStart = new StartAssembly(sim->getSimulationTime(), sim, sim->getPartialProduct());
        sim->addEvent(newStart);
        sim->addEvent(secondStart);
    }
    else
    {
        cout << "At time " << getTime() << ": Part P3 arrives in Finishing Station. (Waiting in queue)." << endl;
        sim->addPartialProduct(myPart); //add to partial products queue
    }
}// processEvent

ProductArrival::~ProductArrival() {}