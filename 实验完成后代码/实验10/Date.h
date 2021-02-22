#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date{
public:
    Date(int year = 1990, int month = 1, int day = 1) :
            year(year),month(month),day(day),separator('-') {
    }
    void printFullYear();
    bool operator >(Date &date);
    ~Date() {}
private:
    int year;
    int month;
    int day;
    char separator;
};

bool Date::operator >(Date &date) {
    if ((year > date.year) || (year == date.year && month > date.month) || (year == date.year && month == date.month && day > date.day))
        return true;
    else
        return false;
}

#endif // DATE_H_INCLUDED
