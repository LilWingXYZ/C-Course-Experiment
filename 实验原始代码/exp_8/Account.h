#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
	Account(double balance);
	void setBalance(double balance);
	double getBalance() const;
	virtual bool debit(double amount);
	virtual bool credit(double amount);

	virtual ~Account();
private:
	double balance;
};
#endif
