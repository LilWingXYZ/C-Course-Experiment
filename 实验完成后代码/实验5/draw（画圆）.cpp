#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

//表示平面上点的结构体
struct Point
{
	int x; //横坐标
	int y; //纵坐标
};
//显示主菜单
void displayMenu();

//得到用户输入的两个点
void getTwoPoints(struct Point*startP, struct Point*endP);

//以（x，y）的形式打印点
void printPoint(struct Point*);

//画圆的函数
void drawCircle(struct Point*startP, struct Point*endP);

//画方的函数
void drawRectangle(struct Point*startP, struct Point*endP);

//主函数
int main()
{
	int choice;//用户选择

	struct Point startP,endP;//起点和终点
	displayMenu();//显示主菜单
	cin>>choice;//得到用户输入
	while(choice)
	{
		switch(choice)
		{
			case 1://圆
				getTwoPoints(&startP, &endP);//得到两个点
				drawCircle(&startP, &endP);//画圆
				break;
			case 2://方
				getTwoPoints(&startP, &endP);//得到两个点
				drawRectangle(&startP, &endP);//画方
				break;
			case 0://退出程序
				cout<<"Good Bye!\n";
				break;
			default://输入不符合要求的数
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
	cout<<"1.Circle(圆)"<<endl;
	cout<<"2.Rectangle(长方形)"<<endl;
	cout<<"0.Exit(退出)"<<endl;
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
