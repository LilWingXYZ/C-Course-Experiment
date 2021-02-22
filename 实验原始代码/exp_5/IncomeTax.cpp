#include <iostream>
#include <iomanip>

using namespace std;

struct TaxRule {
	int baseLine; // ��˰��
	int rate; // ˰��
};

// ��̬ȫ�ֱ�����ָ����˰�����ָ�룬���ڱ�cpp�ļ���ȫ����Ч
static struct TaxRule* taxRules;
// ��̬ȫ�ֱ�������˰��������������ڱ�cpp�ļ���ȫ����Ч
static int ruleNum = 0;

void setRules(); // ���û���������˰����
void displayRules(); // ��ʾ��˰����
double compTax(int); // ����������������˰

// �Ӽ���������˰����
void setRules() {
	// ��ù��������
	cout << "����������������";
	cin >> ruleNum;

	// ����ָ�������Ĺ���
	taxRules = new struct TaxRule[ruleNum];

	// ����û�����Ĺ���
	for (int i = 0; i < ruleNum; i++) {
		cout << "������� " << (i + 1) << " ������";
		cin >> taxRules[i].baseLine >> taxRules[i].rate;
	}

}

// ��ʾ����
void displayRules() {
	cout << "\n��˰�������£�\n";
	cout << "��˰��\t˰��\n";
	for (int i = 0; i < ruleNum; i++) {
		cout << taxRules[i].baseLine << "\t\t" << taxRules[i].rate << endl;
	}
}

// ������˰���
double compTax(int income) {

	double sum = 0.0;
	int i = 0;

	if (taxRules[0].baseLine > income)
		return 0.0;

	// ��μ��ÿһ����˰�ߣ�ֱ�������˵����˰�߻����ҵ�һ������������˰�ߡ�
	// �ڴ˹����У��ۼ�����������˰��֮���˰�
	for (i = 1; i < ruleNum && taxRules[i].baseLine <= income; i++) {
		//�ۼӼ�����˰��Ϊ������ٶȣ�˰���Ȳ�����100.
		sum = sum + (taxRules[i].baseLine - taxRules[i - 1].baseLine) * taxRules[i - 1].rate;
	}

	// forѭ������ʱ��Ҫô�ҵ���ĳ������income����˰�ߣ�
	// Ҫô������˰�߶���incomeС��
	// �������������������income����ǰһ����˰�߶��١�
	// ���������˰�߶���incomeС����ʱi��ruleNum��ȣ�
	// ���ǾͿ��԰����һ����˰�߿���ǰһ����˰�ߡ�
	int remains = income - taxRules[i - 1].baseLine;

	// ���������ְ�ǰһ����˰�߼�����˰���
	sum = sum + remains * taxRules[i - 1].rate;

	// ���������õ�˰�����100
	return sum / 100;
}


/**
 * ��������˰�����ࡣ
 * ��TaxRule��֮����������ϵ����Ϊ��main����ͨ���ֲ�����ʹ����TaxRule��ʵ����
 * @author Jianliang Xu
 *
 */
int main() {
	setRules();
	// ��ʾ����
	displayRules();

	// ����û������������ľֲ�����
	int income = 0;

	// �����û������벢��������˰
	while (true) {
		cout << "\n�������������룺";
		cin >> income;
		if (income == -1) {
			cout << "Good Bye!!" << endl;
			break;
		}
		cout << "���������ǣ�" << income << "��" << "Ӧ������˰��" << setprecision(2) << fixed << compTax(income) << "Ԫ��" << endl;
	}

	return 0;
}
