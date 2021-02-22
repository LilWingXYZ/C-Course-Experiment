#include <iostream>

using namespace std;

struct Point {
	int x; // 横坐标
	int y; // 纵坐标
};

void printPoint(const struct Point * p) {
	cout << "(" << p->x << ", " << p->y << ")";
}

// 得到用户输入的两个点
void getTwoPoints(struct Point *startP, struct Point *endP) {
	cout << "Please input the coordinate (x, y) of the start point: ";
	cin >> (startP->x);
	cin >> (startP->y);

	cout << "Please input the coordinate (x, y) of the end point: ";
	cin >> endP->x;
	cin >> endP->y;

}

// 显示主菜单
void displayMenu() {
	cout << "*******************************\n";
	cout << "    1. Circle (圆)\n";
	cout << "    2. Rectangle (长方形)\n";
	cout << "    0. Exit (退出)\n";
	cout << "*******************************\n";
	cout << "Please select the shape: ";
}

// 根据用户给出的起点和终点，画圆
bool drawCircleAd(struct Point *startP, struct Point *endP) {
	struct Point center; // 圆心坐标
	int radius; // 半径

	if ((endP->x - startP->x) != (endP->y - startP->y)) {
		cout << "Not a circle, please input two points again!\n";
		return false;
	} else {
		center.x = (startP->x + endP->x) / 2; // 计算圆心横坐标
		center.y = (startP->y + endP->y) / 2; // 计算圆心纵坐标
		radius = (endP->x - startP->x) / 2; // 计算半径

		// 模拟画圆
		cout << "Draw a circle at center ";
		printPoint(&center);
		cout << " with radius " << radius << endl;
		return true;
	}

}

// 根据用户给出的起点和终点，画长方形
bool drawRectangleAd(struct Point *startP, struct Point *endP) {
	int width, height;

	width = endP->x - startP->x; // 长
	height = endP->y - startP->y; // 宽

	if (width <= 0 || height <= 0) {
		cout << "Not a rectangle, please input two points again!\n";
		return false;
	}
	// 模拟画长方形
	cout << "Draw a rectangle at topleft ";
	printPoint(startP);
	cout << ", whose width is " << width << " and height is " << height << endl;
	return true;

}

int main() {
	int choice = 1; // 用户选择

	struct Point startP; // 起点
	struct Point endP; // 终点
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

// 根据用户给出的起点和终点，画圆
void drawCircle(struct Point *startP, struct Point *endP) {
	struct Point center; // 圆心坐标
	int radius; // 半径

	if ((endP->x - startP->x) != (endP->y - startP->y))
		cout << "Not a circle, Select again\n";
	else {
		center.x = (startP->x + endP->x) >> 1; // 计算圆心横坐标
		center.y = (startP->y + endP->y) >> 1; // 计算圆心纵坐标
		radius = (endP->x - startP->x) >> 1; // 计算半径

		// 模拟画圆
		cout << "Draw a circle at center ";
		printPoint(&center);
		cout << " with radius " << radius << endl;
	}

}

// 根据用户给出的起点和终点，画长方形
void drawRectangle(struct Point *startP, struct Point *endP) {
	int width, height;

	width = endP->x - startP->x; // 长
	height = endP->y - startP->y; // 宽

	// 模拟画长方形
	cout << "Draw a rectangle at topleft ";
	printPoint(startP);
	cout << ", whose width is " << width << " and height is " << height << endl;

}

void ShapesMain() {
	int choice = 1; // 用户选择

	struct Point startP; // 起点
	struct Point endP; // 终点

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
