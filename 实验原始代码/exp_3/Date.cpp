#include <iostream>
#include <iomanip>

using namespace std;

class Date {
public:
	// 默认构造函数，以fullyear的形式给出年月日，默认值为1990年1月1日，同时设置日期分隔符为“-”
	Date(int year = 1990, int month = 1, int day = 1, char separator = '-');

	// get、set方法
	// 设置日期，如果有非法的月或日，将其置为1
	void setDate(int year, int month, int day);
	int getYearDays(int year) const;

	void setYear(int year);
	void setMonth(int month);
	void setDay(int month);
	void setSeparator(char separator);

	int getYear() const;
	int getMonth() const;
	int getDay() const;
	char getSeparator() const;

	// 输出函数，请使用setfill('0')和setw(2)
	void printFullYear() const; // 以YYYY-MM-DD的形式打印，2011-01-08
	void printStandardYear() const; // 以YY-MM-DD的形式打印，比如11-01-08
	// 计算当前日期与参数日期之间相差几个整年，仅考虑参数日期比当前日期晚的情况
	int fullYearsTo(int year, int month, int day) const;
	// 计算当前日期与参数日期之间相差多少天(考虑闰年)，如果参数日期在当前日期之前，返回负数。
	int daysTo(int year, int month, int day) const;
	int getLeftDaysYear() const;

	int getDayOfYear() const;

	friend ostream & operator <<(ostream & output, const Date & date);
	friend istream & operator >>(istream & input, Date & date);
	int operator -(const Date & date) const;
	bool operator ==(const Date & date) const;
	const Date operator +=(int days);
	bool operator >(const Date & date) const;

private:
	int checkDay(int testDay) const;
	bool isLeapyear(int year) const;

private:
	int year;
	int month;
	int day;
	char separator; // 日期分隔符

	const static int DAYS_PER_MONTH[12];

};

istream & operator >>(istream & input, Date & date) {
	input >> date.year >> date.month >> date.day;

	return input;
}

ostream & operator<<(ostream & output, const Date & date) {
	output << date.year << "-" << date.month << "-" << date.day;
	return output;
}

const int Date::DAYS_PER_MONTH[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date(int year, int month, int day, char separator) :
		year(year), month(month), day(day), separator(separator) {
}

void Date::setDate(int year, int month, int day) {
	this->year = year;
	this->month = month;
	this->day = day;
}

void Date::setYear(int year) {
	this->year = year;
}
void Date::setMonth(int month) {
	if (month >= 0 && month <= 12)
		this->month = month;
	else {
		this->month = 1;
		cout << "Invalid month (" << month << "), set to 1." << endl;
	}
}
void Date::setDay(int day) {
	this->day = checkDay(day); // validate the day.
}
void Date::setSeparator(char separator) {
	this->separator = separator;
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
	cout << year << separator << setfill('0') << setw(2) << month << separator << setw(2) << day << endl;
}

//Print Date object in form YY-MM-DD
void Date::printStandardYear() const {
	cout << setfill('0') << setw(2) << (year % 100) << separator << setw(2) << month << separator << setw(2) << day << endl;
}

// 计算当前日期与参数日期之间相差几个整年，注意参数为日期对象的引用
int Date::fullYearsTo(int year, int month, int day) const {
	// 如果当前日期的月小于参数日期的月；或者月相等，并且当前日期的日小于等于参数日期的日
	if ((this->month < month) || (this->month == month && this->day <= day))
		return year - this->year;
	else
		return year - this->year - 1;
}

// 重载减法运算符 -
// 计算当前日期比参数日期晚了多少天(考虑闰年)
// 如果参数日期晚于当前日期，返回负数，注意参数为日期对象的引用。
int Date::operator -(const Date & date) const {
	const Date *startDate; // 开始日期
	const Date *endDate; // 结束日期
	bool ascent = true; // 当前日期大于参数日期，则为真。默认为真。

	// 如果在同一年中
	if (year == date.year) {
		return getDayOfYear() - date.getDayOfYear();
	}

	// 不在同一年中，且当前日期大于参数日期
	if (year > date.year) {
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

	// 如果是升序
	if (ascent)
		return offsetDays;
	// 如果是降序，返回负数
	else
		return 0 - offsetDays;
}

// 重载 > 运算符
bool Date::operator >(const Date & date) const {

	if (year == date.year) {
		if (month != date.month)
			return (month > date.month);
		else
			return (day > date.day);
	} else
		return (year > date.year);
}

// 重载 == 运算符
bool Date::operator ==(const Date & date) const {
	return (year == date.year) && (month == date.month) && (day == date.day);
}

const Date Date::operator +=(int days) {
	int upperDay = 0;
	for (int i = 1; i <= days; i++) {
		if (isLeapyear(year) && month == 2)
			upperDay = 29;
		else
			upperDay = DAYS_PER_MONTH[month - 1];

		if (day < upperDay)
			day++;
		else {
			day = 1;
			if (month < 12)
				month += 1;
			else {
				month = 1;
				year += 1;
			}
		}
	}
	return *this;
}

// 计算某一年有多少天，闰年366天，平年365天
int Date::getYearDays(int year) const {
	if (isLeapyear(year))
		return 366;
	return 365;
}

// 计算当前日期距本年结束还有几天，不包括当前日期这一天
int Date::getLeftDaysYear() const {
	return getYearDays(year) - getDayOfYear();
}

bool Date::isLeapyear(int year) const {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

// utility function to confirm proper day value based on month and year; handle leap years, too.
int Date::checkDay(int testDay) const {
	if (testDay > 0 && testDay <= DAYS_PER_MONTH[month - 1])
		return testDay;

	if (isLeapyear(year) && month == 2 && testDay == 29)
		return testDay;

	cout << "Invalid day (" << testDay << ") set to 1.\n";
	return 1;
}

// 计算当前日期是本年的第几天
int Date::getDayOfYear() const {

	int days = 0; // 初始化

	// 加上从本年1月到当前日期前一月的所有天数（整月）
	for (int i = 1; i < month; i++) {
		days += DAYS_PER_MONTH[i - 1];
	}

	days += day; // 加上当前月的日子

	// 如果是闰年，并且当前日期大于等于2月，再加一天
	if (isLeapyear(year) && month > 2)
		days++;

	return days;
}

int Date::daysTo(int year, int month, int day) const {
	Date date(year, month, day);

	const Date *startDate; // 开始日期
	const Date *endDate; // 结束日期
	bool ascent = true; // 当前日期大于参数日期，则为真。默认为真。

	// 如果在同一年中
	if (this->year == year) {
		return getDayOfYear() - date.getDayOfYear();
	}

	// 不在同一年中，且当前日期大于参数日期
	if (this->year > year) {
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
	for (int i = startDate->year + 1; i < endDate->year; i++)
		offsetDays += getYearDays(i);

	// 再加上结束日期时，该年已经过的天数
	offsetDays += endDate->getDayOfYear();

	// 如果是升序，返回负数
	if (ascent)
		return 0 - offsetDays;
	// 如果是降序
	else
		return offsetDays;
}

int main() {
	Date birthDate(1969, 8, 11);
	birthDate.printFullYear(); // 打印：1969-08-11
	birthDate.printStandardYear(); // 打印：69-08-11
	birthDate.setSeparator('/');
	birthDate.printFullYear(); // 打印：1969/08/11

	cout << birthDate.fullYearsTo(2010, 4, 15) << endl; // 打印：40，满四十岁
	cout << birthDate.daysTo(2010, 4, 15) << endl; // 打印14857，活了14857天了

	cout << birthDate.daysTo(1949, 10, 1) << endl; // 打印-7254，共和国比我早诞生了7254天

	return 0;
}
