#include<iostream>
#include<cstring>
using namespace std;

void swap(char str[], int i, int j) {
	char ch = str[i];
	str[i] = str[j];
	str[j] = ch;
}

void bubbleSort(char **result, int counter, int length) {
	char *str = new char[length];
	for (int i = counter - 1; i > 0; i--)
		for (int j = 0; j < i - 1; j++)
			if (strcmp(result[j + 1], result[j]) < 0) {
				strcpy(str, result[j]);
				strcpy(result[j], result[j + 1]);
				strcpy(result[j + 1], str);
			}
	delete[] str;
}

bool check(char *sliders, int length) {
	int wMaxIndex = 0, bMinIndex = 0;
	bool notFoundB = true;
	for (int i = 0; i < length; i++) {
		if (sliders[i] == 'W')
			wMaxIndex = i;
		if (notFoundB && (sliders[i] == 'B')) {
			bMinIndex = i;
			notFoundB = true;
		}
	}

	if (wMaxIndex < bMinIndex)
		return true;

	return false;
}

int main() {
	const int MAX_NUM = 6;
	int N;

	cin >> N;

	char **buffer = new char *[N];

	for (int i = 0; i < N; i++) {
		int numSlider;
		cin >> numSlider;
		buffer[i] = new char[2 * numSlider + 1];
		cin >> buffer[i];
	}

	for (int k = 0; k < N; k++) {
		int counter = 0;
		int length = strlen(buffer[k]);
		char *sliders = new char[length]; // 输入字符串
		char *result[MAX_NUM];

		cout << "结果_" << k + 1 << endl;

		strcpy(sliders, buffer[k]);

		if (check(sliders, length)) {
			cout << "目标格局" << endl;
			continue;
		}

		for (int i = 0; i < MAX_NUM; i++) {
			result[i] = new char[length];
			strcpy(result[i], sliders);
		}

		int index = 0;
		for (; index < length; index++) { // 查找空格字符E
			if (sliders[index] == 'E')
				break;
		}

		for (int offset = 1; offset < 4; offset++) {
			if (index + offset < length) {
				swap(result[counter], index, index + offset);
				counter++;
			}
			if (index - offset >= 0) {
				swap(result[counter], index, index - offset);
				counter++;
			}
		}

		bubbleSort(result, counter, length);

		for (int m = 0; m < counter; m++)
			cout << result[m] << endl;

		delete[] sliders;
		for (int t = 0; t < MAX_NUM; t++)
			delete[] result[t];

		counter = 0;
	}

	for (int j = 0; j < N; j++)
		delete[] buffer[j];
	delete[] buffer;

	return 0;
}

