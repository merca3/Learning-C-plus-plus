#ifndef EMPLOYEE_HOURLY_H
#define EMPLOYEE_HOURLY_H

#include "employee.h"

class Employee_Hourly : public Employee
{
public:
    Employee_Hourly(std::string name, unsigned id, unsigned hours, double hourly_rate)
        : Employee(name, id)
    {
        m_hours = hours;
        m_hourly_rate = hourly_rate;
    }
    double calc_pay() const override
    {
        return m_hours * m_hourly_rate;
    }
    void print() const
    {
        std::cout << get_name() << ", id: " << get_id() << " working " << m_hours << " per week" << std::endl;
    }

private:
    unsigned m_hours;
    double m_hourly_rate;
};

#endif