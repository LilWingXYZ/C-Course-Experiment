#include<iostream>
using namespace std;

struct Rule
{
    double M;
    double R;
};

void inputRules(struct Rule rules[], int n)
{
    rules[0].M = 0;
    rules[0].R = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << "请输入第 " << i << " 条规则：";
        cin >> rules[i].M >> rules[i].R;
    }
}

double computeTax(struct Rule rules[], int n, double income)
{
    double tax=0;
    int i=0;
    for (i = 0; i < n; i++)
    {
        if (income >= rules[i+1].M) tax += (rules[i+1].M - rules[i].M) *rules[i].R / 100;
        else {tax += (income - rules[i].M) *rules[i].R / 100; break;}
        if (i == n-1) tax += (income - rules[i+1].M) *rules[i+1].R / 100;
    }
    return tax;
}

int main()
{
    int n;
    double income;
    double tax;
    struct Rule rules[100];
    cout << "请输入规则的条数：";
    cin >> n;
    inputRules(rules, n);
    cout << "纳税线    税率" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << rules[i].M <<"   "<<rules[i].R << endl;
    }

    while(1)
    {
        cout << "请输入您的收入：";
        cin >> income;
        if (income == -1) {cout << "再见" << endl;break;}
        tax = computeTax(rules, n, income);
        cout << "您的收入是：" << income << "， 应缴所得税：" << tax << " 元。" << endl;
    }
    return 0;
}
