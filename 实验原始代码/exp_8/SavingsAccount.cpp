#include <iostream>
#include "SavingsAccount.h"

using namespace std;

SavingsAccount::SavingsAccount(double balance, double interestRate) :
		Account(balance) {
	this->interestRate = interestRate;
}

double SavingsAccount::calculateInterest() {
	return getBalance() * interestRate / 100;
}
