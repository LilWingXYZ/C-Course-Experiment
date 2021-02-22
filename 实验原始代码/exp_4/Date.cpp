#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

// constructor confirms proper value for month; calls utility function checkDay to confirm proper value for day
Date::Date(int year, int month, int day) {
	setYear(year);
	setMonth(month);
	setDay(day);
	setSeparator('-');
}

void Date::setYear(int year) {
	this->year = year;
}

void Date::setMonth(int month) {
	if (month >= 0 && month <= 12)
		this->month = month;
	else {
		this->month = 1;
		cout << "Invalid month (" << month << ") set to 1.\n";
	}
}

void Date::setDay(int day) {
	this->day = checkDay(day); // validate the day.
}

void Date::setSeparator(char c) {
	separator = c;
}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

char Date::getSeparator() const {
	return separator;
}

//Print Date object in form YYYY-MM-DD
void Date::printFullYear() const {
	cout << year << separator
		<< setfill('0') << setw(2) << month << separator
		<< setw(2) << day;
}

//Print Date object in form YY-MM-DD
void Date::printStandardYear() const {
	cout << setfill('0') << setw(2) << (year % 100) << separator
		<< setw(2) << month << separator
		<< setw(2) << day;
}

// ���㵱ǰ�������������֮���������꣬ע�����Ϊ���ڶ��������
int Date::fullYearsTo(const Date &date) const {
	// �����ǰ���ڵ���С�ڲ������ڵ��£�
	// ��������ȣ����ҵ�ǰ���ڵ���С�ڵ��ڲ������ڵ���
	if ((month < date.month) || (month == date.month && day <= date.day))
		return date.year - year;
	else
		return date.year - year - 1;
}

// ���㵱ǰ���ڱȲ����������˶�����(��������)
// ��������������ڵ�ǰ���ڣ����ظ�����ע�����Ϊ���ڶ�������á�
int Date::operator -(const Date &date) const {
	const Date* startDate;		// ��ʼ���ڣ�
	const Date* endDate;		// �������ڣ�
	bool ascent = true;         // ��ǰ�������ڲ������ڣ���Ϊ�档Ĭ��Ϊ�档

	// �����ͬһ����
	if (this->year == date.year) {
		return this->getDayOfYear() - date.getDayOfYear();
	}

	// ����ͬһ���У��ҵ�ǰ������	
	if (this->year > date.year) 	{
		startDate = &date;
		endDate = this;
		// �����ǰ������
	} else {
		startDate = this;
		endDate = &date;
		ascent = false;
	}

	// �ȼ��Ͽ�ʼ���ڵ��������������
	int offsetDays = startDate->getLeftDaysYear();

	// �ټ��Ͽ�ʼ���ںͽ�������֮�������������� ����������ֹ�꣩
	for (int i = startDate->year + 1; i < endDate->year; i++) {
		offsetDays += getYearDays(i);
	}

	// �ټ��Ͻ�������ʱ�������Ѿ���������
	offsetDays += endDate->getDayOfYear();

	
	if (ascent)   // ���������
		return offsetDays;
	else		  // ����ǽ��򣬷��ظ���
		return 0 - offsetDays;
}

// ���㵱ǰ�����Ǳ���ĵڼ���
int Date::getDayOfYear() const {
	int days = 0;

	for (int i = 1; i<month; i++) {
		days += daysPerMonth[i - 1];
	}
	days += day;
	if (isLeapyear(year) && month > 2)
		days++;

	return days;
}

// ���㵱ǰ���ھ౾��������м���
// ��������ǰ������һ��
int Date::getLeftDaysYear() const {
	return getYearDays(year) - getDayOfYear();
}

// ����ĳһ���ж�����
int Date::getYearDays(int year) const {
	if (isLeapyear(year))
		return 366;
	return 365;
}

// utility function to confirm proper day value based on month and year; handle leap years, too.
int Date::checkDay(int testDay) const {
	if (testDay > 0 && testDay <= daysPerMonth[month - 1])
		return testDay;

	if (isLeapyear(year) && month == 2 && testDay == 29)
		return testDay;

	cout << "Invalid day (" << testDay << ") set to 1.\n";
	return 1;
}

bool Date::isLeapyear(int year) const {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

void main() {
	Date birthDate(1991, 1, 11);    // �ҵ�����
	birthDate.printFullYear();      // ��ӡ��1969-08-11
	cout << endl;

	birthDate.printStandardYear(); // ��ӡ��69-08-11
	cout << endl;

	birthDate.setSeparator('/');
	birthDate.printFullYear(); // ��ӡ��1969/08/11
	cout << endl;
	cout << endl;

	Date date(2000, 2, 29);
	cout << date.getDayOfYear() << endl;
	cout << birthDate.fullYearsTo(date) << endl; // ��ӡ��40������ʮ��
	cout << date - birthDate << endl; // ��ӡ14857������14857����

	Date date2(1949, 10, 1);
	cout << birthDate - date2 << endl; // ��ӡ-7254�����͹������絮����7254��
}

const int Date::daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

istream & operator >>(istream &input, Date &date) {
	input >> date.year >> date.month >> date.day;
	return input;
}

ostream & operator <<(ostream &output, const Date &date) {
	output << date.year << "-" << date.month << "-" << date.day;
	return output;
}