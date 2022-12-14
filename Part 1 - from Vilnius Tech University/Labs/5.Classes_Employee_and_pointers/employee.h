#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Employee
{
public:
    Employee(std::string name, unsigned id)
    {
        m_name = name;
        m_id = id;
    }
    // : m_name{name}, m_id{id} { } // initializer list, same as above
    virtual double calc_pay() const = 0; // pure virtual function (completely abstract)
    void print() const
    {
        std::cout << m_name << ", id: " << m_id << std::endl;
    }
    std::string get_name() const
    {
        return m_name;
    }
    unsigned get_id() const
    {
        return m_id;
    }

private:
    std::string m_name;
    unsigned m_id;
};

#endif