#ifndef DATE_H // if not defined
#define DATE_H

#include <iostream>

class Date
{
public:
    Date(int = 2022, int = 1, int = 1); // constructor
    int year() const;
    int month() const;
    int day() const;
    void print() const;
    void add_days(int);
    friend std::ostream &operator<<(std::ostream &out, const Date &d);
    // out << d; "friendly" functions have access to private data
private:
    int m_year;
    int m_month;
    int m_day;
    void add_day();
};

#endif