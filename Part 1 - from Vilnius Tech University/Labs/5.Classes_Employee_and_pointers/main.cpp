#include <iostream>
#include <vector>
// #include "employee.h"
#include "employee_hourly.h"
#include "employee_salaried.h"

using namespace std;

double calculate_pay(const vector<Employee *> &ev)
{
    double sum{0.0};
    for (auto *emp : ev)
        sum += emp->calc_pay(); // special syntax to access thing via pointers ->
    return sum;
}

int main()
{
    // Employee e1{"John", 156}; can't create object out of an abstract data type Employee
    Employee_Hourly eh{"Mark", 100, 40, 15};
    Employee_Salaried es{"Luke", 101, 1500};

    vector<Employee *> ve; // vector of pointers to Employee
    ve.push_back(&eh);
    ve.push_back(&es);
    cout << calculate_pay(ve) << endl;

    Employee &emp_ref_h = eh;
    Employee &emp_ref_s = es;
    eh.print();
    es.print();

    Employee *ptr_h = &eh;
    Employee *pth_s = &es;
    ptr_h->print();
    pth_s->print();
}
