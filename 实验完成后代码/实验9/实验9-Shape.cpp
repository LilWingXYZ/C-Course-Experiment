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
		cout << setiosflags(ios_base::left) << setw(12) << "������" << " ����" << length << "��" << setiosflags(ios_base::left) << setw(18)
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
		cout << setiosflags(ios_base::left) << setw(13) << "ֱ��������" << "��һ���ߣ�" << firstSide << "�ڶ����ߣ�"
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
		cout << setiosflags(ios_base::left) << setw(13) << "Բ" << "�뾶" << setiosflags(ios_base::left) << setw(26) << radius << setiosflags(ios_base::left) << setw(9) << setiosflags(ios_base::left) << setiosflags(ios_base::fixed) << setprecision(2) << this->getCircumference() << endl;
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
	cout << setiosflags(ios_base::left) << setw(5) << "���" << setiosflags(ios_base::left) << setw(15) << "�������"
		<< setiosflags(ios_base::left) << setw(28) << "����" << setiosflags(ios_base::left) << setw(15) << "�ܳ�" << endl;
	for (int i = 0; i<count; i++) {

		cout << setiosflags(ios_base::left) << setw(5) << i + 1;
		ZhouDaKuang[i]->print();
	}


}

void showMenu() {
	cout << "��ѡ������Ҫ�Ĳ�Ʒ��" << endl;
	cout << "*********************************" << endl;
	cout << "* 1.������                      *" << endl;
	cout << "* 2.ֱ��������                  *" << endl;
	cout << "* 3.Բ                          *" << endl;
	cout << "*-1.�˳�                        *" << endl;
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
				cout << "�����볤���εĳ��Ϳ�" << endl;
				double length;
				double width;
				cin >> length >> width;
				ZhouDaKuang[count] = new Rectangle(length, width);
				count++;
				break;
			}
			case 2: {
				cout << "������ֱ�������ε�����ֱ�Ǳߣ�" << endl;
				double firstSide;
				double secondSide;
				cin >> firstSide >> secondSide;
				ZhouDaKuang[count] = new RightTriangle(firstSide, secondSide);
				count++;
				break;
			}
			case 3: {
				cout << "������Բ�İ뾶��" << endl;
				double radius;
				cin >> radius;
				ZhouDaKuang[count] = new Circle(radius);
				count++;
				break;
			}
			default: {
				cout << "����������������������" << endl;
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
