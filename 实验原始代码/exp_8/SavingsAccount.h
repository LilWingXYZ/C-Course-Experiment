#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount: public Account {
public:
	SavingsAccount(double balance, double interestRate);
	double calculateInterest();
private:
	double interestRate;
};
#endif
