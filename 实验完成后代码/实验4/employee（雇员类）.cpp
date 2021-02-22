#include<iostream>
#include<iomanip>
using namespace std;

class Date{
public:
    Date(int year = 1990, int month = 1, int day = 1){
        this->year = year;
        this->month = month;
        this->day =day;
        separator = '-';
    }

    /* 设置接口 */
    // 设置日期，如果有非法的月或日，将其置为1
    void setDate(int year, int month, int day);
    void setYear(int year);
    int getYear() {return year;}
    void setMonth(int month);
    int getMonth() {return month;}
    void setDay(int month);
    int getDay() {return day;}
    void setSeparator(char separator) {
        this->separator = separator;
    }

    int leapyear(int year);

    /* 输出函数，请使用setfill(‘0’)和setw(2) */
    void printFullYear();     // 以YYYY-MM-DD的形式打印，2011-01-08
    void printStandardYear(); // 以YY-MM-DD的形式打印，比如11-01-08
    /*  计算函数  */
    int fullYearsTo(Date &date);
    /* 计算当前日期与参数日期之间相差多少天 */
    int daysTo(Date &date);
private:
    int year;
    int month;
    int day;
    char separator;  // 日期分隔符
};
class Employee{
public:
    Employee(const string firstN, const string lastN, const Date &bir, const Date &hire){
        firstName = firstN;
        lastName = lastN;
        birthDate = bir;
        hireDate = hire;
    }
    void print() {
    	cout<<lastName<<","<<firstName<<endl;
        cout<<"Hired:"; hireDate.printFullYear();
        cout << "Birthday:"; birthDate.printFullYear();
        cout << endl;
    }
    int getAge (Date &date){return birthDate.fullYearsTo(date);}
    int getYearsWorked (Date &date){return hireDate.fullYearsTo(date);}
    int getDaysWorked (Date &date){return hireDate.daysTo(date);}
private:
    string firstName;
    string lastName;
    Date birthDate;
    Date hireDate;
};
int Date::leapyear(int year){
    int leap = 0;
    if (year % 4 == 0&&year % 100 != 0||year %400 == 0) leap = 1;
    return leap;
}

void Date::setDate(int year, int month, int day){
    if (month == 2){
        int Day = 28;
        if (leapyear(year)) Day++;
        if (day < 1||day > Day) day = 1;
    }
    else if (month < 13&&month >0){
        int Day = 30;
        if (month < 8&&month % 2 == 1||month >7&& month % 2 == 0) Day++;
        if(day < 1|| day > Day) day = 1;
    }
    else month = 1;
    this->year = year;
    this->month = month;
    this->day = day;
}

void Date::setYear(int year) {
    this->year = year;
}

void Date::setMonth(int month) {
    if (month < 1 || month > 12) month = 1;
}

void Date::setDay(int day) {
    setDate(year, month, day);
}

void Date::printFullYear() {
    cout<<year<<separator<<setw(2)<<setfill('0')<<month<<separator<<setw(2)<<setfill('0')<<day<<endl;
}

void Date::printStandardYear() {
    cout<<year % 100<<'-'<<setw(2)<<setfill('0')<<month<<'-'<<setw(2)<<setfill('0')<<day;
}

int Date::fullYearsTo(Date &date){
    if (date.getMonth() < month || date.getMonth() == month && date.getDay() < day) return (date.getYear() - year - 1);
    else return (date.getYear() - year);
}

int Date::daysTo( Date &date) {
    int days0 = 0, days = 0, j = 0, flag = 0;
    const int Month[][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};

    flag = leapyear(date.getYear());
    for (j = 1; j <= date.getYear(); j++)
        days0 += leapyear(j) ? 366 : 365;
    for (int i = 1; i < date.getMonth(); i++)
        days0 += Month[flag][i];
    days0 += date.getDay();

    flag = leapyear(year);
    for (j = 1; j <= year; j++)
        days += leapyear(j) ? 366 : 365;
    for (int i = 1; i < month; i++)
        days += Month[flag][i];
    days += day;
    return days0 - days;
}

int main(){
   Date birth(1969, 8, 11);
   Date hire(1998, 4, 1);
   Date today(2010, 4, 30);
   Employee manager("Bob", "Blue", birth, hire);
   cout <<endl;
   manager.print();
   cout << endl;
   cout <<"工作满了" <<manager.getAge(today)<<"年"<< endl;
   cout <<"已工作了"<<manager.getDaysWorked(today)<<"天"<< endl;
}
