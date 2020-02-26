cmake_minimum_required(VERSION 3.15)
project(Event_Driven_Simulation)

set(CMAKE_CXX_STANDARD 11)

add_executable(Event_Driven_Simulation PriorityQueue.cpp A2main.cpp PriorityQueue.h Part.cpp Part.h Node.cpp Node.h Event.cpp Event.h ListItem.cpp ListItem.h Queue.cpp Queue.h Simulation.cpp PartArrival.cpp PartArrival.h StartAssembly.cpp StartAssembly.h EndAssembly.cpp EndAssembly.h ProductArrival.cpp ProductArrival.h OrderedItem.cpp)