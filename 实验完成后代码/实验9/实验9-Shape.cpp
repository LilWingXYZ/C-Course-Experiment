#include <iostream>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include"Array.h"
using namespace std;
const double PI = 3.1415926;

class Shape
{
public:
	virtual double getCircumference() = 0;
	virtual void print() = 0;

};

class Rectangle :public Shape
{
public:
	double getCircumference() {
		return (length + width) * 2;
	}
	Rectangle(double length, double width) :length(length), width(width) {}
	void print() {
		cout << setiosflags(ios_base::left) << setw(12) << "长方形" << " 长：" << length << "宽：" << setiosflags(ios_base::left) << setw(18)
			<< width << setiosflags(ios_base::left) << setw(15) << setiosflags(ios_base::left) << setiosflags(ios_base::fixed) << setprecision(2) << this->getCircumference() << endl;
	}

private:
	double length;
	double width;

};

class RightTriangle :public Shape
{
public:

	double getCircumference() {
		return (sqrt(firstSide*firstSide + secondSide*secondSide) + firstSide + secondSide);
	}
	RightTriangle(double firstSide, double secondSide) :firstSide(firstSide), secondSide(secondSide) {}
	void print() {
		cout << setiosflags(ios_base::left) << setw(13) << "直角三角形" << "第一条边：" << firstSide << "第二条边："
			<< setiosflags(ios_base::left) << setw(6) << secondSide << setiosflags(ios_base::left) << setiosflags(ios_base::fixed)
			<< setprecision(2) << this->getCircumference() << endl;
	}


private:
	double firstSide;
	double secondSide;

};

class Circle :public Shape
{
public:
	double getCircumference() {
		return (PI*radius*2);
	}
	Circle(double radius) :radius(radius) {}
	void print() {
		cout << setiosflags(ios_base::left) << setw(13) << "圆" << "半径" << setiosflags(ios_base::left) << setw(26) << radius << setiosflags(ios_base::left) << setw(9) << setiosflags(ios_base::left) << setiosflags(ios_base::fixed) << setprecision(2) << this->getCircumference() << endl;
	}

private:
	double radius;

};
bool operator>(Shape& First, Shape& Last) {
	return((First.getCircumference()>Last.getCircumference()) ? true : false);
}


void insertSort(Shape* ZhouDaKuang[], int count) {
	if (count < 1) {
		return;
	}
	else {
		for (int i = 1; i != count; i++) {
			int j = i - 1;
			Shape* temp = ZhouDaKuang[i];
			while (j >= 0 && *temp>*ZhouDaKuang[j]) {
				ZhouDaKuang[j + 1] = ZhouDaKuang[j];
				j--;
			}
			ZhouDaKuang[j + 1] = temp;
		}
	}
	cout << setiosflags(ios_base::left) << setw(5) << "序号" << setiosflags(ios_base::left) << setw(15) << "框架名称"
		<< setiosflags(ios_base::left) << setw(28) << "参数" << setiosflags(ios_base::left) << setw(15) << "周长" << endl;
	for (int i = 0; i<count; i++) {

		cout << setiosflags(ios_base::left) << setw(5) << i + 1;
		ZhouDaKuang[i]->print();
	}


}

void showMenu() {
	cout << "请选择您需要的产品：" << endl;
	cout << "*********************************" << endl;
	cout << "* 1.长方形                      *" << endl;
	cout << "* 2.直角三角形                  *" << endl;
	cout << "* 3.圆                          *" << endl;
	cout << "*-1.退出                        *" << endl;
	cout << "*********************************" << endl;

}

void receiveChoice() {
	Array<Shape*>ZhouDaKuang(10);
	int choice;
	int count = 0;
	while (1)
	{
		showMenu();
		cin >> choice;
		try {
			switch (choice)
			{
			case -1: {throw choice; break; }
			case 1: {
				cout << "请输入长方形的长和宽：" << endl;
				double length;
				double width;
				cin >> length >> width;
				ZhouDaKuang[count] = new Rectangle(length, width);
				count++;
				break;
			}
			case 2: {
				cout << "请输入直角三角形的两条直角边：" << endl;
				double firstSide;
				double secondSide;
				cin >> firstSide >> secondSide;
				ZhouDaKuang[count] = new RightTriangle(firstSide, secondSide);
				count++;
				break;
			}
			case 3: {
				cout << "请输入圆的半径：" << endl;
				double radius;
				cin >> radius;
				ZhouDaKuang[count] = new Circle(radius);
				count++;
				break;
			}
			default: {
				cout << "您的输入有误，请重新输入" << endl;
				break;
			}
			}
		}
		catch (int eof) {
			insertSort(ZhouDaKuang, count);
			return;
		}
		if (count == ZhouDaKuang.getSize())
			ZhouDaKuang.resize(count * 2);
	}
}

int main() {
	receiveChoice();
	//system("pause");
}
