#ifndef INVOICE_H
#define INVOICE_H

#include <iostream>
#include <iomanip>

using namespace std;

class Invoice
{
public:
    Invoice(string = "", string = "", int = 0, int = 0);
    string showId();
    string showDescription();
    int showAmount();
    int showPrice();
    int getInvoiceAmount();

private:
    string m_id;
    string m_description;
    int m_amount;
    int m_price;
};

#endif