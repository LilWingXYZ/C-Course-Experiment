#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

//��ʾƽ���ϵ�Ľṹ��
struct Point
{
	int x; //������
	int y; //������
};
//��ʾ���˵�
void displayMenu();

//�õ��û������������
void getTwoPoints(struct Point*startP, struct Point*endP);

//�ԣ�x��y������ʽ��ӡ��
void printPoint(struct Point*);

//��Բ�ĺ���
void drawCircle(struct Point*startP, struct Point*endP);

//�����ĺ���
void drawRectangle(struct Point*startP, struct Point*endP);

//������
int main()
{
	int choice;//�û�ѡ��

	struct Point startP,endP;//�����յ�
	displayMenu();//��ʾ���˵�
	cin>>choice;//�õ��û�����
	while(choice)
	{
		switch(choice)
		{
			case 1://Բ
				getTwoPoints(&startP, &endP);//�õ�������
				drawCircle(&startP, &endP);//��Բ
				break;
			case 2://��
				getTwoPoints(&startP, &endP);//�õ�������
				drawRectangle(&startP, &endP);//����
				break;
			case 0://�˳�����
				cout<<"Good Bye!\n";
				break;
			default://���벻����Ҫ�����
				cout<<"Not supported! Please select again!\n";
				break;
		}
		displayMenu();
		cin>>choice;
	}
}

void displayMenu()
{
	cout<<"***************************"<<endl;
	cout<<"1.Circle(Բ)"<<endl;
	cout<<"2.Rectangle(������)"<<endl;
	cout<<"0.Exit(�˳�)"<<endl;
	cout<<"***************************"<<endl;
	cout<<"Please select the shape:";
}

void getTwoPoints(struct Point*startP, struct Point*endP)
{
	cout<<"Please input the coordinate (x,y) of the start point:";
	cin>>startP->x>>startP->y;
	cout<<"Please input the coordinate (x,y) of the end point:";
	cin>>endP->x>>endP->y;
}

void drawCircle(struct Point*startP, struct Point*endP)
{
	if(abs((startP->x-endP->x))==abs((startP->y-endP->y)))
		cout<<"Draw a circle at center ("<<(startP->x+endP->x)/2<<","<<(startP->y+endP->y)/2<<") with radius "<<abs((startP->x-endP->x))/2<<endl;
	else
		cout<<"Not a circle, Select again"<<endl;
}

void drawRectangle(struct Point*startP, struct Point*endP)
{
	cout<<"Draw a rectangle at topleft ("<<startP->x<<", "<<startP->y<<"), whose width is "<<endP->x-startP->x<<" and the height is "<<endP->y-startP->y<<endl;
}
