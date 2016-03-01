#include <iostream>
#include "Simulation.h"

const int Simulation::CPU_QUANTUM = 4;
int Simulation::nextProcessID = 1;

int main(int argc, char *argv[]){
  if(argc < 2){
    cout << "Usage: " << argv[0] << " <file name>\n";
    exit(1);
  }
  cout << "Simulation begins...\n";
  Simulation* sim = new Simulation();
  sim->runSimulation(argv[1]);
  cout << "\n...All Processes complete.  Final Summary:\n\n";
  sim->summary();
  cout << "\nEnd of processing.\n";
  return 0;
}// main
