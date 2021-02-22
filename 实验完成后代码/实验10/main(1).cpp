#include <iostream>
#include <cstring>
#include "Point.h"
#include "Date.h"
#include "Employee.h"

using namespace std;

void Point::print() {
    cout << "(" << x << ", " << y << ")\n";
}

void Date::printFullYear() {
	cout << year << separator << month << separator << day;
}

void Employee::print() {
    cout << lastName << ", " << firstName << " Hired: ";
	hireDate.printFullYear();
	cout << " Birthday: ";
	birthDate.printFullYear();
}

template <typename T>
T most(T a[],int n) {
    int i;
    T maxMember = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > maxMember)
            maxMember = a[i];
    return maxMember;
}

int main(){
    int i;
    Point points[5] = {Point(2, 3), Point(4, 5), Point(3, 4), Point(5, 2), Point(3, 3)};
    Point point;
    Date dates[5] = {Date(1997, 8, 7), Date(1999, 12, 21), Date(2000, 10, 21), Date(2002, 3, 21), Date(2000, 5, 4)};
    Date date;
    Date birthD[5] = {Date(1965, 5, 6), Date(1967, 8, 9), Date(1977, 10, 4), Date(1978, 2, 9), Date(1980, 8, 9)};
    Date hireD[5] = {Date(1995, 5, 6), Date(1993, 8, 9), Date(1997, 10, 4), Date(1998, 2, 9), Date(2000, 8, 9)};
    Employee manager1("a", "b", birthD[0], hireD[0]);
    Employee manager2("c", "d", birthD[1], hireD[1]);
    Employee manager3("e", "f", birthD[2], hireD[2]);
    Employee manager4("g", "h", birthD[3], hireD[3]);
    Employee manager5("i", "j", birthD[4], hireD[4]);
    Employee employees[5] = {manager1, manager2, manager3, manager4, manager5};
    Employee employee;

    for (i = 0; i < 5; i++)
        points[i].distanceTo();

    point = most(points, 5);
    cout << "距离原点最远的点是：";
    point.print();

    date = most(dates, 5);
    cout << "数组中最晚的日期是：";
    date.printFullYear();

    employee = most(employees, 5);
    cout << "\n数组中年龄最大的雇员是：";
    employee.print();

    return 0;
}
