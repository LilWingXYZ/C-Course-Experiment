#include <string>
#include "Date.h"

using namespace std;

class Employee {
public:
	Employee(const string, const string, const Date &, const Date &);
	void print() const;

	// 计算员工在参数指定的日期时，满多少岁
	int getAge(const Date &date) const;

	// 计算该员工工作满了多少年
	int getYearsWorked(const Date &date) const;
	// 计算该员工工作了多少天
	int getDaysWorked(const Date &date) const;

private:
	string firstName;
	string lastName;
	const Date birthDate; // composition: member object
	const Date hireDate;
};
