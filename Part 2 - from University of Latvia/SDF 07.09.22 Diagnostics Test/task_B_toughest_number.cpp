// B. Write the C++ function and provide the context of how it is used (e.g., function call).
// Calculate, which of the two given natural numbers has both the biggest sum
// and (multiplication) product of the first and the last digits.
// (You can assume that for one-digit numbers, the only digit is both the first and the last one.)
// Example #1. Numbers=123,456. Output: “The number 456 is the toughest.”
// Example #2. Numbers =987,159. Output: “The number 987 is the toughest.”
// Example #3. Numbers = 44,951. Output: “None of 44 and 951 is tough enough.”

#include <iostream>

using namespace std;

int main()
{
    int num1, num2, last1, last2, first1, first2, sum1, sum2, mult1, mult2;

    cout << "Please enter first number: ";
    cin >> num1;
    last1 = num1;
    first1 = num1;

    cout << "Now please enter second number: ";
    cin >> num2;
    last2 = num2;
    first2 = num2;

    while (last1 > 9)
        last1 = last1 % 10;
    while (last2 > 9)
        last2 = last2 % 10;
    while (first1 >= 10)
        first1 = first1 / 10;
    while (first2 >= 10)
        first2 = first2 / 10;

    sum1 = last1 + first1;
    sum2 = last2 + first2;
    mult1 = last1 * first1;
    mult2 = last2 * first2;

    if (sum1 > sum2 && mult1 > mult2)
    {
        cout << "Number " << num1 << " is the toughest" << endl;
    }
    else if (sum1 > sum2 && mult1 < mult2)
    {
        cout << "None of " << num1 << " or " << num2 << " is tough enough" << endl;
    }
    else if (sum1 < sum2 && mult1 > mult2)
    {
        cout << "None of " << num1 << " or " << num2 << " is tough enough" << endl;
    }
    else
        cout << "Number " << num2 << " is tougher" << endl;
}
