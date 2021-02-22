#include <iostream>
#include <string>

using namespace std;

class Automobile;

class Park {
public:
	Park(int N);
	~Park();
	void showInfo();
	bool assignSpace(Automobile *pa);
	bool reclaimSpace(Automobile *pa);

	int income;
private:
	Automobile **spaces;
	int N;
	int numAuto;
};

class Automobile {
public:
	Automobile(string plateNO);
	virtual ~Automobile();
	void enter(Park &park);
	void leave(Park &park);
	string getPlateNO();
	string plateNO;
protected:
	virtual void pay(Park &park) = 0;  // 向停车场支付停车费，由派生类实现
};

Park::Park(int N) {
	spaces = new Automobile*[N];
	for (int i = 0; i < N; i++)
		spaces[i] = NULL;
	income = 0;
	this->N = N;
	numAuto = 0;
}

Park::~Park() {
	delete[] spaces;
}

void Park::showInfo() {
	if (numAuto == 0)
		cout << "停车场目前停放了" << numAuto << "辆汽车，共收入" << income << "元停车费";
	else {
		cout << "停车场目前停放了" << numAuto << "辆汽车：";
		for (int i = 0; i < N; i++)
			if (spaces[i] != NULL)
				cout << spaces[i]->getPlateNO() << ",";

		cout << "共收入" << income << "元停车费" << endl;
	}
}

bool Park::assignSpace(Automobile *pa) {
	for (int i = 0; i < N; i++) {
		if (spaces[i] == NULL) {
			spaces[i] = pa;
			numAuto++;
			cout << pa->getPlateNO() << "进入停车场，分配停车位" << endl;
			return true;
		}
	}
	cout << "无法为" << pa->getPlateNO() << "分配停车位" << endl;
	return false;
}

bool Park::reclaimSpace(Automobile *pa) {
	for (int i = 0; i < N; i++) {
		if (spaces[i] == pa) {
			spaces[i] = NULL;
			numAuto--;
			cout << pa->getPlateNO() << "离开停车场，";
			return true;
		}
	}
	cout << "停车场中没有车牌为" << pa->getPlateNO() << "的汽车";
	return false;
}


Automobile::Automobile(string plateNO) :
		plateNO(plateNO) {
}

Automobile::~Automobile() { }

void Automobile::enter(Park &park) {
	park.assignSpace(this);
}

void Automobile::leave(Park &park) {
	park.reclaimSpace(this);
	pay(park);
}

string Automobile::getPlateNO() {
	return plateNO;
}

class Truck: public Automobile {
public:
	Truck(string plateNO, double capacity) :
			Automobile(plateNO), capacity(capacity) {
	}
protected:
	double capacity;
private:
	void pay(Park &park);
};

void Truck::pay(Park &park) {
	park.income += 3;
	cout << "缴纳停车费3元" << endl;

}

class Car: public Automobile {
public:
	Car(string plateNO, string brand) :
			Automobile(plateNO), brand(brand) {
	}
protected:
	string brand;
private:
	void pay(Park &park);
};

void Car::pay(Park &park) {
	park.income += 1;
	cout << "缴纳停车费1元" << endl;

}

class Bus: public Automobile {
public:
	Bus(string plateNO, int numPassengers) :
			Automobile(plateNO), numPassengers(numPassengers) {
	}
protected:
	int numPassengers;
private:
	void pay(Park &park);
};

void Bus::pay(Park &park) {
	park.income += 2;
	cout << "缴纳停车费2元" << endl;

}


int main() {
	int N = 0;
	cout << "请输入停车位数量：";
	cin >> N; // 输入停b车位数量，此处输入2

	Park park(N); // 创建一个停车场对象

	Car car1("鲁B-12345", "奥迪A6"); // 创建轿车对象
	car1.enter(park); // car1进入停车场，分配停车位

	Truck truck("鲁B-23456", 15); // 创建卡车对象
	truck.enter(park); // truck进入停车场，分配车位

	car1.leave(park); // car1离开停车场，缴纳停车费

	Bus bus("鲁B-34567", 50); // 创建公交车对象
	bus.enter(park); // bus进入停车场，分配车位

	/* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
	park.showInfo();

	Car car2("鲁B-45678", "宝马320"); // 创建轿车对象
	car2.enter(park);
	// car2进入停车场，分配停车位。因为没有空余停车位，所以无法分配

	bus.leave(park); // bus离开停车场，缴纳停车费
	truck.leave(park); // truck离开停车场，缴纳停车费

	/* 显示当前停放的车辆的车牌号码，以及当前的全部停车费收入*/
	park.showInfo();

	return 0;
}
