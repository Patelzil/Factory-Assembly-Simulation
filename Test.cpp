// CLASS: Test.cpp
//
// Author: Patel Zil, 7876456
//
// REMARKS:  Tests on data structure(priority queue)
//
//-----------------------------------------

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Part.h"
#include "PartArrival.h"
#include "PriorityQueue.h"
#include "Simulation.h"
#include "StartAssembly.h"
#include "ProductArrival.h"
#include "EndAssembly.h"

Part *testPart1 = new Part(0, 2);
Part *testPart2 = new Part(0, 3);
Part *testPart3 = new Part(1, 6);
Part *testPart4 = new Part(1, 7);
Part *testPart5 = new Part(2, 9);
Part *testPart6 = new Part(3, 10);
Simulation *sim = new Simulation();

TEST_CASE("Size of the priority queue.")
{
    PriorityQueue *testPriorityQueue = new PriorityQueue();
    PartArrival *firstPart = new PartArrival(2, sim, testPart1);
    PartArrival *secondPart = new PartArrival(5, sim, testPart2);
    PartArrival *thirdPart = new PartArrival(7, sim, testPart3);
    testPriorityQueue->insert(firstPart);
    REQUIRE(testPriorityQueue->getSize() == 1);

    SECTION("Size after inserting event to the priority queue.")
    {
        testPriorityQueue->insert(secondPart);
        testPriorityQueue->insert(thirdPart);
        REQUIRE(testPriorityQueue->getSize() == 3);
    }

    SECTION("Size after deleting event from the priority queue.")
    {
        testPriorityQueue->deleteHighest();
        REQUIRE(testPriorityQueue->getSize() == 0);
        testPriorityQueue->insert(secondPart);
        testPriorityQueue->insert(thirdPart);
        testPriorityQueue->deleteHighest();
        REQUIRE(testPriorityQueue->getSize() == 1);
    }
}

TEST_CASE("Checking for an empty priority queue.")
{
    PriorityQueue *testPriorityQueue = new PriorityQueue();
    PartArrival *firstPart = new PartArrival(2, sim, testPart1);

    REQUIRE(testPriorityQueue->isEmpty());
    REQUIRE(testPriorityQueue->getSize() == 0);

    SECTION("Is priority queue yet empty after inserting an event in it?")
    {
        testPriorityQueue->insert(firstPart);
        REQUIRE(!testPriorityQueue->isEmpty());
        REQUIRE(testPriorityQueue->getSize() == 1);
    }
}

TEST_CASE("Checking for the front of the priority queue.")
{
    PriorityQueue *testPriorityQueue = new PriorityQueue();
    PartArrival *firstPart = new PartArrival(2, sim, testPart1);
    PartArrival *secondPart = new PartArrival(5, sim, testPart2);
    PartArrival *thirdPart = new PartArrival(7, sim, testPart3);

    SECTION("Getting the front in an empty priority queue:")
    {
        REQUIRE(testPriorityQueue->getFront() == nullptr);
    }

    SECTION("After inserting into an empty priority queue:")
    {
        testPriorityQueue->insert(secondPart);
        REQUIRE(testPriorityQueue->getFront() == secondPart);
    }

    SECTION("After inserting some more events and then deleting them from priority queue:")
    {
        testPriorityQueue->insert(firstPart);
        testPriorityQueue->insert(secondPart);
        testPriorityQueue->insert(thirdPart);
        REQUIRE(testPriorityQueue->getFront() == firstPart);
        testPriorityQueue->deleteHighest();
        REQUIRE(testPriorityQueue->getFront() == secondPart);
        testPriorityQueue->deleteHighest();
        testPriorityQueue->deleteHighest();
        REQUIRE(testPriorityQueue->getFront() == nullptr);
    }
}

TEST_CASE("Deleting the highest priority from the priority queue.")
{
    PriorityQueue *testPriorityQueue = new PriorityQueue();
    PartArrival *firstPart = new PartArrival(2, sim, testPart1);
    PartArrival *secondPart = new PartArrival(5, sim, testPart2);
    PartArrival *thirdPart = new PartArrival(7, sim, testPart3);
    StartAssembly *firstStart = new StartAssembly(1,sim,testPart2,testPart4);

    SECTION("Remove event from an empty priority queue")
    {
        testPriorityQueue->deleteHighest();
        REQUIRE(testPriorityQueue->getSize() == 0); // size remains zero
        REQUIRE(testPriorityQueue->getFront() == nullptr);
    }

    testPriorityQueue->insert(firstPart);
    testPriorityQueue->insert(secondPart);
    testPriorityQueue->insert(thirdPart);
    REQUIRE(testPriorityQueue->getSize() == 3);

    SECTION("Remove the event with highest priority from the priority queue.")
    {
        testPriorityQueue->deleteHighest();
        REQUIRE(testPriorityQueue->getSize() == 2);
        REQUIRE(testPriorityQueue->getFront() == secondPart);
    }

    SECTION("Insert and remove another type of event from the priority queue.")
    {
        testPriorityQueue->insert(firstStart); // should be at the front of the priority queue
        REQUIRE(testPriorityQueue->getSize() == 4);
        REQUIRE(testPriorityQueue->getFront() == firstStart);
        testPriorityQueue->deleteHighest();
        REQUIRE(testPriorityQueue->getSize() == 3); // size reduces
        REQUIRE(testPriorityQueue->getFront() == firstPart); // the second on list came at the front of the list
    }
}

TEST_CASE("Ordered Insertion into a priority queue.")
{
    PriorityQueue *testPriorityQueue = new PriorityQueue();
    PartArrival *firstPart = new PartArrival(2, sim, testPart1);
    PartArrival *secondPart = new PartArrival(5, sim, testPart2);
    PartArrival *thirdPart = new PartArrival(7, sim, testPart3);
    PartArrival *fourthPart = new PartArrival(10, sim, testPart5);
    StartAssembly *firstStart = new StartAssembly(1,sim,testPart2,testPart4);

    GIVEN("An empty priority queue.")
    {
        REQUIRE(testPriorityQueue->getSize() == 0);
        REQUIRE(testPriorityQueue->getFront() == nullptr);

        WHEN("Inserting into an empty priority queue")
        {
            testPriorityQueue->insert(thirdPart);
            THEN("The size and the event at the front change.")
            {
                REQUIRE(testPriorityQueue->getSize() == 1);
                REQUIRE(testPriorityQueue->getFront() == thirdPart);
            }
        }

        WHEN("Inserting an event that goes at the front of the priority queue.")
        {
            testPriorityQueue->insert(thirdPart);
            testPriorityQueue->insert(fourthPart);

            REQUIRE(testPriorityQueue->getSize() == 2);
            REQUIRE(testPriorityQueue->getFront() == thirdPart);

            testPriorityQueue->insert(firstStart); // should be at the front of the priority queue

            THEN("The size and the event at the front of the priority queue changes.")
            {
                REQUIRE(testPriorityQueue->getSize() == 3);
                REQUIRE(testPriorityQueue->getFront() == firstStart);
            }
        }

        WHEN("Inserting an event that goes at the middle of the priority queue.")
        {
            testPriorityQueue->insert(firstPart);
            testPriorityQueue->insert(firstStart);
            testPriorityQueue->insert(thirdPart);
            testPriorityQueue->insert(fourthPart);

            REQUIRE(testPriorityQueue->getSize() == 4);
            REQUIRE(testPriorityQueue->getFront() == firstStart);

            testPriorityQueue->insert(secondPart); // should be at the front of the priority queue

            THEN("The size changes but the event at the front of the priority queue does not change.")
            {
                REQUIRE(testPriorityQueue->getSize() == 5);
                REQUIRE(testPriorityQueue->getFront() == firstStart);
            }
        }

        WHEN("Inserting an event that goes at the end of the priority queue")
        {
            testPriorityQueue->insert(secondPart);
            testPriorityQueue->insert(thirdPart);

            REQUIRE(testPriorityQueue->getSize() == 2);
            REQUIRE(testPriorityQueue->getFront() == secondPart);

            testPriorityQueue->insert(fourthPart); // goes at the end of the priority queue

            THEN("The size of the priority queue changes but the event at the front remains the same.")
            {
                REQUIRE(testPriorityQueue->getSize() == 3);
                REQUIRE(testPriorityQueue->getFront() == secondPart);
            }
        }

        WHEN("Inserting an event twice.")
        {
            testPriorityQueue->insert(firstPart);
            testPriorityQueue->insert(thirdPart);

            REQUIRE(testPriorityQueue->getSize() == 2);
            REQUIRE(testPriorityQueue->getFront() == firstPart);

            testPriorityQueue->insert(thirdPart); // inserting similar event

            THEN("The size increases by 1 and the front does not change.")
            {
                REQUIRE(testPriorityQueue->getSize() == 3);
                REQUIRE(testPriorityQueue->getFront() == firstPart);
            }
        }
    }
}

TEST_CASE("Testing for leaks in priority queue.")
{
    PriorityQueue *testPriorityQueue = new PriorityQueue();
    PartArrival *firstEvent = new PartArrival(2, sim, testPart1);
    ProductArrival *secondEvent = new ProductArrival(5, sim, testPart2);
    EndAssembly *thirdEvent = new EndAssembly(7, sim, testPart5,testPart6);
    StartAssembly *fourthEvent = new StartAssembly(1,sim,testPart2,testPart4);

    REQUIRE(testPriorityQueue->getSize() == 0);

    SECTION("Insert all types of events several times and then delete them.")
    {
        int number = 40;
        while (number >= 0)
        {
            testPriorityQueue->insert(firstEvent);
            testPriorityQueue->insert(secondEvent);
            testPriorityQueue->insert(thirdEvent);
            testPriorityQueue->insert(fourthEvent);
            number--;
        }

        REQUIRE(!testPriorityQueue->isEmpty());
        REQUIRE(testPriorityQueue->getFront() == fourthEvent);
        REQUIRE(testPriorityQueue->getSize() == 164);

        number = 164;
        while(number > 0)
        {
            testPriorityQueue->deleteHighest();
            number--;
        }

        REQUIRE(testPriorityQueue->isEmpty());
        REQUIRE(testPriorityQueue->getFront() == nullptr);
    }

}
