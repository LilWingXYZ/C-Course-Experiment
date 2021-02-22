#include <iostream>
using namespace std;

class Point {
public:
	/* Ĭ�Ϲ��캯����Ĭ��ֵΪ���Ͻ�����(0, 0) */
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

	Point p1(x, y); // ���ɵ����1
	cout << "Point p1: ";
	p1.print();

	Point p2(x * 2, y * 2); //���ɵ����2
	cout << "Point p2: ";
	p2.print();

	p1.moveRight(10);
	cout << "After moving right, p1: ";
	p1.print();

	p2.moveDown(-10); // λ����Ϊ��������ʾ�����ƶ�
	cout << "After moving down, p2: ";
	p2.print();

	return 0;
}

