#include<iostream>
using namespace std;

int changeSliding_block(char structure[]) {
	
}

int threeSliding_block(int n) {
	int i;
	int countW=0;
	int countB=0;
	int countE=0;
	char structure[7];
	for(i=0;i<7;i++) {
		cin>>structure[i];
	}
	for(i=0;i<4;i++) {
		if(structure[i]=='W')countW++;
		if(structure[i]=='E')countE++;
		if(structure[i]=='B')countB++;
	}
	if(countW==3&&countE==1) {
		cout<<"Target Structure!"<<endl;
		return 1;
	}
	countW=0;
	countB=0;
	countE=0;
	for(i=0;i<3;i++) {
		if(structure[i]=='W')countW++;
		if(structure[i]=='E')countE++;
		if(structure[i]=='B')countB++;
	}
	if(countW==3) {
		cout<<"Target Structure!"<<endl;
		return 1;
	}
	else changeSliding_block(structure);
	return 1;
} 

int fourSliding_block(int n) {
	int i;
	int countW=0;
	int countB=0;
	int countE=0;
	char structure[9];
	for(i=0;i<9;i++) {
		cin>>structure[i];
	}
	for(i=0;i<5;i++) {
		if(structure[i]=='W')countW++;
		if(structure[i]=='E')countE++;
		if(structure[i]=='B')countB++;
	}
	if(countW==4&&countE==1) {
		cout<<"Target Structure!"<<endl;
		return 1;
	}
	countW=0;
	countB=0;
	countE=0;
	for(i=0;i<4;i++) {
		if(structure[i]=='W')countW++;
		if(structure[i]=='E')countE++;
		if(structure[i]=='B')countB++;
	}
	if(countW==4) {
		cout<<"Target Structure!"<<endl;
	    return 1;
	}
	else changeSliding_block(structure);
	return 1;
}



int main() {
	int number;
	while(1) {
		cin>>number;
		if(number==3) threeSliding_block(3);
		else if(number==4) fourSliding_block(4);
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


