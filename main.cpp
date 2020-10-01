/*
 * Serena LaFave
 * Multi-Armed Bandit in C++
 * main.cpp
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "MultiArmedBandit.h"

using namespace std;

/*****************************
  Students must define main()
 *****************************/

int main() {
  string fileName = "stats.csv";
  int user_numArms;
  int user_numSteps;
  double user_epsilon;
  int seed;

  MultiArmedBandit* mabPtr = NULL;

  cout << "Enter the number of arms:" << endl;
  cin >> user_numArms;

  cout << "Enter the number of simulation time steps:" << endl;
  cin >> user_numSteps;

  cout << "Enter the value of epsilon in [0,1]:" << endl;
  cin >> user_epsilon;

  cout << "Enter random seed:" << endl;
  cin >> seed;\

  srand(seed);
  mabPtr = new MultiArmedBandit(user_numArms, user_numSteps, user_epsilon);

  mabPtr->Run();
  mabPtr->PrintStatistics();
  mabPtr->WriteToFile(fileName);

  delete mabPtr;
  return 0;
}
