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

PriorityQueue *Simulation::getEventList() { return eventList; }
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
void Simulation::incrementParts() { assembledParts += 2;}

Simulation::Simulation()
{
    simulationTime = 0;
    mainAssemblyTime = 0;
    finishingAssemblyTime = 0;
    mainBusy = false;
    finishingBusy = false;
    assembledParts = 0;
    // initialize part queues
    partQueues = new Queue*[3];
    partQueues[0] = new Queue();
    partQueues[1] = new Queue();
    partQueues[2] = new Queue();
    productQueue = new Queue();
    eventList = new PriorityQueue();
}// Simulation

void Simulation::runSimulation(char *fileName)
{
    ifile.open("C:\\Users\\Lenovo\\CLionProjects\\Event_Driven_Simulation\\A2data.txt");

    eventList = new PriorityQueue;
    productQueue = new Queue;
    string line;
    if(ifile.is_open())
    {
        getline(ifile, line);
        stringstream iss;
        iss << line;
        iss >> mainAssemblyTime >> finishingAssemblyTime;

        // read the first arrival event from the data file and put it in the event list
        // this event has to be an arrival!
        getNextArrival();

        while (!eventList->isEmpty())
        {
            Event *theItem = dynamic_cast<Event *>(eventList->deleteHighest());
            setSimulationTime(theItem->getTime());
            theItem->processEvent();
        }
        ifile.close(); // close the file after reading it
    }
    else
    {
        cout << "Sorry. Not able to access your input file." << endl;
    }

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
    int time, partNum;
    if(ifile >> time >> partNum)
    {
        Part *newPart = new Part(partNum, time);
        PartArrival *newArrival = new PartArrival(time, this, newPart);
        addEvent(newArrival);
    }
}

void Simulation::summary()
{
    cout << "Total number of assembled parts: " << assembledParts << endl;
    cout << "Average time to build a product: " << endl;
    cout <<"\n"
           "\t              Number of\n"
           "\t  Queue       parts left\n"
           "\t-------------------------\n"
           "\t    P0           " << partQueues[0]->getSize() << "\n"
           "\t    P1           " << partQueues[1]->getSize() << "\n"
           "\t    P2           " << partQueues[2]->getSize() << "\n"
           "\tP3(Partial)      " << productQueue->getSize() << endl;
}// summary