#include<iostream>
using namespace std;

int main() {
	int row,column,digital_root,square[20][20]={0},number;
	for(row=0;row<10;row++) {
		square[0][row]=row;
		square[row][0]=row;
	}
	for(row=1;row<10;row++) {
		for(column=1;column<10;column++) {
			digital_root=row*column;
			while(digital_root>9) {
				digital_root=digital_root/10+digital_root%10;
			}
			square[row][column]=digital_root;
		}
	}
	for(row=0;row<10;row++) {
		for(column=0;column<10;column++) {
				cout<<square[row][column];
		}
		cout<<'\n';
	}
	cout<<"\nPlease enter a number: ";
	cin>>number;
	while(number>=0) {
		for(row=1;row<10;row++) {
			for(column=1;column<10;column++) {
				if(number==square[row][column])
					cout<<'*';
				else
					cout<<' ';
			}
			cout<<'\n';
		}
		cout<<"\nPlease enter a number: ";
		cin>>number;
	}
	return 0;
} 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


