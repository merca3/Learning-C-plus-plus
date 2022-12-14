/******************************************************************************
Create a class called Invoice that a hardware store might use to represent an invoice for an item sold at the store.
An Invoice should include four data members—a part number (type string) (in this example id), a part description (type string),
a quantity of the item being purchased (type int) and a price per item (type int).
Your class should have a constructor that initializes the four data members.
Provide a set and a get function for each data member. In addition, provide a member function
named getInvoiceAmount that calculates the invoice amount (i.e., multiplies the quantity by the price per item),
then returns the amount as an int value. If the quantity is not positive, it should be set to 0.
If the price per item is not positive, it should be set to 0.
Write a test program that demonstrates class Invoice’s capabilities.
*******************************************************************************/
#include <iostream>
#include "invoice.h"

using namespace std;

int main()
{
    Invoice invoice1{"id123", "Item 1", 3, 50};
    cout << "ID of " << invoice1.showDescription() << " is: " << invoice1.showId() << endl;
    cout << "Amount of " << invoice1.showDescription() << " is: " << invoice1.showAmount() << endl;
    cout << "Price of " << invoice1.showDescription() << " is: " << invoice1.showPrice() << "$" << endl;
    cout << "The invoice amount of is: " << invoice1.getInvoiceAmount() << "$" << endl;
}