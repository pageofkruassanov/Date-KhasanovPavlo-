#include "Date.h"

int Date::getYear()
{
    return this->year;
}

int Date::getMonth()
{
    return this->month;
}

int Date::getDay()
{
    return this->day;
}

bool Date::isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::daysInMonth(int month, int year)
{
    const int daysPerMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int days = daysPerMonth[month - 1];

    if (month == 2 && isLeapYear(year))
        days++;

    return days;
}

void Date::increaseMonth()
{
    month++;
    if (month > 12) {
        month = 1;
        year++;
    }
}

bool Date::isValidDate()
{
    if (month < 1 || month > 12)
        return false;

    int maxDay = daysInMonth(month, year);
    return (day >= 1 && day <= maxDay);
}
void Date::decreaseMonth()
{
    month--;
    if (month < 1) {
        month = 12;
        year--;
    }
}
void Date::increaseDay()
{
    day++;
    if (!isValidDate()) {
        day = 1;
        increaseMonth();
    }
}

void Date::decreaseDay()
{
    day--;
    if (day < 1) {
        decreaseMonth();
        day = daysInMonth(month, year);
    }
}

Date& Date::operator++()
{
    this->increaseDay();
    return *this;
}

Date Date::operator++(int)
{
    Date tempDate = *this;
    this->increaseDay();
    return tempDate;
}

Date& Date::operator-(Date& d)
{
    Date tempDate = *this;

    if (tempDate.year >= d.year)
        tempDate.year -= d.year;
    else {
        if (tempDate.month > d.month)
            tempDate.year = 0;
        else
            tempDate.year = 1;
    }
    for (int i = 0; i < d.month; i++)
        tempDate.decreaseMonth();
    for (int i = 0; i < d.day; i++)
        tempDate.decreaseDay();
    return tempDate;
}

Date& Date::operator=(Date& d)
{
    this->day = d.day;
    this->month = d.month;
    this->year = d.year;
    return *this;
}

bool Date::operator!=(const Date& d) const
{
    if (this->day != d.day)
        return true;
    if (this->month != d.month)
        return true;
    if (this->year != d.year)
        return true;
    return false;
}

bool Date::operator==(const Date& d) const
{
    if (this->day != d.day)
        return false;
    if (this->month != d.month)
        return false;
    if (this->year != d.year)
        return false;
    return true;
}

bool Date::operator>(const Date& d) const
{
    if (this->year > d.year)
        return true;
    if (this->month > d.month && this->year >= d.year)
        return true;
    if (this->day > d.day && this->month >= d.month && this->year >= d.year)
        return true;
    return false;
}

bool Date::operator<(const Date& d) const
{
    if (this->year < d.year)
        return true;
    if (this->month < d.month && this->year <= d.year)
        return true;
    if (this->day < d.day && this->month <= d.month && this->year <= d.year)
        return true;
    return false;
}

Date& Date::operator+=(Date& d)
{
    this->year += d.year;

    for (int i = 0; i < d.month; i++)
        this->increaseMonth();

    for (int i = 0; i < d.day; i++)
        this->increaseDay();

    return *this;
        
}

Date& Date::operator-=(Date& d)
{
    if (this->year > d.year)
        this->year -= d.year;
    else
        this->year = 1;

    for (int i = 0; i < d.month; i++)
        this->decreaseMonth();

    for (int i = 0; i < d.day; i++)
        this->decreaseDay();

    return *this;
}

Date& Date::operator()(unsigned int year, unsigned int month, unsigned int day)
{
    this->year = year;
    this->month = month;
    this->day = day;

    return *this;
}
