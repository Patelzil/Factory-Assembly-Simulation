#include "EndAssembly.h"
#include "Part.h"
#include "ProductArrival.h"
#include "Simulation.h"
#include "StartAssembly.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include <iostream>
using namespace std;

EndAssembly::EndAssembly(int theTime, Simulation *sim, Part *thePart, Part *theOtherPart)
    : Event(theTime,sim), myPart(thePart), mySecPart(theOtherPart){}

//  1) For the main station, create ProductArrival event.
//     If main station available & P0,P1 are waiting schedule StartAssembly.
//  2) For the finishing station calculate statistics for the assembly of product.
void EndAssembly::processEvent()
{
    if(myPart->getPartNumber() == 0 && mySecPart->getPartNumber() == 1) // main station parts
    {
        sim->setMainStatus(false); // set main station to not busy
        cout << "At time " << getTime() << ": Part P1 and P2 have been assembled in the Main Station to produce P3." << endl;
        sim->incrementParts();  // number of parts increment by 2(p0 and p1)

        // remove front part from the respective queues
        sim->removePart(myPart->getPartNumber());
        sim->removePart(mySecPart->getPartNumber());

        Part *newPart = new Part(3, sim->getSimulationTime());
        //sim->addPartialProduct(newPart);

        // schedule Product Arrival
        ProductArrival *proEvent = new ProductArrival(getTime(), sim, newPart);
        sim->addEvent(proEvent);
    }

    if(myPart->getPartNumber() == 2 && mySecPart->getPartNumber() == 3) // finishing station
    {
        sim->setFinishingStatus(false); // set finishing station is not busy

        sim->incrementParts(); // number of parts increment by 2(p3 and p2)

        sim->removePart(myPart->getPartNumber());
        sim->removePart(mySecPart->getPartNumber());
        cout << "At time " << sim->getSimulationTime() << ": Part P2 and P3 have been assembled in Finishing station to produce a finished product." << endl;
    }

    // both P0 and P1 are waiting and main station is not busy
    if(!sim->getPartQueues(0)->isEmpty() && !sim->getPartQueues(1)->isEmpty() && !sim->isMainBusy())
    {
        StartAssembly *newStart = new StartAssembly(sim->getSimulationTime(), sim, dynamic_cast<Part *>(sim->getPartQueues(0)->getFront()), dynamic_cast<Part *>(sim->getPartQueues(1)->getFront())); // start assemblying  P0
        sim->addEvent(newStart);
    }
}// end processEvent

EndAssembly::~EndAssembly() {}