#include<iostream>
using namespace std;

void inputTemps(int temp[] , int n) {
	int i;
	cout<<"Please input the tenperatures: "<<endl;
	for(i=0;i<n;i++) {
		cout<<temp[i]<<" ";
	}
	cout<<endl;
	/*for(i=0;i<n;i++) {
		cin>>temp[i];
	}*/
}

void displayTemps(int temp[] , int n) {
	int i;
	int j;
	cout<<endl<<"This temperature_Histogram is:"<<endl;
	for(i=0;i<n;i++) {
		cout<<i+1;
		if (i<9)
			cout<<"     ";
		else
			cout<<"    ";
		
		for(j=0;j<temp[i];j++) {
			cout<<"*";
		}
		cout<<endl;
	}
}

void displayPeaks(int temp[] , int n) {
	int i;
	cout<<endl<<"The Peak_value as follows: "<<endl;
	for(i=0 ; i<n-2 ; i++) {

		if(temp[i]<temp[i+1]&&temp[i+1]>temp[i+2]) {
			cout<<"Max at day "<<i+2<<" is "<<temp[i+1]<<endl;
		}
	} 
}

void displayFlat(int temp[] , int n) {
	int i;
	int number=1;
	int max=1;
	for(i=0;i<n-1;i++) {
		if(temp[i]==temp[i+1]) {
			number++;
		}
		else number=1;
		if(number>max) {
			max=number;
		}	
	}
	cout<<endl<<"The length of longest flat is "<<max<<endl;
}

int main() {
	const int Days=15;
	int temps[Days]={11,12,13,11,11,11,11,10,9,13,13,11,16,14,15};
	inputTemps(temps , Days);
	displayTemps(temps , Days);
	displayPeaks(temps , Days);
	displayFlat(temps , Days);
	return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


