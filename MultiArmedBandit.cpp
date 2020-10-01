/*
 * Serena LaFave
 * Multi-Armed Bandit in C++
 * MultiArmedBandit.cpp
 */

#include "MultiArmedBandit.h"

/**********************************************
  Students must define the following functions
***********************************************/

MultiArmedBandit::MultiArmedBandit() {
  numArms = 5;
  numSteps = 25;
  epsilon = 0.2;
  armVect.resize(numArms);
  selectionVect.resize(numSteps);
  payoffVect.resize(numSteps);
}


MultiArmedBandit::MultiArmedBandit(int p_numArms, int p_numSteps, double p_epsilon) {
  numArms = p_numArms;
  numSteps = p_numSteps;
  epsilon = p_epsilon;
  armVect.resize(numArms);
  selectionVect.resize(numSteps);
  payoffVect.resize(numSteps);
}


/* Runs a simulation with:
      numSteps time steps
      numArms arms
      epsilon for exploration
*/



/* Selects arm based on epsilon greedy action selection method.*/
int MultiArmedBandit::SelectArm() {
  double maxAvgPayoff = armVect[0].GetAvgPayoff();
  double val = (double)rand() / (double)RAND_MAX;
  int armIndex = 0;
	if (val < epsilon) {
		return rand() % numArms;
	}
	else {
    for (int i = 0; i < numArms; i++) {
      if (armVect[i].GetAvgPayoff() > maxAvgPayoff) {
        armIndex = i;
        maxAvgPayoff = armVect.at(i).GetAvgPayoff();
      }
    }
	}
  return armIndex;
}

void MultiArmedBandit::Run() {
  int sArm;
  double payoff;
  cout.precision(2);

  cout << endl;
  cout << "***** Simulation Begins *****" << endl;
  for (int i = 0; i < numSteps; i++) {
    sArm = SelectArm();
    selectionVect.at(i) = sArm;
    payoff = armVect.at(sArm).Pull();
    payoffVect.at(i) = payoff;
    cout << "t: " << i << "\tArm: " << sArm << "\tPayoff: " << fixed << payoff << endl;
  }
  cout << "***** Simulation Ends *****" << endl << endl;
}

/* Prints the simulation statistics.
 * Statistics include:
 *      Total Payoff
 *      No. of times each arm is selected
 *      Average payoff (estimated value) of each arm
 *      Expected payoff (value) of each arm
 */
void MultiArmedBandit::PrintStatistics() {
  double totPayoff = 0.0;
  cout.precision(2);

  for (int i = 0; i < numArms; i++) {
    totPayoff += armVect.at(i).GetTotalPayoff();
  }

  cout << "Total Payoff: " << setprecision(2) << totPayoff << endl;

  cout << "Arm   Count   Avg. Payoff   Value" << endl;
  
  for (int i = 0; i < numArms; i++) {
    cout << setw(3) << i << setw(8) << armVect.at(i).GetCount() << setw(14) << fixed << armVect.at(i).GetAvgPayoff() << setw(8) << fixed << armVect.at(i).GetPayoffMean() << endl;
  }
}

/* Prints simulation record to a CSV file */
void MultiArmedBandit::WriteToFile(string p_filename) {
  double runPayoffSum = 0;
  double runAvg = 0;

  ofstream simFile;
  simFile.open (p_filename);
  simFile << "Step, Arm, Payoff, Running Avg." << endl;

  for(int i = 0; i < numSteps; i++) {
    runPayoffSum += payoffVect.at(i);
    runAvg = runPayoffSum / (i + 1);
    simFile << setw(4) << i << "," << setw(4) << selectionVect.at(i) << "," << setw(7) << setprecision(2) << fixed << payoffVect.at(i) << "," << setw(13) << setprecision(2) << fixed << runAvg << endl;
  }
  simFile.close();
}


/***************************************************************
 * The below functions are used to test student code in zyBooks
 * Their definitions are provided
 * Do not change them
****************************************************************/
vector<int> MultiArmedBandit::TestSelectArm(int p_seed) {
   vector<int> tmp(numSteps);

   // Seed the random number generator
   srand(p_seed);

   // Initialize member variables of each BanditArm randomly
   for (int i = 0; i < numArms; i++) {
      armVect.at(i).SetPayoffMean(rand() % 10);
      armVect.at(i).SetPayoffStdDev(rand() % 10);
    	armVect.at(i).SetCount(rand() % 100);
    	armVect.at(i).SetTotalPayoff(rand() % 1000);
    	armVect.at(i).SetAvgPayoff(armVect.at(i).GetTotalPayoff() / armVect.at(i).GetCount());
  	}

   for (int t = 0; t < numSteps; t++) {
	   // Select arm according to Epsilon-Greedy exploration policy
      tmp.at(t) = SelectArm();
   }

   return tmp;
}


int MultiArmedBandit::GetNumArms() {
   return numArms;
}


int MultiArmedBandit::GetNumSteps() {
   return numSteps;
}


double MultiArmedBandit::GetEpsilon() {
   return epsilon;
}


unsigned int MultiArmedBandit::GetSelectionVectSize() {
   return selectionVect.size();
}


unsigned int MultiArmedBandit::GetPayoffVectSize() {
   return payoffVect.size();
}


unsigned int MultiArmedBandit::GetArmVectSize() {
   return armVect.size();
}
