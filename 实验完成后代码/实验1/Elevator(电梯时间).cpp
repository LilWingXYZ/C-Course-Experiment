#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int second,count,floor_number[10],result;
	cout<<"Please enter the number of times: ";
	cin>>floor_number[0];
	while(floor_number[0]>0) {
		cout<<"Please enter the order of floors:";
		for(count=1;count<=floor_number[0];count++) {
			cin>>floor_number[count];
		}
		result=floor_number[1]*6+5;
			for(count=1;count<floor_number[0];count++) {;
				if(floor_number[count]>floor_number[count+1]) second=4;
				else second=6;
				result+=abs(floor_number[count+1]-floor_number[count])*second+5;
			}
		cout<<result<<endl;
		cout<<"Please enter the number of times: ";
		cin>>floor_number[0];
	}
	
	
	return 0;
} 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


