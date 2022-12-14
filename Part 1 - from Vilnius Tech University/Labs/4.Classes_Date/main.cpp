#include <iostream>
#include "date.h"

using namespace std;

int main()
{
    Date d{2022, 3, 8};
    // Date d;
    cout << d.year() << "/";
    cout << d.month() << "/";
    cout << d.day() << endl;
    d.print();
    cout << d << endl;

    Date dd{2021, 12, 31};
    cout << "Initial: " << dd << endl;
    dd.add_days(32);
    cout << "32 days added: " << dd << endl;
}
