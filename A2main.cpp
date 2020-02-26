//-----------------------------------------
// NAME		: Patel Zil
// STUDENT NUMBER	: 7876456
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike Domaratzki
// ASSIGNMENT	: assignment 2
// QUESTION	: question 1
//
// REMARKS: Simulating an assembly line that assembles
//          three parts to construct a finished product
//
//-----------------------------------------

#include "Simulation.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
  if(argc < 2){
    cout << "Usage: " << argv[0] << " SpecificationFile InputFile \n";
    exit(1);
  }
  cout << "Simulation begins...\n";
  Simulation* sim = new Simulation();
  // run simulation 
  cout << "starting simulation." << endl;
  sim->runSimulation(argv[1]);
  cout << "\n...All Assembly complete.  Final Summary:\n\n";

  sim->summary();

  cout << "\nEnd of processing.\n";
  return 0;
}// main
