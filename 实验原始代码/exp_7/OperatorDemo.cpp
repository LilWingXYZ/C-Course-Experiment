#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Date {
public:
	// Ĭ�Ϲ��캯������fullyear����ʽ���������գ�Ĭ��ֵΪ1990��1��1�գ�ͬʱ�������ڷָ���Ϊ��-��
	Date(int year = 1990, int month = 1, int day = 1, char separator = '-');

	// get��set����
	// �������ڣ�����зǷ����»��գ�������Ϊ1
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

	// �����������ʹ��setfill('0')��setw(2)
	void printFullYear() const; // ��YYYY-MM-DD����ʽ��ӡ��2011-01-08
	void printStandardYear() const; // ��YY-MM-DD����ʽ��ӡ������11-01-08
	// ���㵱ǰ�������������֮���������꣬�����ǲ������ڱȵ�ǰ����������
	int fullYearsTo(int year, int month, int day) const;
	int fullYearsTo(const Date& date) const;
	// ���㵱ǰ�������������֮����������(��������)��������������ڵ�ǰ����֮ǰ�����ظ�����
	int daysTo(int year, int month, int day) const;
	int getLeftDaysYear() const;

	int getDayOfYear() const;

	friend ostream & operator <<(ostream & output, const Date & date);
	friend istream & operator >>(istream & input, Date & date);
	int operator -(const Date & date) const;
	bool operator ==(const Date & date) const;
	const Date operator +=(int days);
	bool operator >(const Date & date) const;
	bool operator <(const Date & date) const;

private:
	int checkDay(int testDay) const;
	bool isLeapyear(int year) const;

private:
	int year;
	int month;
	int day;
	char separator; // ���ڷָ���

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

// ���㵱ǰ�������������֮���������꣬ע�����Ϊ���ڶ��������
int Date::fullYearsTo(int year, int month, int day) const {
	// �����ǰ���ڵ���С�ڲ������ڵ��£���������ȣ����ҵ�ǰ���ڵ���С�ڵ��ڲ������ڵ���
	if ((this->month < month) || (this->month == month && this->day <= day))
		return year - this->year;
	else
		return year - this->year - 1;
}

int Date::fullYearsTo(const Date& date) const {
	// �����ǰ���ڵ���С�ڲ������ڵ��£���������ȣ����ҵ�ǰ���ڵ���С�ڵ��ڲ������ڵ���
	if ((month < date.month) || (month == date.month && day <= date.day))
		return date.year - year;
	else
		return date.year - year - 1;
}

// ���ؼ�������� -
// ���㵱ǰ���ڱȲ����������˶�����(��������)
// ��������������ڵ�ǰ���ڣ����ظ�����ע�����Ϊ���ڶ�������á�
int Date::operator -(const Date & date) const {
	const Date *startDate; // ��ʼ����
	const Date *endDate; // ��������
	bool ascent = true; // ��ǰ���ڴ��ڲ������ڣ���Ϊ�档Ĭ��Ϊ�档

	// �����ͬһ����
	if (year == date.year) {
		return getDayOfYear() - date.getDayOfYear();
	}

	// ����ͬһ���У��ҵ�ǰ���ڴ��ڲ�������
	if (year > date.year) {
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

	// ���������
	if (ascent)
		return offsetDays;
	// ����ǽ��򣬷��ظ���
	else
		return 0 - offsetDays;
}

// ���� > �����
bool Date::operator >(const Date & date) const {
	if (year == date.year) {
		if (month != date.month)
			return (month > date.month);
		else
			return (day > date.day);
	} else
		return (year > date.year);
}

// ���� < �����
bool Date::operator <(const Date & date) const {
	if (year == date.year) {
		if (month != date.month)
			return (month < date.month);
		else
			return (day < date.day);
	} else
		return (year < date.year);
}

// ���� == �����
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

// ����ĳһ���ж����죬����366�죬ƽ��365��
int Date::getYearDays(int year) const {
	if (isLeapyear(year))
		return 366;
	return 365;
}

// ���㵱ǰ���ھ౾��������м��죬��������ǰ������һ��
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

// ���㵱ǰ�����Ǳ���ĵڼ���
int Date::getDayOfYear() const {

	int days = 0; // ��ʼ��

	// ���ϴӱ���1�µ���ǰ����ǰһ�µ��������������£�
	for (int i = 1; i < month; i++) {
		days += DAYS_PER_MONTH[i - 1];
	}

	days += day; // ���ϵ�ǰ�µ�����

	// ��������꣬���ҵ�ǰ���ڴ��ڵ���2�£��ټ�һ��
	if (isLeapyear(year) && month > 2)
		days++;

	return days;
}

int Date::daysTo(int year, int month, int day) const {
	Date date(year, month, day);

	const Date *startDate; // ��ʼ����
	const Date *endDate; // ��������
	bool ascent = true; // ��ǰ���ڴ��ڲ������ڣ���Ϊ�档Ĭ��Ϊ�档

	// �����ͬһ����
	if (this->year == year) {
		return getDayOfYear() - date.getDayOfYear();
	}

	// ����ͬһ���У��ҵ�ǰ���ڴ��ڲ�������
	if (this->year > year) {
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
	for (int i = startDate->year + 1; i < endDate->year; i++)
		offsetDays += getYearDays(i);

	// �ټ��Ͻ�������ʱ�������Ѿ���������
	offsetDays += endDate->getDayOfYear();

	// ��������򣬷��ظ���
	if (ascent)
		return 0 - offsetDays;
	// ����ǽ���
	else
		return offsetDays;
}

class Employee {
public:
	Employee(const string, const string, const Date &, const Date &);
	void print() const;
	const Date & getHireDate() const;

	// ����Ա���ڲ���ָ��������ʱ����������
	int getAge(const Date& date) const;

	// �����Ա���������˶�����
	int getYearsWorked(const Date& date) const;
	// �����Ա�������˶�����
	int getDaysWorked(const Date& date) const;

	/* ����: employees[]�ǹ�Ա��������飻n�ǹ�Ա���������Ԫ�ظ���
	 * ����ֵ: ����������Ĺ�Ա��������� */
	static const Employee & getMostFaith(const Employee employees[], int n);

private:
	string firstName;
	string lastName;
	const Date birthDate; // composition: member object
	const Date hireDate;
};

Employee::Employee(const string first, const string last, const Date &dateOfBirth, const Date &dateOfHire) :
		firstName(first), lastName(last), birthDate(dateOfBirth), hireDate(dateOfHire) {
}

void Employee::print() const {
	cout << firstName << " " << lastName
			<< ", hire date: " << hireDate
			<< ", birthday: " << birthDate << endl;
}

const Date & Employee::getHireDate() const {
	return hireDate;
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

const Employee & Employee::getMostFaith(const Employee employees[], int n) {
	int index = 0;
	for (int i = 1; i < n; i++) {
		if (employees[index].getHireDate() > employees[i].getHireDate())
			index = i;
	}

	return employees[index];
}


int main() {
	const Employee employees[5] = {
			Employee("Pat",  "Hingle", Date(1965, 5, 11), Date(1998, 4, 17)),
			Employee("David", "Hodges", Date(1967, 7, 21), Date(1997, 5, 12)),
			Employee("Christian", "Bale", Date(1969, 8, 3), Date(1995, 12, 1)),
			Employee("Gus", "Lewis", Date(1970, 3, 1), Date(2000, 3, 7)),
			Employee("Aaron", "Eckhart", Date(1968, 4, 23), Date(1994, 10, 30))
	};

	const Employee & employee = Employee::getMostFaith(employees, 5);
	cout << "����������Ĺ�Ա����Ϣ���£�" << endl;
	employee.print();

	return 0;
}
