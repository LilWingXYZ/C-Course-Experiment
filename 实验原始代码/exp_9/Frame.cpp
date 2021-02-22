#include <iostream>
#include <string>
#include <cmath>
#include "Array.h"

using namespace std;

class Shape {
public:
	virtual double getCircumference() = 0;
	virtual void showInfo() = 0;

	virtual ~Shape() { }
	bool operator >(Shape & shape);

};

bool Shape::operator >(Shape & shape) {
	return (getCircumference() > shape.getCircumference());
}


class Circle: public Shape {
public:
	Circle(double radius) :
			radius(radius) {
	}

	static Shape * createCircle() {
		cout << "������Բ�εİ뾶��";
		double radius;
		cin >> radius;
		return new Circle(radius);
	}

	double getCircumference() {
		return 2 * radius * PI;
	}

	void showInfo() {
		cout << "Բ�Σ��뾶" << radius << "���ܳ�" << getCircumference() << endl;
	}

private:
	double radius;
	static const double PI = 3.1415926;
};

class Rectangle: public Shape {
public:
	Rectangle(double length, double width) :
			length(length), width(width) {
	}

	static Shape * createRectangle() {
		cout << "�����볤���εĳ��Ϳ�";
		double length, width;
		cin >> length >> width;
		return new Rectangle(length, width);
	}

	double getCircumference() {
		return 2 * (length + width);
	}

	void showInfo() {
		cout << "�����Σ���" << length << "����" << width << "���ܳ�" << getCircumference() << endl;
	}

private:
	double length;
	double width;
};

class RightTriangle: public Shape {
public:
	RightTriangle(double edge1, double edge2) :
		edge1(edge1), edge2(edge2) {
	}

	static Shape * createRightTriangle() {
		cout << "������ֱ�������ε������߳���";
		double edge1, edge2;
		cin >> edge1 >> edge2;
		return new RightTriangle(edge1, edge2);
	}

	double getCircumference() {
		return edge1 + edge2 + sqrt(edge1 * edge1 + edge2 * edge2);
	}

	void showInfo() {
		cout << "ֱ�������Σ�ֱ�Ǳ�" << edge1 << "��ֱ�Ǳ�" << edge2 << "���ܳ�" << getCircumference() << endl;
	}

private:
	double edge1;
	double edge2;
};

void insertSort(Array<Shape *> &shapes, int index, Shape * ptr) {// ���´�������״ptr���뵽��̬����shapes��
	int size = shapes.getSize();
	int boundary = 0;

	for (; boundary < index; boundary++) {
		if (*shapes[boundary] > *ptr)
			break;
	}

	for (int i = size - 1; i > boundary; i--)
		shapes[i] = shapes[i-1];
	shapes[boundary] = ptr;
}

int main () {
	cout << "������ͼ���ı�ţ������µĿ�ܣ�����-1�������" << endl
			<< "  1  Բ��" << endl
			<< "  2  ������" << endl
			<< "  3  ֱ��������" << endl;

	int preSize = 2;// ��̬����ĳ�ʼ��С
	Array<Shape *> shapes(preSize);
	for (int i = 0; i < preSize; i++)	// Ҫ��shapes�е�ָ��Ԫ�س�ʼ��ΪNULL�������п����ǡ�Ұָ�롱
		shapes[i] = NULL;

	int index = 0;
	int option = 0;
	cin >> option;

	while (option != -1) {
		Shape *ptr = NULL;
		switch(option) {
		case 1:
			ptr = Circle::createCircle();
			break;
		case 2:
			ptr = Rectangle::createRectangle();
			break;
		case 3:
			ptr = RightTriangle::createRightTriangle();
			break;
		default:
			cout << "�����ѡ�����������" << endl;
			break;
		}

		insertSort(shapes, index, ptr);// ִ�в�������
		index++;

		if (index >= preSize) {// ������̬����Ĵ�С
			preSize *= 2;
			shapes.resize(preSize);
		}

		cin >> option;// �����µ�����ѡ��
	}

	for (int i = 0; i < index; i++)
			shapes[i]->showInfo();

	return 0;
}
