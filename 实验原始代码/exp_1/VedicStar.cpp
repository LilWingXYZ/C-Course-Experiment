#include <iostream>
using namespace std;

/* This function returns the sum of all the digits of the integer num. */
int sumDigits(int num) {
	int sum = 0;
	while (num != 0) {
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

/* This function returns the digital root of the integer num. */
int digitalRoot(int num) {
	while (num > 9)
		num = sumDigits(num);
	return num;
}

void getVedicTable(int vedicTable[][9]) {
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			vedicTable[i][j] = digitalRoot((i + 1) * (j + 1));
}

void printVedicTable(int vedicTable[][9]) {
	// 打印行标题
	cout << "   | ";
	for (int j = 0; j < 9; j++)
		cout << " " << j << " ";
	cout << endl << "---|-----------------------------" << endl;

	// 打印每一行
	for (int i = 0; i < 9; i++) {
		// 打印列标题
		cout << " " << i + 1 << " | ";

		// 打印每列的内容
		for (int j = 0; j < 9; j++)
			cout << " " << vedicTable[i][j] << " ";

		cout << endl; // 换行，准备打印下一行
	}
}

void printVedicStar(int vedicTable[][9], int digit) {
	int bestPartner = 10 - digit;
	// 打印每个星座的标题
	cout << endl << "---------------" << digit << "---------------" << endl;

	// 打印星座
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (vedicTable[i][j] == digit || vedicTable[i][j] == bestPartner)
				cout << " * ";
			else
				cout << "   ";
		}
		cout << endl;
	}
}

int main() {
	int aVedicTable[9][9]; // Vedic Table, 二维数组

	getVedicTable(aVedicTable); // 生成Vedic Table

	printVedicTable(aVedicTable); // 打印Vedic Table

	// 打印Vedic Star，从1到9
	for (int i = 1; i <= 9; i++)
		printVedicStar(aVedicTable, i);

	return 0;
}
