/*
 * Serena LaFave
 * Multi-Armed Bandit in C++
 * MultiArmedBandit.h
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "BanditArm.h"

using namespace std;

#ifndef MULTI_ARMED_BANDIT_H_
#define MULTI_ARMED_BANDIT_H_


class MultiArmedBandit {
public:
   /**********************************************************************
     Students must define the following functions in MultiArmedBandit.cpp
    **********************************************************************/
   MultiArmedBandit();
   MultiArmedBandit(int p_numArms, int p_numSteps, double p_epsilon);

   void Run();
   int SelectArm();
   void PrintStatistics();
   void WriteToFile(string p_filename);

   /***************************************************************
    * The below functions are used to test student code in zyBooks
    * Their definitions are provided in MultiArmedBandit.cpp
    * Do not change them
   ****************************************************************/
   vector<int> TestSelectArm(int p_seed);

   int GetNumArms();
   int GetNumSteps();
   double GetEpsilon();
   unsigned int GetSelectionVectSize();
   unsigned int GetPayoffVectSize();
   unsigned int GetArmVectSize();

private:
   int numArms;
   int numSteps;
   double epsilon;
   vector<int> selectionVect;
   vector<double> payoffVect;
   vector<BanditArm> armVect;
};

#endif
