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
	// ��ӡ�б���
	cout << "   | ";
	for (int j = 0; j < 9; j++)
		cout << " " << j << " ";
	cout << endl << "---|-----------------------------" << endl;

	// ��ӡÿһ��
	for (int i = 0; i < 9; i++) {
		// ��ӡ�б���
		cout << " " << i + 1 << " | ";

		// ��ӡÿ�е�����
		for (int j = 0; j < 9; j++)
			cout << " " << vedicTable[i][j] << " ";

		cout << endl; // ���У�׼����ӡ��һ��
	}
}

void printVedicStar(int vedicTable[][9], int digit) {
	int bestPartner = 10 - digit;
	// ��ӡÿ�������ı���
	cout << endl << "---------------" << digit << "---------------" << endl;

	// ��ӡ����
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
	int aVedicTable[9][9]; // Vedic Table, ��ά����

	getVedicTable(aVedicTable); // ����Vedic Table

	printVedicTable(aVedicTable); // ��ӡVedic Table

	// ��ӡVedic Star����1��9
	for (int i = 1; i <= 9; i++)
		printVedicStar(aVedicTable, i);

	return 0;
}
