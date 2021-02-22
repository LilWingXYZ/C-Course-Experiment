#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;

int sum=0;

class Park;

class Automobile{
public:
	void enter(Park &park,int N,Automobile &car);
	char* getplate(){
		return plate;
	}
private:
	char plate[10];
};

class Truck:public Automobile{
public:
	Truck(char plate1[10], int t){
		strcpy(getplate(),plate1);
		this->t = t;
	}
	void leave(Park &park,int N,Truck &car);
	int pay(){
		return 3;
	}
private:
	int t;
};

class Car:public Automobile{
public:
	Car(char plate1[10], string what){
		strcpy(getplate(),plate1);
		this->what = what;
	}
	void leave(Park &park,int N,Car &car);
	int pay(){
		return 1;
	}
private:
	string what;
};

class Bus:public Automobile{
public:
	Bus(char plate1[10], int number){
		strcpy(getplate(),plate1);
		this->number = number;
	}
	void leave(Park &park,int N,Bus &car);
	int pay(){
		return 2;
	}
private:
	int number;
};

class Park{
public:
	Park(int N);
	Automobile** getspaces(){
		return spaces;
	}
	~Park(){
		delete[] spaces;
	}
	int getincome(){
		return income;
	}
	void showInfo(int N);
private:
	int income;
	Automobile **spaces;
};

Park::Park(int N){
	spaces = new Automobile*[N];
	int i;
	for(i=0;i<N;i++){
		spaces[i]=NULL;
	}
	income=0;
}
void Park::showInfo(int N){
	int i;
	int n=0;
	for(i=0;i<N;i++){
		if(spaces[i]!=NULL)
			n++;
	}
	cout<<"停车场目前停放了"<<n<<"辆汽车:";
	for(i=0;i<N;i++){
		if(spaces[i]!=NULL)
			cout<<spaces[i]->getplate()<<" ";
	}
	cout<<"共收入";
	for(i=0;i<N;i++){
		if(spaces[i]!=NULL)
			income+=sum;
	}
	cout<<sum<<"元停车费 "<<endl;
}
void Automobile::enter(Park &park,int N,Automobile &car){
	int i;
	for(i=0;i<N;i++){
		if((park.getspaces())[i]==NULL){
			(park.getspaces())[i]=&car;
			cout<<car.getplate()<<"进入停车场，分配停车位"<<endl;
			break;
		}
	}
}

void Car::leave(Park &park,int N,Car &car){
	int i;
	for(i=0;i<N;i++){
		if((park.getspaces())[i]==&car){
			cout<<car.getplate()<<"离开停车场，缴纳停车费"<<car.pay()<<endl;
			sum+=car.pay();
			(park.getspaces())[i]=NULL;
			break;
		}
	}
}

void Truck::leave(Park &park,int N,Truck &car){
	int i;
	for(i=0;i<N;i++){
		if((park.getspaces())[i]==&car){
			cout<<car.getplate()<<"离开停车场，缴纳停车费"<<car.pay()<<endl;
			sum+=car.pay();
			(park.getspaces())[i]=NULL;
			break;
		}
	}
}

void Bus::leave(Park &park,int N,Bus &car){
	int i;
	for(i=0;i<N;i++){
		if((park.getspaces())[i]==&car){
			cout<<car.getplate()<<"离开停车场，缴纳停车费"<<car.pay()<<endl;
			sum+=car.pay();
			(park.getspaces())[i]=NULL;
			break;
		}
	}
}

int main(){
	int N;
	cout << "请输入停车位的数量：";
	cin >> N;

	Park park(N);

	Car car1("鲁B-12345","奥迪A6");
	car1.enter(park,N,car1);

	Truck truck("鲁B-23456",15);
	truck.enter(park,N,truck);

	car1.leave(park,N,car1);

	Bus bus("鲁B-34567",50);
	bus.enter(park,N,bus);

	park.showInfo(N);

	Car car2("鲁B-45678","宝马320");
	car2.enter(park,N,car2);

	bus.leave(park,N,bus);
	truck.leave(park,N,truck);

	park.showInfo(N);
}
