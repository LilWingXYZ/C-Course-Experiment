#include <string>
#include "Date.h"

using namespace std;

class Employee {
public:
	Employee(const string, const string, const Date &, const Date &);
	void print() const;

	// ����Ա���ڲ���ָ��������ʱ����������
	int getAge(const Date &date) const;

	// �����Ա���������˶�����
	int getYearsWorked(const Date &date) const;
	// �����Ա�������˶�����
	int getDaysWorked(const Date &date) const;

private:
	string firstName;
	string lastName;
	const Date birthDate; // composition: member object
	const Date hireDate;
};
