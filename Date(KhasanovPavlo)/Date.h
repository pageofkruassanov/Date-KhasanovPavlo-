#pragma once
#include <iostream>

using namespace std;
class Date
{
private:
	unsigned int year;
	unsigned int month;
	unsigned int day;
	
	int getYear();

	int getMonth();

	int getDay();

	bool isLeapYear(int year);

	int daysInMonth(int month, int year);

	void increaseMonth();

	bool isValidDate();

	void decreaseMonth();
public:
	explicit Date(unsigned int year, unsigned int month, unsigned int day) : year(year), month(month), day(day) {};

	void increaseDay();

	void decreaseDay();

	Date& operator++();

	Date operator++(int);

	Date& operator-(Date& d);
	
	Date& operator=(Date& d);

	bool operator!=(const Date& d) const;

	bool operator== (const Date& d) const;

	bool operator>(const Date& d) const;

	bool operator<(const Date& d) const;

	Date& operator+=(Date& d);

	Date& operator-=(Date& d);

	Date& operator()(unsigned int year, unsigned int month, unsigned int day);

	friend ostream& operator<<(ostream& out, Date& d);

	friend istream& operator>>(istream& in, Date& d);
};

