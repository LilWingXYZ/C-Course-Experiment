#include <iostream>
#include "Account.h"

using namespace std;

Account::Account(double balance) {
	setBalance(balance);
}

Account::~Account() { }

void Account::setBalance(double balance) {
	if (balance >= 0)
		this->balance = balance;
	else {
		balance = 0;
		cout << "  非法的余额，设为0" << endl;
	}
}

double Account::getBalance() const {
	return balance;
}

bool Account::credit(double amount) {
	balance += amount;
	return true;
}

bool Account::debit(double amount) {
	if (balance < amount) {
		cout << "  Debit amount exceeded account balance" << endl;
		return false;
	} else {
		balance -= amount;
		return true;
	}
}
