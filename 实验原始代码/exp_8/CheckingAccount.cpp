#include <iostream>
#include "CheckingAccount.h"

using namespace std;

CheckingAccount::CheckingAccount(double balance, double transFee) : Account(balance) {
	this->transFee = transFee;
}

bool CheckingAccount::credit(double amount) {
	Account::credit(amount);
	if (getBalance() < transFee) {
		cout << "  Transaction fee exceeded account balance while crediting" << endl;
		Account::debit(amount);
		return false;
	} else
		return Account::debit(transFee);
}

bool CheckingAccount::debit(double amount) {
	if (Account::debit(amount)) {
		if (getBalance() < transFee) {
			cout << "  Transaction fee exceeded account balance while debiting" << endl;
			Account::credit(amount);
			return false;
		} else
			return Account::debit(transFee);
	}

	return false;
}
