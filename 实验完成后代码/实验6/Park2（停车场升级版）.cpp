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
		cout << "ͣ����Ŀǰͣ����" << number << "��������";
		for (int i = 0; i < number; i++)
			cout << spaces[i]->getPlate()<< "��";
		cout << "������" << income << "Ԫͣ����" << endl;
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
	if (n = setSpaces(automobile)) cout << automobile->getPlate() << "����ͣ����������ͣ��λ" << endl;
	else cout << "�޷�Ϊ" << automobile->getPlate() << "����ͣ��λ" << endl;
	automobile->setN(n);
}

void Car::pay(Park park){
	int income = 0;
	income = park.getIncome();
	income += 1;
	park.setIncome(income);
	cout << getPlate() << "�뿪ͣ����������ͣ����1Ԫ " << endl;
}

void Truck::pay(Park park){
	int income = 0;
	income = park.getIncome();
	income += 2;
	park.setIncome(income);
	cout << getPlate() << "�뿪ͣ����������ͣ����2Ԫ " << endl;
}

void Bus::pay(Park park){
	int income = 0;
	income = park.getIncome();
	income += 3;
	park.setIncome(income);
	cout << getPlate() << "�뿪ͣ����������ͣ����3Ԫ " << endl;
}

int main(){
	int N;

	cout << "������ͣ��λ������";
	cin >> N;

	Park park(N);

	Car car1("³B-12345", "�µ�A6");
	park.enter(&car1);

	Truck truck("³B-23456", 15);
	park.enter(&truck);

	car1.leave(park);

	Bus bus("³B-34567", 50);
	park.enter(&bus);

	park.showInfo();

	Car car2("³B-45678", "����320");
	park.enter(&car2);

	bus.leave(park);
	truck.leave(park);

	park.showInfo();

	system("pause");
	return 0;
}
//1�����캯����������
//2��ֻ���ڹ��캯����ʹ�ó�ʼ���б�
//3����������
//4��this���÷���
