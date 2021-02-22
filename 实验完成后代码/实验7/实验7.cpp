#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Date{
public:
    Date(int newY=1990,int newM=1,int newD=1);
    void setDate(int newyear,int newmonth,int newday);
    void setSeparator(char separator);
    int daysTo(Date &date);
    void printFullYear();
    int operator-(Date &date);
    int operator>(Date &date);
    int display();
private:
    int year;
    int month;
    int day;
    char separator;
    int result;
};

void Date::printFullYear(){
    cout << year <<separator<<setw(2)<<setfill('0')<< month <<separator<<setw(2)<<setfill('0')<< day ;
    cout <<endl;
}

int Date::daysTo(Date &date){
    int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int b[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int result=0;
	int i,j;
	if(date.year==year)
    {
        if((date.year%4==0&&date.year%100!=0)||(date.year%100==0&&date.year%400==0))
        {
            for(i=0;i<date.month;i++)
            {
                result=result+b[i];
            }
            for(i=0;i<month;i++)
            {
                result=result-b[i];
            }
            result=result-date.day+day;
        }
        else
        {
            for(int i=0;i<date.month;i++)
            {
                result=result+a[i];
            }
            for(int i=0;i<month;i++)
            {
                result=result-a[i];
            }
            result=result-date.day+day;
        }
    }
    if(date.year>year)
    {
        for(i=year;i<date.year;i++)
        {
            if((i%4==0&&i%100!=0)||(i%100==0&&i%400==0))
            {
                for(j=0;j<12;j++)
                {
                    result=result+b[j];
                }
            }
            else
            {
                for(j=0;j<12;j++)
                {
                    result=result+a[j];
                }
            }
        }
         //2010/1/1--2010/4/15
        if((i%4==0&&i%100!=0)||(i%100==0&&i%400==0))
        {
            for(j=0;j+1<date.month;j++)
            {
                result=result+b[j];
            }
        }
        else
        {
            for(j=0;j+1<date.month;j++)
            {
                result=result+a[j];
            }
        }
        if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))//1969/1/1--1969/8/11
        {
            for(j=0;j+1<month;j++)
            {
                result=result-b[j];
            }
        }
        else
        {
            for(j=0;j+1<month;j++)
            {
                result=result-a[j];
            }
        }
        result=-(result+date.day-day);
    }
    if(date.year<year)
    {
        for(i=date.year;i<year;i++)
        {
            if((i%4==0&&i%100!=0)||(i%100==0&&i%400==0))
            {
                for(j=0;j<12;j++)
                {
                    result=result-b[j];
                }
            }
            else
            {
                for(j=0;j<12;j++)
                {
                    result=result-a[j];
                }
            }
        }
        if((date.year%4==0&&date.year%100!=0)||(date.year%100==0&&date.year%400==0))
        {
            for(j=0;j+1<date.month;j++)
            {
                result=result+b[j];
            }
        }
        else
        {
            for(j=0;j+1<date.month;j++)
            {
                result=result+a[j];
            }
        }
        if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))
        {
            for(j=0;j+1<month;j++)
            {
                result=result-b[j];
            }
        }
        else
        {
            for(j=0;j+1<month;j++)
            {
                result=result-a[j];
            }
        }
        result=-(result+date.day-day);
    }
    return (-result);
}


int Date::operator-(Date &date) {
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int b[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int result=0;
	int i,j;
	if(date.year==year)
    {
        if((date.year%4==0&&date.year%100!=0)||(date.year%100==0&&date.year%400==0))
        {
            for(i=0;i<date.month;i++)
            {
                result=result+b[i];
            }
            for(i=0;i<month;i++)
            {
                result=result-b[i];
            }
            result=result-date.day+day;
        }
        else
        {
            for(int i=0;i<date.month;i++)
            {
                result=result+a[i];
            }
            for(int i=0;i<month;i++)
            {
                result=result-a[i];
            }
            result=result-date.day+day;
        }
    }
    if(date.year>year)
    {
        for(i=year;i<date.year;i++)
        {
            if((i%4==0&&i%100!=0)||(i%100==0&&i%400==0))
            {
                for(j=0;j<12;j++)
                {
                    result=result+b[j];
                }
            }
            else
            {
                for(j=0;j<12;j++)
                {
                    result=result+a[j];
                }
            }
        }
         //2010/1/1--2010/4/15
        if((i%4==0&&i%100!=0)||(i%100==0&&i%400==0))
        {
            for(j=0;j+1<date.month;j++)
            {
                result=result+b[j];
            }
        }
        else
        {
            for(j=0;j+1<date.month;j++)
            {
                result=result+a[j];
            }
        }
        if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))//1969/1/1--1969/8/11
        {
            for(j=0;j+1<month;j++)
            {
                result=result-b[j];
            }
        }
        else
        {
            for(j=0;j+1<month;j++)
            {
                result=result-a[j];
            }
        }
        result=result+date.day-day;
    }
    if(date.year<year)
    {
        for(i=date.year;i<year;i++)
        {
            if((i%4==0&&i%100!=0)||(i%100==0&&i%400==0))
            {
                for(j=0;j<12;j++)
                {
                    result=result-b[j];
                }
            }
            else
            {
                for(j=0;j<12;j++)
                {
                    result=result-a[j];
                }
            }
        }
        if((date.year%4==0&&date.year%100!=0)||(date.year%100==0&&date.year%400==0))
        {
            for(j=0;j+1<date.month;j++)
            {
                result=result+b[j];
            }
        }
        else
        {
            for(j=0;j+1<date.month;j++)
            {
                result=result+a[j];
            }
        }
        if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))
        {
            for(j=0;j+1<month;j++)
            {
                result=result-b[j];
            }
        }
        else
        {
            for(j=0;j+1<month;j++)
            {
                result=result-a[j];
            }
        }
        result=result+date.day-day;
    }
    return result;
}

int Date::operator>(Date &date) {
	int a[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int b[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int result=0;
	int i,j;
	if(date.year==year)
    {
        if((date.year%4==0&&date.year%100!=0)||(date.year%100==0&&date.year%400==0))
        {
            for(i=0;i<date.month;i++)
            {
                result=result+b[i];
            }
            for(i=0;i<month;i++)
            {
                result=result-b[i];
            }
            result=result-date.day+day;
        }
        else
        {
            for(int i=0;i<date.month;i++)
            {
                result=result+a[i];
            }
            for(int i=0;i<month;i++)
            {
                result=result-a[i];
            }
            result=result-date.day+day;
        }
    }
    if(date.year>year)
    {
        for(i=year;i<date.year;i++)
        {
            if((i%4==0&&i%100!=0)||(i%100==0&&i%400==0))
            {
                for(j=0;j<12;j++)
                {
                    result=result+b[j];
                }
            }
            else
            {
                for(j=0;j<12;j++)
                {
                    result=result+a[j];
                }
            }
        }
         //2010/1/1--2010/4/15
        if((i%4==0&&i%100!=0)||(i%100==0&&i%400==0))
        {
            for(j=0;j+1<date.month;j++)
            {
                result=result+b[j];
            }
        }
        else
        {
            for(j=0;j+1<date.month;j++)
            {
                result=result+a[j];
            }
        }
        if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))//1969/1/1--1969/8/11
        {
            for(j=0;j+1<month;j++)
            {
                result=result-b[j];
            }
        }
        else
        {
            for(j=0;j+1<month;j++)
            {
                result=result-a[j];
            }
        }
        result=result+date.day-day;
    }
    if(date.year<year)
    {
        for(i=date.year;i<year;i++)
        {
            if((i%4==0&&i%100!=0)||(i%100==0&&i%400==0))
            {
                for(j=0;j<12;j++)
                {
                    result=result-b[j];
                }
            }
            else
            {
                for(j=0;j<12;j++)
                {
                    result=result-a[j];
                }
            }
        }
        if((date.year%4==0&&date.year%100!=0)||(date.year%100==0&&date.year%400==0))
        {
            for(j=0;j+1<date.month;j++)
            {
                result=result+b[j];
            }
        }
        else
        {
            for(j=0;j+1<date.month;j++)
            {
                result=result+a[j];
            }
        }
        if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0))
        {
            for(j=0;j+1<month;j++)
            {
                result=result-b[j];
            }
        }
        else
        {
            for(j=0;j+1<month;j++)
            {
                result=result-a[j];
            }
        }
        result=result+date.day-day;
    }
    return result>0?0:1;
}

Date::Date(int newY,int newM,int newD){
    year=newY;
    month=newM;
    day=newD;
    separator='-';
}

class Employee{
public:
    Employee(const string,const string,const Date date1,const Date date2);
    void print();
    static Employee getMostFaith(Employee employees[],int n);
    int getDayWorked(Date &date);
    ~Employee() {}
private:
    string firstName;
    string lastName;
    Date today;
    Date birthDate;
    Date hireDate;
};

Employee::Employee(const string s1,const string s2,const Date date1,const Date date2):birthDate(date1),hireDate(date2) {
    firstName=s1;
    lastName=s2;
    Date birthDate=date1;
    Date hireDate=date2;
}

int Employee::getDayWorked(Date &date)
{
    return hireDate.daysTo(date);
}

void Employee::print() {
    cout <<lastName<<","<<firstName<<" Hired:";
    hireDate.printFullYear();
    cout << " Birthday:";
    birthDate.printFullYear();
}


Employee Employee::getMostFaith(Employee employees[],int n) {
    Date birth(0000,00,00);
    Date today(1980,8,30);
    int i=0;
    Employee max1("faith","employee",birth,today);
    max1=employees[0];
    for(i=0;i<4;i++)
    {
        int key=employees[i].hireDate>employees[i+1].hireDate;
        if(key==0)
            max1=employees[i+1];
    }
    return max1;
}

int main () {
    Date birth(1949,10, 1);
    Date today(1980 , 8, 7);
    Date A(1980, 8, 5);
    Date B(1980, 8, 4);
    Date C(1980, 8, 3);
    Date D(1980, 8, 2);
    Date E(1980, 8, 1);
    Employee Jack("Cullen","Jack",birth,A);
    Employee Jasper("Cullen","Jasper",birth,B);
    Employee Tom("Cullen","Tom",birth,C);
    Employee Mark("Cullen","Mark",birth,D);
    Employee David("Cullen","David",birth,E);
    Employee M("EMPTY","EMPTY",birth,today);
    Employee employees[5]={Jack,Jasper,Tom,Mark,David};
    cout <<"打印所有雇员信息:"<<endl;
    for(int i=0;i<5;i++)
    {
        employees[i].print();
    }
    M=Employee::getMostFaith(employees,5);
    cout<<endl<<"其中工作年限最长的雇员为:"<<endl;
    M.print();
    cout<<"已工作"<<M.getDayWorked(today)<<"天.";

    return 0;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


