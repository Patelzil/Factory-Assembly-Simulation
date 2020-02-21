#include "StartAssembly.h"
#include "Part.h"
#include "Simulation.h"
#include "EndAssembly.h"
#include <iostream>
using namespace std;


// constructor
StartAssembly::StartAssembly(int theTime, Simulation *sim, Part *thePart, Part *theOtherPart)
    : Event(theTime, sim), myPart(thePart),mySecondPart(theOtherPart) {}

// End Assembly to be scheduled.
// Set respective stations to busy
void StartAssembly::processEvent()
{
    EndAssembly *newAssy;
    int time;
    if(myPart->getPartNumber() == 0 && mySecondPart->getPartNumber() == 1) // main station parts
    {
        cout << "At time " << sim->getSimulationTime() << ": Part P0 and P1 starts assembly at the Main Station." << endl;
        sim->setMainStatus(true); // set main station to be busy
        time = getTime() + sim->getMainAssemblyTime();
        // schedule and create an end assembly event
        newAssy = new EndAssembly(time,sim,myPart,mySecondPart);
        sim->addEvent(newAssy);
    }

    if(myPart->getPartNumber() == 2 && mySecondPart->getPartNumber() == 3)// finishing station
    {
        cout << "At time " << sim->getSimulationTime() << ": Part P2 and P3 starts assembly at the Finishing Station." << endl;
        sim->setFinishingStatus(true); // finishing station becomes busy
        time = getTime() + sim->getFinishingAssemblingTime();
        // schedule and create an end assembly event
        newAssy = new EndAssembly(time,sim,myPart,mySecondPart);
        sim->addEvent(newAssy);
    }
//    // schedule and create an end assembly event
//    EndAssembly *newAssy = new EndAssembly(time,sim,myPart,mySecondPart);
//    sim->addEvent(newAssy);
}// processEvent

// destructor
StartAssembly::~StartAssembly() {}