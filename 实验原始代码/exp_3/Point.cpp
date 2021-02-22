#include <iostream>
using namespace std;

class Point {
public:
	/* 默认构造函数，默认值为左上角坐标(0, 0) */
	Point(int x = 0, int y = 0) :
			x(x), y(y) {
	}
	void setX(int x) {
		this->x = x;
	}
	int getX() {
		return x;
	}
	void setY(int y) {
		this->y = y;
	}
	int getY() {
		return y;
	}
	void print() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
	void moveRight(int offset) {
		x += offset;
	}
	void moveDown(int offset) {
		y += offset;
	}
private:
	int x;
	int y;
};

int main() {
	int x, y;
	cout << "Please input a point: ";
	cin >> x >> y;

	Point p1(x, y); // 生成点对象1
	cout << "Point p1: ";
	p1.print();

	Point p2(x * 2, y * 2); //生成点对象2
	cout << "Point p2: ";
	p2.print();

	p1.moveRight(10);
	cout << "After moving right, p1: ";
	p1.print();

	p2.moveDown(-10); // 位移量为负数，表示向上移动
	cout << "After moving down, p2: ";
	p2.print();

	return 0;
}

