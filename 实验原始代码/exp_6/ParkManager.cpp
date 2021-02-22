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
	bool reclaimSpace(Automobile *pa, int fee);
private:
	Automobile **spaces;
	int income;
	int N;
	int numAuto;
};

class Automobile {
public:
	Automobile(string plateNO);
	void enter(Park &park);
	void leave(Park &park);
	string getPlateNO();

protected:
	string plateNO;
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

bool Park::reclaimSpace(Automobile *pa, int fee) {
	for (int i = 0; i < N; i++) {
		if (spaces[i] == pa) {
			spaces[i] = NULL;
			numAuto--;
			income += fee;
			cout << pa->getPlateNO() << "�뿪ͣ����������ͣ����" << fee << "Ԫ" << endl;
			return true;
		}
	}
	cout << "ͣ������û�г���Ϊ" << pa->getPlateNO() << "������";
	return false;
}

Automobile::Automobile(string plateNO) :
		plateNO(plateNO) {
}

void Automobile::enter(Park &park) {
	park.assignSpace(this);
}

void Automobile::leave(Park &park) {

}

string Automobile::getPlateNO() {
	return plateNO;
}

class Truck: public Automobile {
public:
	Truck(string plateNO, double capacity) :
			Automobile(plateNO), capacity(capacity) {
	}
	void leave(Park &park);
protected:
	double capacity;
};

void Truck::leave(Park &park) {
	park.reclaimSpace(this, 3);
}

class Car: public Automobile {
public:
	Car(string plateNO, string brand) :
			Automobile(plateNO), brand(brand) {
	}
	void leave(Park &park);
protected:
	string brand;
};

void Car::leave(Park &park) {
	park.reclaimSpace(this, 1);
}

class Bus: public Automobile {
public:
	Bus(string plateNO, int numPassengers) :
			Automobile(plateNO), numPassengers(numPassengers) {
	}
	void leave(Park &park);
protected:
	int numPassengers;
};

void Bus::leave(Park &park) {
	park.reclaimSpace(this, 2);
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
