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

// 计算当前日期与参数日期之间相差几个整年，注意参数为日期对象的引用
int Date::fullYearsTo(const Date &date) const {
	// 如果当前日期的月小于参数日期的月；
	// 或者月相等，并且当前日期的日小于等于参数日期的日
	if ((month < date.month) || (month == date.month && day <= date.day))
		return date.year - year;
	else
		return date.year - year - 1;
}

// 计算当前日期比参数日期晚了多少天(考虑闰年)
// 如果参数日期晚于当前日期，返回负数，注意参数为日期对象的引用。
int Date::operator -(const Date &date) const {
	const Date* startDate;		// 开始日期；
	const Date* endDate;		// 结束日期；
	bool ascent = true;         // 当前日期晚于参数日期，则为真。默认为真。

	// 如果在同一年中
	if (this->year == date.year) {
		return this->getDayOfYear() - date.getDayOfYear();
	}

	// 不在同一年中，且当前日期晚	
	if (this->year > date.year) 	{
		startDate = &date;
		endDate = this;
		// 如果当前日期早
	} else {
		startDate = this;
		endDate = &date;
		ascent = false;
	}

	// 先加上开始日期到该年结束的天数
	int offsetDays = startDate->getLeftDaysYear();

	// 再加上开始日期和结束日期之间的所有年的天数 （不包括起止年）
	for (int i = startDate->year + 1; i < endDate->year; i++) {
		offsetDays += getYearDays(i);
	}

	// 再加上结束日期时，该年已经过的天数
	offsetDays += endDate->getDayOfYear();

	
	if (ascent)   // 如果是升序
		return offsetDays;
	else		  // 如果是降序，返回负数
		return 0 - offsetDays;
}

// 计算当前日期是本年的第几天
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

// 计算当前日期距本年结束还有几天
// 不包括当前日期这一天
int Date::getLeftDaysYear() const {
	return getYearDays(year) - getDayOfYear();
}

// 计算某一年有多少天
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
	Date birthDate(1991, 1, 11);    // 我的生日
	birthDate.printFullYear();      // 打印：1969-08-11
	cout << endl;

	birthDate.printStandardYear(); // 打印：69-08-11
	cout << endl;

	birthDate.setSeparator('/');
	birthDate.printFullYear(); // 打印：1969/08/11
	cout << endl;
	cout << endl;

	Date date(2000, 2, 29);
	cout << date.getDayOfYear() << endl;
	cout << birthDate.fullYearsTo(date) << endl; // 打印：40，满四十岁
	cout << date - birthDate << endl; // 打印14857，活了14857天了

	Date date2(1949, 10, 1);
	cout << birthDate - date2 << endl; // 打印-7254，共和国比我早诞生了7254天
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