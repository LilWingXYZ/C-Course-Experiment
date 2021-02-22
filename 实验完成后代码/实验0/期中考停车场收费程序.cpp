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
			cout<<"ͣ��"<<time<<"Сʱ��"<<"�ѷ���ͣ��λ"<<endl;
			income+=2*time;
		}
		else  cout<<"ͣ����������û��ͣ��λ"<<endl;
}

void Park::showInfo(){
	int number=0;
	for(int i=0;i<2;i++)
		if(spaces[i]==true)number++;
	cout<<"ͣ����Ŀǰͣ����"<<number<<"������������"<<income<<"Ԫͣ����"<<endl;
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
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


