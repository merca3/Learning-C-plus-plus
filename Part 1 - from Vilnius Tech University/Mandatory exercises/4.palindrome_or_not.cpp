/******************************************************************************
Write a program that uses the vector and checks whether the vector contains a palindrome,
i.e. whether the vector does or does not read the same forward as backward
(e.g., a vector containing 1, 2, 3, 2, 1 is a palindrome, but a vector containing 1, 2, 3, 4 is not).
*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector x = {"a", "b", "c", "d", "a"};

    cout << "The vector x = { ";
    for (auto elem : x)
        cout << elem << " ";
    cout << "}" << endl;

    int xlength = x.size();
    bool isPalindrome = true;

    for (int i = 0; i < xlength; ++i)
    {
        if (x.at(i) != x.at(xlength - 1 - i))
        {
            isPalindrome = false;
        }
    }
    if (isPalindrome == true)
        cout << "Vector x IS a palindrome" << endl;

    if (isPalindrome == false)
        cout << "Vector x is NOT a palindrome" << endl;
}
