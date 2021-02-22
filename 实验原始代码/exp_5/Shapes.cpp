#include <iostream>

using namespace std;

struct Point {
	int x; // ������
	int y; // ������
};

void printPoint(const struct Point * p) {
	cout << "(" << p->x << ", " << p->y << ")";
}

// �õ��û������������
void getTwoPoints(struct Point *startP, struct Point *endP) {
	cout << "Please input the coordinate (x, y) of the start point: ";
	cin >> (startP->x);
	cin >> (startP->y);

	cout << "Please input the coordinate (x, y) of the end point: ";
	cin >> endP->x;
	cin >> endP->y;

}

// ��ʾ���˵�
void displayMenu() {
	cout << "*******************************\n";
	cout << "    1. Circle (Բ)\n";
	cout << "    2. Rectangle (������)\n";
	cout << "    0. Exit (�˳�)\n";
	cout << "*******************************\n";
	cout << "Please select the shape: ";
}

// �����û������������յ㣬��Բ
bool drawCircleAd(struct Point *startP, struct Point *endP) {
	struct Point center; // Բ������
	int radius; // �뾶

	if ((endP->x - startP->x) != (endP->y - startP->y)) {
		cout << "Not a circle, please input two points again!\n";
		return false;
	} else {
		center.x = (startP->x + endP->x) / 2; // ����Բ�ĺ�����
		center.y = (startP->y + endP->y) / 2; // ����Բ��������
		radius = (endP->x - startP->x) / 2; // ����뾶

		// ģ�⻭Բ
		cout << "Draw a circle at center ";
		printPoint(&center);
		cout << " with radius " << radius << endl;
		return true;
	}

}

// �����û������������յ㣬��������
bool drawRectangleAd(struct Point *startP, struct Point *endP) {
	int width, height;

	width = endP->x - startP->x; // ��
	height = endP->y - startP->y; // ��

	if (width <= 0 || height <= 0) {
		cout << "Not a rectangle, please input two points again!\n";
		return false;
	}
	// ģ�⻭������
	cout << "Draw a rectangle at topleft ";
	printPoint(startP);
	cout << ", whose width is " << width << " and height is " << height << endl;
	return true;

}

int main() {
	int choice = 1; // �û�ѡ��

	struct Point startP; // ���
	struct Point endP; // �յ�
	bool flag = false;

	while (choice) {
		displayMenu();
		cin >> choice;

		flag = false;
		while (!flag) {
			switch (choice) {
			case 1:
				getTwoPoints(&startP, &endP);
				flag = drawCircleAd(&startP, &endP);
				break;
			case 2:
				getTwoPoints(&startP, &endP);
				flag = drawRectangleAd(&startP, &endP);
				break;
			case 0:
				cout << "Good Bye!\n";
				flag = true;
				break;
			default:
				cout << "Error Input! Please select again!\n";
				flag = true;
				break;
			}
		}
	}

	return 0;
}

// �����û������������յ㣬��Բ
void drawCircle(struct Point *startP, struct Point *endP) {
	struct Point center; // Բ������
	int radius; // �뾶

	if ((endP->x - startP->x) != (endP->y - startP->y))
		cout << "Not a circle, Select again\n";
	else {
		center.x = (startP->x + endP->x) >> 1; // ����Բ�ĺ�����
		center.y = (startP->y + endP->y) >> 1; // ����Բ��������
		radius = (endP->x - startP->x) >> 1; // ����뾶

		// ģ�⻭Բ
		cout << "Draw a circle at center ";
		printPoint(&center);
		cout << " with radius " << radius << endl;
	}

}

// �����û������������յ㣬��������
void drawRectangle(struct Point *startP, struct Point *endP) {
	int width, height;

	width = endP->x - startP->x; // ��
	height = endP->y - startP->y; // ��

	// ģ�⻭������
	cout << "Draw a rectangle at topleft ";
	printPoint(startP);
	cout << ", whose width is " << width << " and height is " << height << endl;

}

void ShapesMain() {
	int choice = 1; // �û�ѡ��

	struct Point startP; // ���
	struct Point endP; // �յ�

	while (choice) {
		displayMenu();
		cin >> choice;

		switch (choice) {
		case 1:
			getTwoPoints(&startP, &endP);
			drawCircle(&startP, &endP);
			break;
		case 2:
			getTwoPoints(&startP, &endP);
			drawRectangle(&startP, &endP);
			break;
		case 0:
			cout << "Good Bye!\n";
			break;
		default:
			cout << "Error Input! Please select again!\n";
			break;
		}
	}
}
