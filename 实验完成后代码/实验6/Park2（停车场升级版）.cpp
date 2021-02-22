#include<iostream>
#include<string>
using namespace std;

class Automobile{
public:
	void setPlate(string plate){ this->plate = plate; }
	string getPlate(){ return plate; }
	void setN(int n){ this->n = n; }
	int getN(){ return n - 1; }
private:
	int n;
	string plate;
};

class Park{
public:
	Park(int N) {
		spaces = new Automobile*[N];
		this->N = N;
		number = 0;
		for (int i = 0; i < N; i++){
			spaces[i] = NULL;
		}
	}
	Automobile *&getSpaces(int n){ return spaces[n]; }
	int setSpaces(Automobile *automobile);
	int getIncome() { return income; }
	void setIncome(int income){ this->income = income; }
	int getNumber() { return number; }
	void setNumber(int number){ this->number = number; }
	void enter(Automobile *automobile);
	void showInfo(){
		cout << "停车场目前停放了" << number << "辆汽车：";
		for (int i = 0; i < number; i++)
			cout << spaces[i]->getPlate()<< "，";
		cout << "共收入" << income << "元停车费" << endl;
	}
private:
	int N;
	int number;
	int income=0;
	Automobile **spaces;
};

class Car : public Automobile{
public:
	Car(string plate, string name) : name(name){ setPlate(plate); }
	string getName(){ return name; }
	void pay(Park park);
	void leave(Park &park){
		park.getSpaces(getN()) = NULL;
		pay(park);
		park.setNumber(park.getNumber() - 1);
		park.setIncome(park.getIncome() + 1);
	}
private:
	string name;
};

class Truck : public Automobile{
public:
	Truck(string plate, double weight) : weight(weight){ setPlate(plate); }
	double getWeight(){ return weight; }
	void pay(Park park);
	void leave(Park &park){
		park.getSpaces(getN()) = NULL;
		pay(park);
		park.setNumber(park.getNumber() - 1);
		park.setIncome(park.getIncome() + 2);
	}
private:
	double weight;
};

class Bus : public Automobile{
public:
	Bus(string plate, int passengers) : passengers(passengers){ setPlate(plate); }
	int getPassengers(){ return passengers; }
	void pay(Park park);
	void leave(Park &park){
		park.getSpaces(getN()) = NULL;
		pay(park);
		park.setNumber(park.getNumber() - 1);
		park.setIncome(park.getIncome() + 3);
	}
private:
	int passengers;
};

int Park::setSpaces(Automobile *automobile){
	for (int i = 0; i < N; i++){
		if (spaces[i] == NULL){
			number++;
			spaces[i] = automobile;
			return i + 1;
		}
	}
	return 0;
}

void Park::enter(Automobile *automobile){
	int n;
	if (n = setSpaces(automobile)) cout << automobile->getPlate() << "进入停车场，分配停车位" << endl;
	else cout << "无法为" << automobile->getPlate() << "分配停车位" << endl;
	automobile->setN(n);
}

void Car::pay(Park park){
	int income = 0;
	income = park.getIncome();
	income += 1;
	park.setIncome(income);
	cout << getPlate() << "离开停车场，缴纳停车费1元 " << endl;
}

void Truck::pay(Park park){
	int income = 0;
	income = park.getIncome();
	income += 2;
	park.setIncome(income);
	cout << getPlate() << "离开停车场，缴纳停车费2元 " << endl;
}

void Bus::pay(Park park){
	int income = 0;
	income = park.getIncome();
	income += 3;
	park.setIncome(income);
	cout << getPlate() << "离开停车场，缴纳停车费3元 " << endl;
}

int main(){
	int N;

	cout << "请输入停车位数量：";
	cin >> N;

	Park park(N);

	Car car1("鲁B-12345", "奥迪A6");
	park.enter(&car1);

	Truck truck("鲁B-23456", 15);
	park.enter(&truck);

	car1.leave(park);

	Bus bus("鲁B-34567", 50);
	park.enter(&bus);

	park.showInfo();

	Car car2("鲁B-45678", "宝马320");
	park.enter(&car2);

	bus.leave(park);
	truck.leave(park);

	park.showInfo();

	system("pause");
	return 0;
}
//1、构造函数不能派生
//2、只能在构造函数中使用初始化列表
//3、传递引用
//4、this的用法？
