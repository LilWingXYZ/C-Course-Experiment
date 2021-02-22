#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

void changeClass(int n,int now,int next,char c[]){
	char temp;
	temp=c[now];
	c[now]=c[next];
	c[next]=temp;
}

void sortClass(char p[][100],int n){
	int i;
	int j;
	int k;
	char temp [100];

	for(i=0;i<n-1;i++){
		k=i;
		for(j=i+1;j<n;j++)
			if(strcmp(p[j],p[k])<0)k=j;
		if(k!=i){
			strcpy(temp,p[i]);
			strcpy(p[i],p[k]);
			strcpy(p[k],temp);
		}
	}

	for(i=0;i<n;i++)
		cout<<p[i]<<endl;
}

void operateClass(int n,char Class[]){
	int i;
	int k;
	int countB=0;
	int countW=0;
	int count=0;
	char copy[100][100];

	for(i=0;i<(n/2+1);i++)
		if(Class[i]=='B')countB++;
	for(i=0;i<(n/2+1);i++)
		if(Class[i]=='W')countW++;
	if((countB==n/2&&countW==0)||(countB==0&&countW==n/2)||(Class[n/2]=='B'&&countW==n/2)||(Class[n/2]=='W'&&countB==n/2))
		cout<<"Target Structure£¡"<<endl;
	else{
		for(i=0;i<n;i++)
			if(Class[i]=='E')break;
		for(k=-3;k<=3;k++){
			if(k==0)continue;
			else if(-1<i+k&&i+k<n){
				changeClass(n,i,i+k,Class);
				strcpy(copy[count],Class);
				changeClass(n,i+k,i,Class);
				count++;
			}
		}
		sortClass(copy,count);
	}
}
int main(){
	int N;
	int i;

	while(cin>>N){
	char *Class=new char[N];
	for(i=0;i<2*N+1;i++)
		cin>>Class[i];
	operateClass(2*N+1,Class);
	}

	system("pause");
	return 0; 
}
