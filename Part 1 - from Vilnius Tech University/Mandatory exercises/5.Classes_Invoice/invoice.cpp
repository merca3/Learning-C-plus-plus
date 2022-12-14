#include <iostream>
#include <iomanip>
#include "invoice.h"

using namespace std;

Invoice::Invoice(string id, string description, int amount, int price)
{
    m_id = id;
    m_description = description;
    if (amount < 0)
    {
        m_amount = 0;
    }
    else
    {
        m_amount = amount;
    };
    if (price < 0)
    {
        m_price = 0;
    }
    else
    {
        m_price = price;
    };
}

string Invoice::showId() { return m_id; };
string Invoice::showDescription() { return m_description; };
int Invoice::showAmount() { return m_amount; };
int Invoice::showPrice() { return m_price; };

int Invoice::getInvoiceAmount() { return m_price * m_amount; };