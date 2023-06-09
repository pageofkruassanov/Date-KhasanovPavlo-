#include "datefunc.h"

ostream& operator<<(ostream& out, Date& d)
{
	out << "Year: " << d.year << endl;
	out << "Month: " << d.month << endl;
	out << "Day: " << d.day << endl;

	return out;
}

istream& operator>>(istream& in, Date& d)
{
	cout << "Input year (>0): ";
	in >> d.year;

	cout << "Input month(1-12): ";
	in >> d.month;

	cout << "Input day(1-31): ";
	in >> d.day;

	return in;
}
