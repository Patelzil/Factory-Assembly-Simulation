// CLASS: PartArrival.cpp
//
// Author: Patel Zil, 7876456
//
// REMARKS: Subclass of Event class.
//          Schedules start assembly if the proper parts
//          of a station are waiting. Adds the part
//          to its respective queue.
//
//-----------------------------------------

#include "PartArrival.h"
#include "Part.h"
#include "Simulation.h"
#include "StartAssembly.h"
#include "Queue.h"
#include <iostream>
using namespace std;

PartArrival::PartArrival(int theTime, Simulation *sim, Part *thePart): Event(theTime, sim), myPart(thePart){}

/* processEvent()
 *
 * 1) Adds the part to its respective queue.
 *    Prints the appropriate message related to the arrival
 * 2) Checks if both the stations are able to assemble a product.
 *    If yes then start assembly is scheduled
 * 3) Gets next arrival from the file.
 *
 */
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
            cout << "At time " << getTime() << ": P0 arrived at the main station." << endl;
        }
        else
        {
            cout << "At time " << getTime() << ": P1 arrived at the main station." << endl;
        }

        if(!sim->getPartQueues(0)->isEmpty() && !sim->getPartQueues(1)->isEmpty() && !sim->isMainBusy())
        {
            StartAssembly *newStart = new StartAssembly(getTime(), sim, dynamic_cast<Part *>(sim->getPartQueues(0)->getFront()), dynamic_cast<Part *>(sim->getPartQueues(1)->getFront())); // start assemblying  P0
            sim->addEvent(newStart);
        }
    }
    else if(myPart->getPartNumber() == 2)
    {
        cout << "At time " << getTime() << ": P2 arrived at the Finishing Station." << endl;
        if(!sim->getPartQueues(2)->isEmpty() && !sim->getProductQueue()->isEmpty() && !sim->isFinishingBusy())
        {
            StartAssembly *newStart = new StartAssembly(sim->getSimulationTime(), sim, dynamic_cast<Part *>(sim->getPartQueues(2)->getFront()), dynamic_cast<Part *>(sim->getPartialProduct())); // start assemblying  P0
            sim->addEvent(newStart);
        }
    }

    sim->getNextArrival();
}// processEvent

//destructor
PartArrival::~PartArrival(){}