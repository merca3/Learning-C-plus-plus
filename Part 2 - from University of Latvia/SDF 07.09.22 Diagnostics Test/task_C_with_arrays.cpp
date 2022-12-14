// C. Given two integer arrays of the same length. Write a C++ program to determine,
// whether at each position the element of A is bigger than corresponding element of B.
// Example #1. A={11,22,33},B={1,2,3}. Answer: yes. Example #2. A={11,22,33},B={1,2,40}. Answer: no.

#include <iostream>

using namespace std;

void getBigger(int arr1[], int arr2[], int length)
{
    string result = "Yes";
    for (int i = 0; i < length; ++i)
    {
        if (arr1[i] < arr2[i])
        {
            result = "No";
        }
    }
    cout << result << endl;
}

int main()
{
    int number1[3] = {11, 22, 33};
    int number2[3] = {1, 2, 3};

    int number3[3] = {11, 22, 33};
    int number4[3] = {1, 2, 40};

    getBigger(number1, number2, 3);
    getBigger(number3, number4, 3);
}
