#include <iostream>
#include <iomanip>
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

using namespace std;

int main() {
	Account* accounts[3];

	accounts[0] = new SavingsAccount(100, 3); // ��ʼ���Ϊ100Ԫ����ϢΪ3%
	accounts[1] = new CheckingAccount(100, 5); // ��ʼ���Ϊ100Ԫ��ÿ�ʽ��׷���Ϊ5Ԫ
	accounts[2] = new CheckingAccount(50, 5); // ��ʼ���Ϊ50Ԫ��ÿ�ʽ��׷���Ϊ5Ԫ

	for (int i = 0; i < 3; i++) {
		cout << "�� " << i + 1 << " ��ѭ���Ľ����" << endl;
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
		cout << "  �˻������Ϊ��" << accounts[i]->getBalance() << endl;
	}
	return 0;
}
