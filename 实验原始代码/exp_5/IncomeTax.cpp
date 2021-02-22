#include <iostream>
#include <iomanip>

using namespace std;

struct TaxRule {
	int baseLine; // 纳税线
	int rate; // 税率
};

// 静态全局变量，指向征税规则的指针，仅在本cpp文件内全局有效
static struct TaxRule* taxRules;
// 静态全局变量，征税规则的条数，仅在本cpp文件内全局有效
static int ruleNum = 0;

void setRules(); // 从用户输入获得征税规则
void displayRules(); // 显示征税规则
double compTax(int); // 计算给定收入的所得税

// 从键盘输入纳税规则
void setRules() {
	// 获得规则的条数
	cout << "请输入规则的条数：";
	cin >> ruleNum;

	// 生成指定条数的规则
	taxRules = new struct TaxRule[ruleNum];

	// 获得用户输入的规则
	for (int i = 0; i < ruleNum; i++) {
		cout << "请输入第 " << (i + 1) << " 条规则：";
		cin >> taxRules[i].baseLine >> taxRules[i].rate;
	}

}

// 显示规则
void displayRules() {
	cout << "\n纳税规则如下：\n";
	cout << "纳税线\t税率\n";
	for (int i = 0; i < ruleNum; i++) {
		cout << taxRules[i].baseLine << "\t\t" << taxRules[i].rate << endl;
	}
}

// 计算纳税金额
double compTax(int income) {

	double sum = 0.0;
	int i = 0;

	if (taxRules[0].baseLine > income)
		return 0.0;

	// 逐次检查每一个纳税线，直到检查完说有纳税线或者找到一个比输入大的纳税线。
	// 在此过程中，累加两个相邻纳税线之间的税额。
	for (i = 1; i < ruleNum && taxRules[i].baseLine <= income; i++) {
		//累加计算纳税金额。为了提高速度，税率先不除以100.
		sum = sum + (taxRules[i].baseLine - taxRules[i - 1].baseLine) * taxRules[i - 1].rate;
	}

	// for循环结束时，要么找到了某个大于income的纳税线，
	// 要么所有纳税线都比income小。
	// 不管是哪种情况，都看income超过前一个纳税线多少。
	// 如果所有纳税线都比income小，此时i和ruleNum相等，
	// 我们就可以把最后一个纳税线看作前一个纳税线。
	int remains = income - taxRules[i - 1].baseLine;

	// 将超出部分按前一个纳税线计算纳税金额
	sum = sum + remains * taxRules[i - 1].rate;

	// 最后计算所得的税额除以100
	return sum / 100;
}


/**
 * 计算所得税的主类。
 * 与TaxRule类之间是依赖关系。因为其main方法通过局部变量使用了TaxRule的实例。
 * @author Jianliang Xu
 *
 */
int main() {
	setRules();
	// 显示规则
	displayRules();

	// 存放用户输入的收入金额的局部变量
	int income = 0;

	// 接受用户的输入并计算所得税
	while (true) {
		cout << "\n请输入您的收入：";
		cin >> income;
		if (income == -1) {
			cout << "Good Bye!!" << endl;
			break;
		}
		cout << "您的收入是：" << income << "，" << "应缴所得税：" << setprecision(2) << fixed << compTax(income) << "元。" << endl;
	}

	return 0;
}
