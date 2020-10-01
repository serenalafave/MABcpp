/*
 * Serena LaFave
 * Multi-Armed Bandit in C++
 * BanditArm.cpp
 */

#include "BanditArm.h"

const double piVal = 3.14159265358979323846;

/**********************************************
  Students must define the following functions
 **********************************************/

BanditArm::BanditArm() {
    payoffMean = fabs(GetNormalRV());
    payoffStdDev = 1.0;
    count = 0;
    totalPayoff = 0.0;
    avgPayoff = 0.0;
}

/* Returns payoff from arm
 * Payoff is generated from a Gaussian distribution
 * with mean (payoffMean) and standard deviation
 * (payoffStdDev).
 * Updates count, avgPayoff, and totalPayoff of arm
 */
double BanditArm::Pull() {
  double receivedPayoff = payoffMean + (payoffStdDev * GetNormalRV());
  count++;
  totalPayoff += receivedPayoff;
  avgPayoff = totalPayoff / count;
	return receivedPayoff;
}

int BanditArm::GetCount() {
	return count;
}

double BanditArm::GetTotalPayoff() {
	return totalPayoff;
}

double BanditArm::GetAvgPayoff() {
	return avgPayoff;
}

double BanditArm::GetPayoffMean() {
	return payoffMean;
}

/*************************************************
 * The remaining functions are defined for students
 * Do not change them
 *************************************************/

double BanditArm::GetPayoffStdDev() {
	return payoffStdDev;
}

void BanditArm::SetPayoffMean(double p_payoffMean) {
   payoffMean = p_payoffMean;
}

void BanditArm::SetPayoffStdDev(double p_payoffStdDev) {
	payoffStdDev = p_payoffStdDev;
}

void BanditArm::SetCount(int p_count) {
	count = p_count;
}

void BanditArm::SetTotalPayoff(double p_totalPayoff) {
	totalPayoff = p_totalPayoff;
}

void BanditArm::SetAvgPayoff(double p_avgPayoff) {
	avgPayoff = p_avgPayoff;
}

/* Generates a Gaussian random variable with 0 mean and
 * unit standard deviation
 */
double BanditArm::GetNormalRV() {
	/* Get a uniform random variable */
	double randVar1 = GetUniformRV();
	double randVar2 = GetUniformRV();

	return sqrt(-2.0 * log(randVar1)) * cos(2.0 * piVal * randVar2);
}

/* Generates a uniform random value in the interval [0, 1] */
double BanditArm::GetUniformRV() {
	return (double) rand() / (double) RAND_MAX;
}
