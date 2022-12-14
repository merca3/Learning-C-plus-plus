// A. Given integer number N. Write a C++ program to calculate the category
// this number belongs to: (A) working day (1..5), (B) holiday (6..7), (C) other.
// Example #1. N=3; output=A. Example #2. N=-90; output: C. Example #3. N=7; output: B.

#include <iostream>

using namespace std;

int main()
{
    cout << "Enter the number of the day to check it's type: " << endl;

    int day;
    cin >> day;

    if (day > 0 && day < 6)
    {
        cout << "A - Working day" << endl;
    }

    if (day >= 6 && day <= 7)
    {
        cout << "B - Holiday" << endl;
    }

    if (day <= 0 || day > 7)
    {
        cout << "C - other" << endl;
    }
}
