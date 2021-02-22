/***********************************************
 �ļ�����WeatherForecast.cpp
 ��Ҫ��  ģ������Ԥ����һ���µ��¶ȷ���
 ������
 1. displayTemp����ʾ�¼��¶ȵ���״ͼ
 2. displayPeaks����ʾ�¼��¶��еķ�ֵ
 3. displayFlat����ʾ�¼������õ��¶�
 4. forecasting�������û����룬
 ���������3������
 ************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int minTemp(int temp[], int n) {
	int min = temp[0];
	for (int i = 1; i < n; i++) {
		if (min > temp[i])
			min = temp[i];
	}

	return min;
}

// ��ʾ��״ͼ
void displayTemp(int temp[], int n) {
	int min = minTemp(temp, n); // ���������¶�

	for (int i = 0; i < n; i++) {
		if (min < 0) {// ���������¶ȵ�ʱ������¶�С����
			cout << setw(4) << temp[i] << "  ";
			if (temp[i] < 0) {
				for (int j = 0; j < temp[i] - min; j++)
					cout << " ";
				for (int k = temp[i]; k < 0; k++)
					cout << "*";
				cout << "|" << endl;
			} else {
				for (int j = min; j < 0; j++)
					cout << " ";
				cout << "|";
				for (int k = 0; k < temp[i]; k++)
					cout << "*";
				cout << endl;
			}
		} else { // �����������¶ȵ�ʱ��
			cout << setw(4) << temp[i] << "  |";
			for (int j = 0; j < temp[i]; j++)
				cout << "*";
			cout << endl;
		}
	}
}

// ��ʾ�¼��¶��еķ�ֵ
void displayPeaks(int temp[], int n) {
	bool flag = false;

	for (int i = 1; i < n - 1; i++) {
		if (temp[i - 1] < temp[i] && temp[i] > temp[i + 1]) {
			flag = true;
			cout << "Peak at day " << i + 1 << " is " << temp[i] << endl;
		}
	}

	if (!flag)
		cout << "No peaks." << endl;
}

// ��ʾ�¼������õ��¶�
void displayFlat(int temp[], int n) {
	int length = 1;
	int maxLength = 0;

	for (int i = 1; i < n; i++) {
		if (temp[i - 1] == temp[i])
			length++;
		else {
			if (length > maxLength)
				maxLength = length;
			length = 1;
		}
	}

	// ����������������
	if (length > maxLength)
		maxLength = length;

	cout << "The length of longest flat is " << maxLength << endl;
}

int main() {
	int temp[15]; // �洢 15 ����¶�

	cout << "Please input the tempratures:\n";

	// ���� 15 ����¶�
	for (int i = 0; i < 15; i++)
		cin >> temp[i];

	cout << "\n��ʾ��״ͼ���£�\n";
	displayTemp(temp, 15); // ��ʾ��״ͼ

	cout << "\n��ʾ��ֵ���£�\n";
	displayPeaks(temp, 15); // ������еķ�ֵ�¶�

	cout << "\n��ʾ�ĵĳ������£�\n";
	displayFlat(temp, 15); // �������ʱ������¶�

	return 0;
}
