#ifndef EMPLOYEE_SALARIED_H
#define EMPLOYEE_SALARIED_H

#include "employee.h"

class Employee_Salaried : public Employee
{
public:
    Employee_Salaried(std::string name, unsigned id, double salary)
        : Employee(name, id)
    {
        m_salary = salary;
    }
    double calc_pay() const override
    {
        return m_salary;
    }
    void print() const
    {
        std::cout << get_name() << ", id: " << get_id() << " earning " << m_salary << " per week" << std::endl;
    }

private:
    double m_salary;
};

#endif