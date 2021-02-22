#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <cstring>
#include "Date.h"
using namespace std;

class Employee{
public:
    Employee() {}
    Employee(string, string, Date &, Date &);
    void print();
    bool operator >(Employee &employee);
    ~Employee() {}
private:
    string firstName;
    string lastName;
    Date birthDate;
    Date hireDate;
};

Employee::Employee(string firstName, string lastName, Date &birthDate, Date &hireDate) {
	this -> firstName = firstName;
	this -> lastName = lastName;
	this -> birthDate = birthDate;
	this -> hireDate = hireDate;
}

bool Employee::operator >(Employee &employee) {
    if (this -> birthDate > employee.birthDate)
        return false;
    else
        return true;
}

#endif // EMPLOYEE_H_INCLUDED
