#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;

class Account{
public:
	Account(double Newbalance);
	void virtual credit(double money);
	void virtual debit(double money);
	double getBalance();
private:
	double balance;//�˻����
};

class SavingsAccount:public Account{
public:
	SavingsAccount(double Newbalance,double NewinterestRate);
	double calculateInterest();//����balance*interestRate
private:
	double interestRate;
};

class CheckingAccount:public Account{
public:
	CheckingAccount(double NewBalance,double Neweveryfee);
	void credit(double money);
	void debit(double money);
private:
	double everyfee;
};

Account::Account(double Newbalance){
	balance = Newbalance;
}

void Account::credit(double money){
	balance+=money;
}

void Account::debit(double money){
	if(balance>=money)
		balance-=money;
	else
		cout<<"Debit amount exceeded account balance"<<endl;
}

double Account::getBalance(){
	return balance;
}

SavingsAccount::SavingsAccount(double Newbalance,double NewinterestRate):Account(Newbalance){
	interestRate = NewinterestRate;
}

double SavingsAccount::calculateInterest(){
	double money=getBalance();
	return(this->interestRate*money);
}

CheckingAccount::CheckingAccount(double NewBalance,double Neweveryfee):Account(NewBalance){
	everyfee = Neweveryfee;
}

void CheckingAccount::credit(double money){
	Account::credit(money);
	if(getBalance()<everyfee){
		cout<<"Transaction fee exceeded account balance while crediting"<<endl;
		Account::debit(money);
	}
	else
		Account::debit(everyfee);
}

void CheckingAccount::debit(double money){
	if(money<=getBalance()){
		Account::debit(money);
		if(getBalance()<everyfee){
			cout<<"Transaction fee exceeded account balance while debiting"<<endl;
				Account::credit(money);
		}
		else
			Account::debit(everyfee);
	}
	else
		cout<<"Debit amount exceeded account balance"<<endl;
}

int main() { 
	Account *accounts[3]; 
	accounts[0] = new SavingsAccount(100, 0.03);   //���100Ԫ����Ϣ3% 
	accounts[1] = new CheckingAccount(100, 5);  //���100Ԫ�����׷�5Ԫ 
	accounts[2] = new CheckingAccount(50, 5);   //���50Ԫ�����׷�5Ԫ  
	for (int i = 0; i < 3; i++) { 
		cout << "��" << i + 1 << "��ѭ���Ľ����" << endl; 
		accounts[i]->debit(200);   //���200Ԫ 
		accounts[i]->debit(40); 
		accounts[i]->credit(50);   //���50Ԫ 
		accounts[i]->debit(49); 
		accounts[i]->debit(43); 
		accounts[i]->credit(1); 
		//��Accountָ��ǿ��ת��ΪSavingAccountָ�� 
		SavingsAccount *derivedPtr = dynamic_cast<SavingsAccount *>(accounts[i]); if(derivedPtr != NULL)   //������ͼ��ݣ�ת���ɹ� 
		derivedPtr->credit(derivedPtr->calculateInterest());
		cout << fixed << setprecision(2);   //ʹ�ö�������ʽ��2λС������ 
		cout << "�˻������Ϊ��" << accounts[i]->getBalance() << endl; 
		
	} 
} 