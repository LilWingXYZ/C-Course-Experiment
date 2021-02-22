#include <iostream>
#include <iomanip>
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

using namespace std;

int main() {
	Account* accounts[3];

	accounts[0] = new SavingsAccount(100, 3); // 初始余额为100元，利息为3%
	accounts[1] = new CheckingAccount(100, 5); // 初始余额为100元，每笔交易费用为5元
	accounts[2] = new CheckingAccount(50, 5); // 初始余额为50元，每笔交易费用为5元

	for (int i = 0; i < 3; i++) {
		cout << "第 " << i + 1 << " 次循环的结果：" << endl;
		accounts[i]->debit(200);
		accounts[i]->debit(40);
		accounts[i]->credit(50);
		accounts[i]->debit(49);
		accounts[i]->debit(43);
		accounts[i]->credit(1);

		SavingsAccount* derivedPtr = dynamic_cast<SavingsAccount*>(accounts[i]);

		if (derivedPtr != 0)
			derivedPtr->credit(derivedPtr->calculateInterest());

		cout << fixed << setprecision(2);
		cout << "  账户的余额为：" << accounts[i]->getBalance() << endl;
	}
	return 0;
}
