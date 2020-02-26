// CLASS: Simulation.h
//
// Author: Patel Zil, 7876456
//
//-----------------------------------------

#pragma once
#include <fstream>
using namespace std;

class PriorityQueue; // Priority Queue
class Queue; // Queue class - provided to you
class Event; // Event - given to you.
class ListItem;
class Part;

class Simulation {
private:
    ifstream ifile; // input file to read.
    int simulationTime; // what is the current time of the simulation?
    PriorityQueue *eventList; // priority queue of Events.
    Queue* productQueue; // queue of partially assembled products (for finishing station).
    Queue** partQueues; // *array* of queues of parts for the stations. for P0,P1,P2
    int  mainAssemblyTime; //  how long does the main station take?
    int  finishingAssemblyTime; //  how long does the main station take?
	bool mainBusy; // is the main station busy?
	bool finishingBusy; // is the finishing station busy?
    int assembledParts;
    int totalProcessTime;
public:
    Simulation();

    // methods to manipulate the part and product queues
	Part *getPartialProduct();
	void addPartialProduct(ListItem *); // insert P3 in productQueue
	Queue* getPartQueues(int );
	void addPart(int ,Part *);
	void removePart(int);
	Queue *getProductQueue();

	void incrementProduct();
    void incrementProcessingTime(int time);

	// getters for the stations
	int getMainAssemblyTime();
	int getFinishingAssemblingTime();

	// getter and setter for simulation time
	int getSimulationTime();
	void setSimulationTime(int time);

	// main method for driving the simulation
	void runSimulation(char *fileName);

	// add an event to event queue.
	void addEvent (Event*); 

	// read next arrival from file and add it to the event queue. 
	void getNextArrival();
	
	// getters and setters for station statuses.
	bool isMainBusy();
	bool isFinishingBusy();
	void setMainStatus(bool);
	void setFinishingStatus(bool);

	void summary();
};// class Simulation
