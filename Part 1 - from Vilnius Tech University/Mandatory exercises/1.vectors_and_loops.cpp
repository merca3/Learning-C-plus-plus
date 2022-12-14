/******************************************************************************

Read a set of integers into a vector.
Print the sum of each pair of adjacent elements.
Change your program so that it prints the sum of the first and last elements,
followed by the sum of the second and second-to-last, and so on.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector intVector{2, 5, 3, 7, 1, 4};
    cout << "Integer vector equals to: { ";
    for (auto elem : intVector)
        cout << elem << " ";

    cout << "}" << endl;

    cout << "===========================================================" << endl;

    for (int i = 1; i < intVector.size(); ++i)
    {
        int sum = intVector.at(i - 1) + intVector.at(i);
        cout << "Sum of " << intVector.at(i - 1) << " and " << intVector.at(i) << " is: " << sum << endl;
    }

    cout << "===========================================================" << endl;

    for (int i = 1; i <= intVector.size() / 2; ++i)
    {
        int sum = intVector.at(i - 1) + intVector.at(intVector.size() - i);
        string text;
        if (i == 1)
        {
            text = "Sum of first and last element of integer vector is: ";
        };
        if (i == 2)
        {
            text = "Sum of second and second-to-last element of integer vector is: ";
        };
        if (i == 3)
        {
            text = "Sum of third and third-to-last element of integer vector is: ";
        };
        cout << text << sum << endl;
    }
}
