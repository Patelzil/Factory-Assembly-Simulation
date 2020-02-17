#include <string>
#include <fstream>
#include "Simulation.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "Event.h"
#include "PartArrival.h"


int Simulation::getMainAssemblyTime() { return mainAssemblyTime; }
int Simulation::getFinishingAssemblingTime() { return finishingAssemblyTime; }
int Simulation::getSimulationTime() { return simulationTime; }
void Simulation::setSimulationTime(int time) { simulationTime = time; }
bool Simulation::isMainBusy(){ return mainBusy; }
bool Simulation::isFinishingBusy(){ return finishingBusy; }
void Simulation::setMainStatus(bool value){ mainBusy = value; }
void Simulation::setFinishingStatus(bool value){ finishingBusy = value; }


Simulation::Simulation()
:simulationTime(0),mainAssemblyTime(0),finishingAssemblyTime(0),mainBusy(false),
finishingBusy(false),partQueues(new Queue*[3]){}// Simulation

// todo: main method for driving the simulation
void Simulation::runSimulation(char *fileName)
{
    OrderedItem *theItem; // to store the event with highest priority
    eventList = new PriorityQueue;
    productQueue = new Queue;
    string line;

    ifile.open(fileName); // open the file
    getline(ifile, line);

    for(int i=0; i<2 ;i++)
    {

    }

    // read the first arrival event from the data file and put it in the event list
    // this event has to be an arrival!

    while (!eventList->isEmpty())
    {
        theItem = eventList->deleteHighest();
        if(PartArrival *part = dynamic_cast<PartArrival *>(theItem))
        {
            part->processEvent();
        }
        else if ()
    }
    //take next event from the (time-ordered) event list;
    //if this is an arrival event then
    //      Process an Arrival
    //else
    //      Process a Departure
    //endif
    //endwhile

    ifile.close(); // close the file after reading it
}// runSimulation

// add an event to event queue.
void Simulation::addEvent (Event *newEvent)
{
    eventList->insert(newEvent);
}// addEvent


// todo: read next arrival from file and add it to the event queue.
void Simulation::getNextArrival()
{

}

