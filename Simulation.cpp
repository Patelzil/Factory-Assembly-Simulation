#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Simulation.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "Event.h"
#include "PartArrival.h"
#include "ListItem.h"
#include "Part.h"

using namespace std;

PriorityQueue *Simulation::getEventList() {return eventList; }
Queue *Simulation::getProductQueue() { return productQueue; }
Part *Simulation::getPartialProduct() { return dynamic_cast<Part *>(productQueue->getFront()); }
int Simulation::getMainAssemblyTime() { return mainAssemblyTime; }
int Simulation::getFinishingAssemblingTime() { return finishingAssemblyTime; }
Queue* Simulation::getPartQueues(int num) { return partQueues[num]; }
int Simulation::getSimulationTime() { return simulationTime; }
void Simulation::setSimulationTime(int time) { simulationTime = time; }
bool Simulation::isMainBusy(){ return mainBusy; }
bool Simulation::isFinishingBusy(){ return finishingBusy; }
void Simulation::setMainStatus(bool value){ mainBusy = value; }
void Simulation::setFinishingStatus(bool value){ finishingBusy = value; }

Simulation::Simulation()
{
    mainBusy = false;
    finishingBusy = false;
    partQueues = new Queue*[3];
    partQueues[0] = new Queue();
    partQueues[1] = new Queue();
    partQueues[2] = new Queue();
    productQueue = new Queue();
    eventList = new PriorityQueue();
}// Simulation

// todo: main method for driving the simulation
void Simulation::runSimulation(char *fileName)
{
    ifile.open(fileName);

    Event *theItem; // to store the event with highest priority
    eventList = new PriorityQueue;
    productQueue = new Queue;
    string line;

    getline(ifile, line);
    stringstream iss(line);
    cout << "This line is:" << line << endl;
    iss << line;
    iss >> mainAssemblyTime >> finishingAssemblyTime;

    // read the first arrival event from the data file and put it in the event list
    // this event has to be an arrival!
    getNextArrival();

    while (!eventList->isEmpty())
    {
        theItem = dynamic_cast<Event *>(eventList->deleteHighest());
        setSimulationTime(theItem->getTime());
        theItem->processEvent();
    }

    ifile.close(); // close the file after reading it

}// runSimulation

void Simulation::addPartialProduct(ListItem *newItem)
{
    productQueue->enqueue(newItem);
}// addPartialEvent

void Simulation::addPart(int num,Part *newPart)
{
    partQueues[num]->enqueue(newPart);
}// addPart

void Simulation::removePart(int num)
{
    if(num == 3 )
    {
        productQueue->dequeue();
    }
    else
    {
        partQueues[num]->dequeue();
    }
}// removePart

// add an event to event queue.
void Simulation::addEvent (Event *newEvent)
{
    eventList->insert(newEvent);
}// addEvent

void Simulation::getNextArrival()
{
    string line;
    int time;
    int partNum;
    if(!ifile.eof())
    {
        getline(ifile, line);
        stringstream iss;
        iss << line;
        iss >> time >> partNum;
        Part *newPart = new Part(partNum, time);
        PartArrival *newArrival = new PartArrival(time, this, newPart);
        addEvent(newArrival);
    }
}

