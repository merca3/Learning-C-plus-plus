/******************************************************************************
===  B15  =======================================
Create program in C++ by making use of described or other functions. See published detailed requirements.

B15. Given natural number n and n natural numbers a(1..n) (n<100). Print on screen all mutual prime number pairs.
Use function to check - are two numbers mutual prime numbers.
First input must determine how many numbers to input.
You must find mutual prime pairs from entered numbers.
Also required function to check - are two numbers mutual prime numbers – is not realized.
*******************************************************************************/

/**
 Test 1: input = -2; output: "Please enter a number equal or bigger than 1"

 Test 2: input = 100; output: "Please enter a number smaller than 100"

 Test 3: input = 0; output: "Thanks for checking and - have a nice day!"

 Test 4: input amount = 1, input number = any; output: "Mutual prime numbers are: *** none *** "

 Test 5: input = 3, input numbers = 5, 6, 7; output: "5 and 6, 5 and 7, 6 and 7" (each pair on new line)

 Test 6: input = 3, input numbers = 22, 44, 66; output: "Mutual prime numbers are: *** none *** "

 Test 7: input = 4, input numbers = 25, 36, 72, -2; output: "25 and 36, 25 and 72, 25 and -2" (each pair on new line)

 Test 8: input = 7, input numbers = 1, 2, 3, 4, 5, 6, 7;
            output: "2 and 3, 2 and 5, 2 and 7, 3 and 4, 3 and 5, 3 and 7, 4 and 5, 4 and 7, 5 and 6, 5 and 7, 6 and 7"
            (each pair on new line)

 Test 9: input = 3, input numbers = 5, 0, 7; output: "5 and 7"
**/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Function to check and print mutual prime number pair
bool isPrimeNumberPair(int a, int b)
{

    // Using inbuilt function to find greatest common divisor
    int gcd = __gcd(a, b);

    // print the pair if gcd is 1 and numbers are not equal to 1
    if (gcd == 1 && a != 1 && b != 1)
    {
        cout << a << " and " << b << endl;
        return true;
    }

    return false; // not prime
};

// Function to check if amount input number belong to interval from 1 to 100
bool isValidAmount(int x)
{
    if (x < 1)
    {
        cout << "Please enter a number equal or bigger than 1" << endl;
        return false;
    }
    if (x > 99)
    {
        cout << "Please enter a number smaller than 100" << endl;
        return false;
    }
    return true;
}

int main()
{
    int inputAmount;

    do
    {
        cout << "(To quit, enter 0)" << endl;
        cout << "Enter amount of numbers to check: ";
        cin >> inputAmount;
        cout << "---------------------------------------------" << endl;

        // No need to validate if input is 0 (meant for exiting program)
        if (inputAmount != 0)
        {
            if (isValidAmount(inputAmount))
            { // doing all the logic only if valid input for number amount

                vector<int> numbers = {}; // vector to gather input numbers

                cout << "Enter numbers to check: " << endl;
                for (int i = 0; i < inputAmount; ++i)
                {
                    int inputNum;
                    cin >> inputNum;
                    numbers.push_back(inputNum); // collect input numbers in vector
                };
                cout << endl;

                int gcdAmount = 0; // needed to display "*** none ***" if there are no mutual prime number pairs

                cout << "Mutual prime numbers are: " << endl;
                for (int i = 0; i < inputAmount; ++i)
                {

                    // this i+1 added to avoid repetition of same numbers, like "2 and 5" and "5 and 2"
                    for (int j = i + 1; j < inputAmount; ++j)
                    {
                        isPrimeNumberPair(numbers.at(i), numbers.at(j)) && ++gcdAmount;
                    }
                }
                gcdAmount == 0 && cout << "*** none ***" << endl;
            };
            cout << "---------------------------------------------" << endl;
            cout << endl;
        };

    } while (inputAmount != 0);

    cout << "Thanks for checking and - have a nice day!" << endl;

    return 0;
}
