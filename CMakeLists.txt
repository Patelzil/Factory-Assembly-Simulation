cmake_minimum_required(VERSION 3.15)
project(Event_Driven_Simulation)

set(CMAKE_CXX_STANDARD 11)

add_executable(Event_Driven_Simulation A2main.cpp PriorityQueue.cpp PriorityQueue.h Part.cpp Part.h Node.cpp Node.h Event.cpp Event.h ListItem.cpp ListItem.h Queue.cpp Queue.h )