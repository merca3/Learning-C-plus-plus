#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector iv{1, 2, 5, 1, 6};
    for (auto elem : iv)
        cout << elem << endl;

    cout << "========" << endl;

    sort(iv.begin(), iv.end());
    for (auto elem : iv)
        cout << elem << endl;

    int sum = 0;
    for (int i = 0; i < iv.size(); ++i)
    {
        cout << iv.at(i) << endl;
        if (i % 2 == 1)
            sum += iv.at(i);
    }
    cout << "Sum of odd indices: " << sum << endl;

    cout << "Size of iv: " << iv.size() << endl;
    cout << iv.capacity() << endl;

    cout << endl;

    cout << 5 / 2 << endl; // integer division produces just the integer part of answer
    cout << 5 % 2 << endl; // modulus: produces a remainder

    if (5 % 2 == 1)
        cout << "5 is odd";
}
