/******************************************************************************

B. Write C++ function to process sequence of integer values of type list<int>.
B1[7]. Function incOddBeforeEven, which increases by 1 any odd element located right before an even.
E.g., {-2,3,-7,-4,5,10}→{-2,3,-6,-4,6,10}
B2[11]. Function deleteFirstTwoAdjacentOdds, which removes from the list the first two adjacent elements,
which are odds. E.g. {1,3,5,3,1,4}→{5,3,1,4}; {4,9,7,5,6,7}→{4,5,6,7}; {1,2,3,4,5}→{1,2,3,4,5} (nothing
deleted).

*******************************************************************************/
#include <iostream>
#include <list>

using namespace std;

void print(list<int> &aa)
{
    auto i = aa.begin();
    while (i != aa.end())
    {
        cout << *i << " ";
        i++;
    }
    cout << endl;
};

void incOddBeforeEven(list<int> &aa)
{
    auto i = aa.begin();
    while (i != aa.end())
    {
        auto k = i;
        k++;
        if (*i % 2 != 0 && k != aa.end() and *k % 2 == 0)
        {
            *i += 1;
        }
        i++;
    }
}

int main()
{
    list<int> aa = {-2, 3, -7, -4, 5, 10};
    print(aa);
    incOddBeforeEven(aa);
    print(aa);
}
