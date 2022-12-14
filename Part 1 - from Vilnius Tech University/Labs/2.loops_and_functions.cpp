#include <iostream>
#include <iomanip>

using namespace std;

int square(int); // function prototype - doesn't specify what
// the function does, but indicates how it looks (declaration)
int cube(int);

int main()
{
    int i{1};
    while (i <= 10)
    {
        // setw(number) - set width
        cout << setw(2) << i << ": " << setw(3) << square(i) << '\n';
        ++i;
    }
    for (int i = 1; i <= 10; ++i)
    {
        cout << setw(2) << i << ": " << setw(4) << cube(i) << '\n';
    }
}

int square(int x)
{
    return x * x;
}
int cube(int x)
{
    return x * x * x;
}
