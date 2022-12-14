#include <iostream>
#include <iomanip>
#include "date.h"

using namespace std;

Date::Date(int y, int m, int d) : m_year{y}, m_month{m}, m_day{d} {}

int Date::year() const { return m_year; }
int Date::month() const { return m_month; }
int Date::day() const { return m_day; }

void Date::print() const
{
    cout << m_year << "/" << setw(2) << setfill('0') << m_month << "/" << setw(2) << setfill('0') << m_day << endl;
}

ostream &operator<<(ostream &out, const Date &d)
{
    out << d.year() << "/" << setw(2) << setfill('0') << d.month() << "/" << setw(2) << setfill('0') << d.day();
    return out;
}

void Date::add_day()
{
    static const int month_days[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (m_day == month_days[m_month])
    {
        m_day = 1;
        if (m_month == 12)
        {
            m_month = 1;
            ++m_year;
        }
        else
            ++m_month;
    }
    else
        ++m_day;
}

void Date::add_days(int n)
{
    for (int i{0}; i < n; ++i)
        add_day();
}
