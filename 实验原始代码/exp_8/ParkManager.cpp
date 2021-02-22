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
	virtual void pay(Park &park) = 0;  // ��ͣ����֧��ͣ���ѣ���������ʵ��
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
		cout << "ͣ����Ŀǰͣ����" << numAuto << "��������������" << income << "Ԫͣ����";
	else {
		cout << "ͣ����Ŀǰͣ����" << numAuto << "��������";
		for (int i = 0; i < N; i++)
			if (spaces[i] != NULL)
				cout << spaces[i]->getPlateNO() << ",";

		cout << "������" << income << "Ԫͣ����" << endl;
	}
}

bool Park::assignSpace(Automobile *pa) {
	for (int i = 0; i < N; i++) {
		if (spaces[i] == NULL) {
			spaces[i] = pa;
			numAuto++;
			cout << pa->getPlateNO() << "����ͣ����������ͣ��λ" << endl;
			return true;
		}
	}
	cout << "�޷�Ϊ" << pa->getPlateNO() << "����ͣ��λ" << endl;
	return false;
}

bool Park::reclaimSpace(Automobile *pa) {
	for (int i = 0; i < N; i++) {
		if (spaces[i] == pa) {
			spaces[i] = NULL;
			numAuto--;
			cout << pa->getPlateNO() << "�뿪ͣ������";
			return true;
		}
	}
	cout << "ͣ������û�г���Ϊ" << pa->getPlateNO() << "������";
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
	cout << "����ͣ����3Ԫ" << endl;

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
	cout << "����ͣ����1Ԫ" << endl;

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
	cout << "����ͣ����2Ԫ" << endl;

}


int main() {
	int N = 0;
	cout << "������ͣ��λ������";
	cin >> N; // ����ͣb��λ�������˴�����2

	Park park(N); // ����һ��ͣ��������

	Car car1("³B-12345", "�µ�A6"); // �����γ�����
	car1.enter(park); // car1����ͣ����������ͣ��λ

	Truck truck("³B-23456", 15); // ������������
	truck.enter(park); // truck����ͣ���������䳵λ

	car1.leave(park); // car1�뿪ͣ����������ͣ����

	Bus bus("³B-34567", 50); // ��������������
	bus.enter(park); // bus����ͣ���������䳵λ

	/* ��ʾ��ǰͣ�ŵĳ����ĳ��ƺ��룬�Լ���ǰ��ȫ��ͣ��������*/
	park.showInfo();

	Car car2("³B-45678", "����320"); // �����γ�����
	car2.enter(park);
	// car2����ͣ����������ͣ��λ����Ϊû�п���ͣ��λ�������޷�����

	bus.leave(park); // bus�뿪ͣ����������ͣ����
	truck.leave(park); // truck�뿪ͣ����������ͣ����

	/* ��ʾ��ǰͣ�ŵĳ����ĳ��ƺ��룬�Լ���ǰ��ȫ��ͣ��������*/
	park.showInfo();

	return 0;
}
