// CLASS: Simulation.cpp
//
// Author: Patel Zil, 7876456
//
// REMARKS: Performs PartArrival Event.
//          reads the file line by line as it performs the correct event.
//
//-----------------------------------------

#include <string>
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
void Simulation::incrementProduct(){ assembledParts++;}
void Simulation::incrementProcessingTime(int time) { totalProcessTime += time; }

Simulation::Simulation()
{
    // initialize private variables
    simulationTime = 0;
    mainAssemblyTime = 0;
    finishingAssemblyTime = 0;
    mainBusy = false;
    finishingBusy = false;
    assembledParts = 0;
    totalProcessTime = 0;

    // initialize part and product queues
    partQueues = new Queue*[3];
    partQueues[0] = new Queue();
    partQueues[1] = new Queue();
    partQueues[2] = new Queue();
    productQueue = new Queue();

    eventList = new PriorityQueue();
}// Simulation

/* runSimulation(char *)
 *
 * opens and reads the file as it processes events
 * from the eventList until no events are left to be processed.
 *
 */
void Simulation::runSimulation(char *fileName)
{
    ifile.open("C:\\Users\\Lenovo\\CLionProjects\\Event_Driven_Simulation\\data.txt");

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
        exit(EXIT_FAILURE);
    }

}// runSimulation

/* addPartialProduct(ListItem*)
 *
 * adds partial product P3 passed as parameter to the queue at the finishing station
 */
void Simulation::addPartialProduct(ListItem *newItem)
{
    productQueue->enqueue(newItem);
}// addPartialEvent

/* addPart(int, Part *)
 *
 * PURPOSE: adds parts P0,P1,P2 to its respective queue
 *
 * PARAMETER: part number and the part is passed.
 *          part number is used in conjunction with the queue number
 *          eg P0 is added to partQueues[0], P1 is added to partQueues[1]
 *
 */
void Simulation::addPart(int num,Part *newPart)
{
    partQueues[num]->enqueue(newPart);
}// addPart

/* removePart(int)
 *
 * PURPOSE:removes part that has been processed from its respective queue
 *
 * PARAMETER: passed part number:
 *          if partNum == 3 then dequeue from product queue
 *          else if it is 0,1 0r 2 the dequeue from partQueue[part number]
 *
 */
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

/* addEvent(Event *)
 *
 * PURPOSE: add an event passed as a parameter to event queue
 *
 */
void Simulation::addEvent (Event *newEvent)
{
    eventList->insert(newEvent);
}// addEvent

/* getNextArrival()
 *
 * reads the next line from the file.
 * Creates a part and then schedules a PartArrival Event
 *
 */
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

// prints the summary for the whole simulation
void Simulation::summary()
{
    if(assembledParts > 0)
    {
        int averageTime = totalProcessTime / assembledParts;
        cout << "Total number of assembled parts: " << assembledParts << endl;
        cout << "Average time to build a product: " << averageTime << endl;
        cout << "\n"
                "\t              Number of\n"
                "\t  Queue       parts left\n"
                "\t-------------------------\n"
                "\t    P0           " << partQueues[0]->getSize() << "\n"
                "\t    P1           " << partQueues[1]->getSize() << "\n"
                "\t    P2           " << partQueues[2]->getSize() << "\n"
                "\tPartial(P3)      " << productQueue->getSize() << endl;
    }
}// summary