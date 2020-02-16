#include "Simulation.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "Event.h"

int Simulation::getSimulationTime() { return simulationTime; }
void Simulation::setSimulationTime(int time) { simulationTime = time; }
bool Simulation::isMainBusy(){ return mainBusy; }
bool Simulation::isFinishingBusy(){ return finishingBusy; }
void Simulation::setMainStatus(bool value){ mainBusy = value; }
void Simulation::setFinishingStatus(bool value){ finishingBusy = value; }


Simulation::Simulation()
:simulationTime(0),mainAssemblyTime(0),finishingAssemblyTime(0),mainBusy(false),
finishingBusy(false),eventList(new PriorityQueue),productQueue(new Queue),partQueues(new Queue*[3]){}// Simulation

// todo: main method for driving the simulation
void Simulation::runSimulation(char *fileName)
{

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

