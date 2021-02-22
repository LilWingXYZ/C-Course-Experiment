#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H

#include "Account.h"

class CheckingAccount: public Account {
public:
	CheckingAccount(double balance, double transFee);
	virtual bool credit(double amount);
	virtual bool debit(double amount);
private:
	double transFee; // 每笔交易的费用
};
#endif
