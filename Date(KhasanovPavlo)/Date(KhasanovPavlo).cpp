#include "Date.h"

int main()
{
    Date d1(2023, 1, 2);
    Date d2(1, 1, 1);
    d2 = d1;
    cout << d1;
    cin >> d2;
    cout << d2;

    cout << endl << (d1 > d2) << endl;
    cout << endl << (d1 == d2) << endl;
    cout << endl << (d1 != d2) << endl;
    cout << endl << (d1 < d2) << endl;

    Date d3(100, 5, 30);
    cout << endl << endl;
    Date d4 = d1 - d3;
    cout << d4;
    d1 += d3;
    cout << d1;
    d1 -= d3;
    cout << d1;
    d1(2023, 1, 2);
    cout << d1;

}

