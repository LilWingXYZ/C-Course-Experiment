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
		cout << "请输入圆形的半径：";
		double radius;
		cin >> radius;
		return new Circle(radius);
	}

	double getCircumference() {
		return 2 * radius * PI;
	}

	void showInfo() {
		cout << "圆形，半径" << radius << "，周长" << getCircumference() << endl;
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
		cout << "请输入长方形的长和宽：";
		double length, width;
		cin >> length >> width;
		return new Rectangle(length, width);
	}

	double getCircumference() {
		return 2 * (length + width);
	}

	void showInfo() {
		cout << "长方形，长" << length << "，宽" << width << "，周长" << getCircumference() << endl;
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
		cout << "请输入直角三角形的两条边长：";
		double edge1, edge2;
		cin >> edge1 >> edge2;
		return new RightTriangle(edge1, edge2);
	}

	double getCircumference() {
		return edge1 + edge2 + sqrt(edge1 * edge1 + edge2 * edge2);
	}

	void showInfo() {
		cout << "直角三角形，直角边" << edge1 << "，直角边" << edge2 << "，周长" << getCircumference() << endl;
	}

private:
	double edge1;
	double edge2;
};

void insertSort(Array<Shape *> &shapes, int index, Shape * ptr) {// 将新创建的形状ptr插入到动态数组shapes中
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
	cout << "输入框架图案的编号，创建新的框架，键入-1输入结束" << endl
			<< "  1  圆形" << endl
			<< "  2  长方形" << endl
			<< "  3  直角三角形" << endl;

	int preSize = 2;// 动态数组的初始大小
	Array<Shape *> shapes(preSize);
	for (int i = 0; i < preSize; i++)	// 要将shapes中的指针元素初始化为NULL，否则有可能是“野指针”
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
			cout << "错误的选项，请重新输入" << endl;
			break;
		}

		insertSort(shapes, index, ptr);// 执行插入排序
		index++;

		if (index >= preSize) {// 调整动态数组的大小
			preSize *= 2;
			shapes.resize(preSize);
		}

		cin >> option;// 接收新的输入选项
	}

	for (int i = 0; i < index; i++)
			shapes[i]->showInfo();

	return 0;
}
