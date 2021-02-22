#include<iostream>
using namespace std;
class Date{
public:
	Date(int year = 1990, int month = 1,int day =1);
	/*void setDate(int year, int month, int day);
	void setYear(int year);
	int getYear();
	void setMonth(int month);
	void setDay(int day);*/
	void setSeparator(char separator);
	void printFullYear();
	void printStandardYear();
	int fullYearTo(int year, int month, int day);
	int daysTo(int year, int month, int day);
private:
	int year;
	int month;
	int day;
	char separator;   
};
Date::Date(int a, int b,int c){
	year=a;
	month=b;
	day=c;
}
void Date::printFullYear(){
	cout << year <<"-" << month << "-" << day << endl;
}
void Date::printStandardYear(){
	cout << year%100 <<"-" << month << "-" << day << endl;
}
void Date::setSeparator(char separator){
    cout << year <<separator << month << separator << day << endl;
}
int Date::fullYearTo(int a, int b, int c){
	int gap;
	gap=a-year;
	if(b<month) gap--;
	else if(b=month) {
		if(c<day) gap--;
	}  
	return gap;
}
int Date::daysTo(int Newyear, int Newmonth, int Newday){
		int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		int b[12]={31,29,31,30,31,30,31,31,30,31,30,31};
		int i;
		int flag = 0;
		int sub = 0;
		int result = 0;
		if (Newyear > year){
			if((Newyear%4==0&&Newyear%100!=0)||(Newyear%100==0&&Newyear%400==0)){
				for(i=0;i+1<Newmonth;i++)
					result+=b[i];
			}
			else{
				for(i=0;i+1<Newmonth;i++)
					result+=a[i];
			}
			result += Newday;
			for (Newyear -= 1; Newyear > year; Newyear--){
				if((Newyear%4==0&&Newyear%100!=0)||(Newyear%100==0&&Newyear%400==0)){
					result += 366;
				}
				else
					result += 365;
			}
			if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0)){
				for(i=0;i+1<month;i++)
					sub+=b[i];
				flag = 1;
			}
			else{
				for(i=0;i+1<month;i++)
					sub+=a[i];
			}
			sub += day;
			if(flag)
				sub = 366 - sub;
			else
				sub = 365 - sub;
			result += sub;
			return result;
		}
		else{
			if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0)){
				for(i=0;i+1<month;i++)
					result+=b[i];
			}
			else{
				for(i=0;i+1<month;i++)
					result+=a[i];
			}
			result += day;
			for (year -= 1; year > Newyear; year--){
				if((year%4==0&&year%100!=0)||(year%100==0&&year%400==0)){
					result += 366;
				}
				else
					result += 365;
			}
			if((Newyear%4==0&&Newyear%100!=0)||(Newyear%100==0&&Newyear%400==0)){
				for(i=0;i+1<Newmonth;i++)
					sub+=b[i];
				flag = 1;
			}
			else{
				for(i=0;i+1<Newmonth;i++)
					sub+=a[i];
			}
			sub += Newday;
			if(flag)
				sub = 366 - sub;
			else
				sub = 365 - sub;
			result += sub;
			year = 1969;
			return -result;
		}
}
int main(){
	Date birthDate(1969, 8, 11);
	birthDate.printFullYear();
	birthDate.printStandardYear();
	birthDate.setSeparator('/');
	//birthDate.printFullYear();
	cout << birthDate.fullYearTo(2010,4,15) << ",满" <<birthDate.fullYearTo(2010,4,15)<<"岁" <<endl;
	cout << birthDate.daysTo(2010,4,15) << ",活了" << birthDate.daysTo(2010,4,15) << "天" << endl;
	cout << birthDate.daysTo(1949,10,1) << ",共和国比我早诞生了" << -birthDate.daysTo(1949,10,1) << "天" << endl;
}
