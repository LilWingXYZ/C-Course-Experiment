#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
	int next, current = 0, numbers, temp, time = 0;
	int counter = 0;
	int values[20] = { 0 };
	string text[20][51];

	while (cin >> numbers && numbers != 0) {
		time = 0;
		current = 0;
		stringstream sStream;

		for (int i = 0; i < numbers; i++) {
			cin >> next;
			temp = next - current;
			if (temp > 0) {
				time += temp * 6 + 5;
				sStream << "6 * " << temp << " + 5";
			} else {
				time += (-temp) * 4 + 5;
				sStream << "4 * " << -temp << " + 5";
			}
			current = next;
			text[counter][i].append(sStream.str());
			sStream.str("");
		}
		values[counter] = time;
		counter++;
	}

	for (int i = 0; i < counter; i++) {
		cout << values[i] << " (";
		for (int j = 0; j < 50; j++) {
			cout << text[i][j];
			if (! text[i][j + 1].empty())
				cout << " + ";
		}
		cout << ")" << endl;
	}

	return 0;
}
