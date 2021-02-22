#include <iostream>
#include <iomanip>
#include "Employee.h"
#include "Date.h"

using namespace std;

Employee::Employee(const string first, const string last,
		const Date &dateOfBirth, const Date &dateOfHire)
		: firstName(first), lastName(last),
		  birthDate(dateOfBirth),
		  hireDate(dateOfHire) { }

void Employee::print() const {
	cout << lastName << ", " << firstName << " Hired: ";
	cout << hireDate;
	cout << ", Birthday: ";
	cout << birthDate << endl;
}
int Employee::getAge(const Date& date) const {
	return birthDate.fullYearsTo(date);
}

int Employee::getYearsWorked(const Date& date) const {
	return hireDate.fullYearsTo(date);
}

int Employee::getDaysWorked(const Date& date) const {
	return date - hireDate;
}

void main() {
	Date birth(1969, 8, 11);
	Date hire(1998, 4, 1);

	Date today(2010, 4, 30);

	Employee manager("Bob", "Blue", birth, hire);
	cout << endl;

	manager.print();

	cout << "到";
	today.printFullYear();
	cout << "为止" << endl;
	cout << "   雇员已满" << manager.getAge(today) << "岁" << endl;
	cout << "   雇员已工作了" << manager.getDaysWorked(today) << "天" << endl;

}