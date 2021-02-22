/***********************************************
 文件名：WeatherForecast.cpp
 概要：  模拟天气预报，一个月的温度分析
 函数：
 1. displayTemp，显示月间温度的柱状图
 2. displayPeaks，显示月间温度中的峰值
 3. displayFlat，显示月间持续最久的温度
 4. forecasting，接收用户输入，
 调用上面的3个函数
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

// 显示柱状图
void displayTemp(int temp[], int n) {
	int min = minTemp(temp, n); // 先求出最低温度

	for (int i = 0; i < n; i++) {
		if (min < 0) {// 存在零下温度的时候，最低温度小于零
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
		} else { // 不存在零下温度的时候
			cout << setw(4) << temp[i] << "  |";
			for (int j = 0; j < temp[i]; j++)
				cout << "*";
			cout << endl;
		}
	}
}

// 显示月间温度中的峰值
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

// 显示月间持续最久的温度
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

	// 处理最长崮在最后的情况
	if (length > maxLength)
		maxLength = length;

	cout << "The length of longest flat is " << maxLength << endl;
}

int main() {
	int temp[15]; // 存储 15 天的温度

	cout << "Please input the tempratures:\n";

	// 输入 15 天的温度
	for (int i = 0; i < 15; i++)
		cin >> temp[i];

	cout << "\n显示柱状图如下：\n";
	displayTemp(temp, 15); // 显示柱状图

	cout << "\n显示峰值如下：\n";
	displayPeaks(temp, 15); // 求出所有的峰值温度

	cout << "\n显示崮的长度如下：\n";
	displayFlat(temp, 15); // 求出持续时间最长的温度

	return 0;
}
