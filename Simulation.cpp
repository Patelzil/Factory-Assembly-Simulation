#include "Simulation.h"

int Simulation::getSimulationTime() { return simulationTime; }
void Simulation::setSimulationTime(int time) { simulationTime = time; }
bool Simulation::isMainBusy(){ return mainBusy; }
bool Simulation::isFinishingBusy(){ return finishingBusy; }
void Simulation::setMainStatus(bool value){ mainBusy = value; }
void Simulation::setFinishingStatus(bool value){ finishingBusy = value; }

//todo: Finish constructor
Simulation::Simulation()
{

}// Simulation

// todo: main method for driving the simulation
void Simulation::runSimulation(char *fileName)
{

}// runSimulation

// todo: add an event to event queue.
void Simulation::addEvent (Event*)
{

}// addEvent


// todo: read next arrival from file and add it to the event queue.
void Simulation::getNextArrival()
{

}

