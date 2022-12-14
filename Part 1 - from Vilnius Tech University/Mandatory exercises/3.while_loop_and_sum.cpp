/******************************************************************************
Write a program that uses a while to sum the even numbers from 50 to 100.
*******************************************************************************/
#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    int i = 50;

    while (i <= 100)
    {
        if (i % 2 == 0)
        {
            sum += i;
        }
        ++i;
    }

    cout << "The sum of even numbers from 50 to 100 in while loop is: " << sum << endl;
}
