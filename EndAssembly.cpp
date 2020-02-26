// CLASS: EndAssembly.cpp
//
// Author: Patel Zil, 7876456
//
// REMARKS: Subclass of Event class.
//          Causes product arrival for finishing station.
//          Starts assembly at main station if it is able to assemble.
//          Calculates statistics at finishing station
//
//-----------------------------------------------------

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

        // partial product gets created at the main station after P0 and P1 have been assembled
        Part *newPart = new Part(3, sim->getSimulationTime());
        // schedule Product Arrival
        ProductArrival *proEvent = new ProductArrival(getTime(), sim, newPart);
        sim->addEvent(proEvent);

        cout << "At time " << getTime() << ": Part P1 and P2 have been assembled in the Main Station to produce P3." << endl;
    }

    if(myPart->getPartNumber() == 2 && mySecPart->getPartNumber() == 3) // finishing station
    {
        sim->setFinishingStatus(false); // set finishing station is not busy

        sim->incrementProduct(); // increase the number of finished product by 1

        cout << "At time " << sim->getSimulationTime() << ": Part P2 and partial product(P3) have been assembled in Finishing station to produce a finished product." << endl;
    }

    //------- Process the parts accordingly----------------
    // set the end of processing time for each of the part
    myPart->setEndProcessTime(getTime());
    mySecPart->setEndProcessTime(getTime());

    // add the processing times for both of the parts for summary purposes
    int time = (myPart->getEndProcessTime() - myPart->getArrivalTime());
    int secTime = (mySecPart->getEndProcessTime() - mySecPart->getArrivalTime());
    sim->incrementProcessingTime(max(time,secTime));

    // remove front part from the respective queues as they have been processed
    sim->removePart(myPart->getPartNumber());
    sim->removePart(mySecPart->getPartNumber());
    //-----------------------------------------------------

    // both P0 and P1 are waiting and main station is not busy
    if(!sim->getPartQueues(0)->isEmpty() && !sim->getPartQueues(1)->isEmpty() && !sim->isMainBusy())
    {
        StartAssembly *newStart = new StartAssembly(sim->getSimulationTime(), sim, dynamic_cast<Part *>(sim->getPartQueues(0)->getFront()), dynamic_cast<Part *>(sim->getPartQueues(1)->getFront())); // start assemblying  P0
        sim->addEvent(newStart);
    }
}// end processEvent

EndAssembly::~EndAssembly() {}