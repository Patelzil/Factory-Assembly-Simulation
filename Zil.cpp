#include "Simulation.h"
#include "PriorityQueue.h"
#include "PartArrival.h"
#include "Part.h"
#include <iostream>
using namespace std;

int main()
{
    Simulation *sim = new Simulation();

    PriorityQueue *list = new PriorityQueue();
    PartArrival *one = new PartArrival(2, sim, new Part(0,2));
    PartArrival *two = new PartArrival(4, sim, new Part(0,4));
    PartArrival *three = new PartArrival(6, sim, new Part(1,6));
    PartArrival *four = new PartArrival(8, sim, new Part(2,8));
    PartArrival *five = new PartArrival(9, sim, new Part(1,9));
//    sim->addEvent(one);
//    sim->addEvent(two);
//    sim->addEvent(three);
//    sim->addEvent(four);
//    sim->addEvent(five);
//    Event *theItem;
//
//    while(!sim->getEventList()->isEmpty())
//    {
//        theItem = dynamic_cast<Event *>(sim->getEventList()->deleteHighest());
//        sim->setSimulationTime(theItem->getTime());
//        theItem->processEvent();
//    }


    list->insert(two);
    list->insert(five);
    list->insert(four);
    list->insert(three);
    list->insert(one);

    cout << "Highest: " << dynamic_cast<Event *>(list->deleteHighest())->getTime() << endl;
    cout << "next: " << dynamic_cast<Event *>(list->deleteHighest())->getTime() << endl;
    cout << "next: " << dynamic_cast<Event *>(list->deleteHighest())->getTime() << endl;
    cout << "next: " << dynamic_cast<Event *>(list->deleteHighest())->getTime() << endl;
    cout << "next: " << dynamic_cast<Event *>(list->deleteHighest())->getTime() << endl;

    return 0;
}