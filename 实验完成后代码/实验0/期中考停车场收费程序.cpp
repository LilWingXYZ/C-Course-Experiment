#include<iostream>
#include<cstdlib>
using namespace std;

class Automobile{
public:
	Automobile(int plate,int passengers):plate(plate),passengers(passengers){}
private:
	int plate;
	int passengers;
};

class Park{
public:

	Park(int income=0):income(income){
		for(int i=0;i<2;i++)
			spaces[i]=false;
	}

	void assignSpace(Automobile&carName,int time);
	void showInfo();
private:
	bool spaces[2];
	int income;

};

void Park::assignSpace(Automobile&carName,int time){
		int i;
		for(i=0;i<2;i++)
			if(spaces[i]==false)break;
		if(i<2){
			spaces[i]=true;
			cout<<"停车"<<time<<"小时，"<<"已分配停车位"<<endl;
			income+=2*time;
		}
		else  cout<<"停车场已满，没有停车位"<<endl;
}

void Park::showInfo(){
	int number=0;
	for(int i=0;i<2;i++)
		if(spaces[i]==true)number++;
	cout<<"停车场目前停放了"<<number<<"辆汽车，收了"<<income<<"元停车费"<<endl;
}

int main(){

	Park park;

	Automobile car(12345,5);
	park.assignSpace(car,3);

	Automobile truck(23456,3);
	park.assignSpace(truck,5);

	Automobile bus(34567,40);
	park.assignSpace(bus,2);

	park.showInfo();
	
	return 0;
}
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


