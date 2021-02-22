#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date {
	friend istream & operator>>(istream &, Date &);
	friend ostream & operator<<(ostream &, const Date &);
public:
	// 默认构造函数，以fullyear的形式给出年月日，
	// 默认值为1900年1月1日
	// 同时设置日期分隔符为“-”
	Date(int = 1900, int = 1, int = 1);

/// 设置、获取函数///
	// 设置日期，如果有非法的月或日，将其置为
	void setDate(int, int , int);
	void setYear(int);
	int getYear() const;
	void setMonth(int);
	int getMonth() const;
	void setDay(int);
	int getDay() const;
	void setSeparator(char);
	char getSeparator() const;

/// 输出函数，使用setfill和setw ///
	void printFullYear() const;	// 以YYYY-MM-DD的形式打印，比如2010-01-08
	void printStandardYear() const;	// 以YY-MM-DD的形式打印，比如2010-01-08

///  计算函数  ///
	// 计算当前日期与参数日期之间相差几个整年，注意参数为日期对象的引用
	int fullYearsTo(const Date& date) const; 

	// 计算当前日期比参数日期晚了多少天(考虑闰年)。如果参数日期晚于当前日期，返回负数，注意参数为日期对象的引用。
	int operator-(const Date& date) const;	
	// 计算当前日期是本年的第几天
	int getDayOfYear() const;
	
	// 计算当前日期距本年结束还有几天。不包括当前日期这一天
	int getLeftDaysYear() const;

private:
	int year;
	int month;
	int day;
	char separator;						// 日期分隔符
	static const int daysPerMonth[12];	// 声明静态常变量，每月的天数。在.cpp文件中定义并初始化
	int checkDay( int ) const;			// 根据年和月，判断参数日期是否合法。
	bool isLeapyear( int ) const;		// 判断参数年是否是闰年。
	int getYearDays( int ) const;		// 计算参数年有多少天
};

#endif