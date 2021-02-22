#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date {
	friend istream & operator>>(istream &, Date &);
	friend ostream & operator<<(ostream &, const Date &);
public:
	// Ĭ�Ϲ��캯������fullyear����ʽ���������գ�
	// Ĭ��ֵΪ1900��1��1��
	// ͬʱ�������ڷָ���Ϊ��-��
	Date(int = 1900, int = 1, int = 1);

/// ���á���ȡ����///
	// �������ڣ�����зǷ����»��գ�������Ϊ
	void setDate(int, int , int);
	void setYear(int);
	int getYear() const;
	void setMonth(int);
	int getMonth() const;
	void setDay(int);
	int getDay() const;
	void setSeparator(char);
	char getSeparator() const;

/// ���������ʹ��setfill��setw ///
	void printFullYear() const;	// ��YYYY-MM-DD����ʽ��ӡ������2010-01-08
	void printStandardYear() const;	// ��YY-MM-DD����ʽ��ӡ������2010-01-08

///  ���㺯��  ///
	// ���㵱ǰ�������������֮���������꣬ע�����Ϊ���ڶ��������
	int fullYearsTo(const Date& date) const; 

	// ���㵱ǰ���ڱȲ����������˶�����(��������)����������������ڵ�ǰ���ڣ����ظ�����ע�����Ϊ���ڶ�������á�
	int operator-(const Date& date) const;	
	// ���㵱ǰ�����Ǳ���ĵڼ���
	int getDayOfYear() const;
	
	// ���㵱ǰ���ھ౾��������м��졣��������ǰ������һ��
	int getLeftDaysYear() const;

private:
	int year;
	int month;
	int day;
	char separator;						// ���ڷָ���
	static const int daysPerMonth[12];	// ������̬��������ÿ�µ���������.cpp�ļ��ж��岢��ʼ��
	int checkDay( int ) const;			// ��������£��жϲ��������Ƿ�Ϸ���
	bool isLeapyear( int ) const;		// �жϲ������Ƿ������ꡣ
	int getYearDays( int ) const;		// ����������ж�����
};

#endif