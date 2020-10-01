/*
 * Serena LaFave
 * Multi-Armed Bandit in C++
 * BanditArm.h
 */

#include <iostream>
#include <cmath>
#include <string>

#ifndef BANDIT_ARM_H_
#define BANDIT_ARM_H_

class BanditArm {
public:
   /************************************************************
     Students must define the following functions in Bandit.cpp
    ************************************************************/
   BanditArm();

   int GetCount();
   double GetTotalPayoff();
   double GetAvgPayoff();
   double GetPayoffMean();

   double Pull();

   /******************************************************************
    * The remaining functions are defined for students in BanditArm.cpp
    * Do not change them
    ******************************************************************/
   double GetPayoffStdDev();
   void SetPayoffMean(double p_payoffMean);
   void SetPayoffStdDev(double p_payoffStdDev);
   void SetCount(int p_count);
   void SetTotalPayoff(double p_totalPayoff);
   void SetAvgPayoff(double p_avgPayoff);

   double GetNormalRV();
   double GetUniformRV();

private:
   double payoffMean;     // Expected payoff
   double	payoffStdDev;   // Standard deviation of payoff
   int count;          // Number of times that this arm has been selected
   double totalPayoff;    // Total payoff obtained by selecting this arm
   double avgPayoff;      // Average payoff obtained by selecting this arm
};

#endif
