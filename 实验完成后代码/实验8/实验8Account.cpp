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
	double balance;//账户余额
};

class SavingsAccount:public Account{
public:
	SavingsAccount(double Newbalance,double NewinterestRate);
	double calculateInterest();//返回balance*interestRate
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
	accounts[0] = new SavingsAccount(100, 0.03);   //余额100元，利息3% 
	accounts[1] = new CheckingAccount(100, 5);  //余额100元，交易费5元 
	accounts[2] = new CheckingAccount(50, 5);   //余额50元，交易费5元  
	for (int i = 0; i < 3; i++) { 
		cout << "第" << i + 1 << "次循环的结果：" << endl; 
		accounts[i]->debit(200);   //借款200元 
		accounts[i]->debit(40); 
		accounts[i]->credit(50);   //存款50元 
		accounts[i]->debit(49); 
		accounts[i]->debit(43); 
		accounts[i]->credit(1); 
		//将Account指针强制转换为SavingAccount指针 
		SavingsAccount *derivedPtr = dynamic_cast<SavingsAccount *>(accounts[i]); if(derivedPtr != NULL)   //如果类型兼容，转换成功 
		derivedPtr->credit(derivedPtr->calculateInterest());
		cout << fixed << setprecision(2);   //使用定点数格式，2位小数部分 
		cout << "账户的余额为：" << accounts[i]->getBalance() << endl; 
		
	} 
} 