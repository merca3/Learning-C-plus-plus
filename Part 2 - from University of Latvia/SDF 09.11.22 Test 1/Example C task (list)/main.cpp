/******************************************************************************

C. Write C++ function (only function not the whole program) to process one-way linked list of int.
Already created non-empty linked list is supplied as pointer to the first element.

C1[5]. Function incDecOdd, which increases by 1 negative odd numbers, but decreases by 1 positive odd numbers.
E.g., {-2,3,-7,-4,5}→{-2,2,-6,-4,4}

C2[9]. Function deleteFirstEvenBeforeOdd, which removes from the list the first even number directly followed by an odd number.
E.g. {2,3,8,4,5}→{3,8,4,5}; {2,4,8,6,5}→{2,4,8,5}; {2,4,8,6,-2}→{2,4,8,6,-2} (nothing deleted, only even numbers); {1,3,5,9}→{1,3,5,9} (nothing deleted, only odd numbers)

*******************************************************************************/
#include <iostream>
#include <list>

using namespace std;

void printList(list<int> &aa)
{
    auto i = aa.begin();
    while (i != aa.end())
    {
        cout << *i << " ";
        i++;
    }
    cout << endl;
};

void incDecOdd(list<int> &aa)
{
    for (auto &a : aa)
    {
        if (a % 2 != 0 && a < 0)
        {
            a++;
        }
        else if (a % 2 != 0 && a > 0)
        {
            a--;
        };
    };
};

void deleteFirstEvenBeforeOdd(list<int> &aa)
{
    auto i = aa.begin();
    while (i != aa.end())
    {
        auto k = i;
        k++;
        if (*i % 2 == 0 and *k % 2 != 0 and k != aa.end())
        {
            aa.erase(i);
            break;
        };
        i++;
    }
}

int main()
{
    list<int> aa = {-2, 3, -7, -4, 5};
    printList(aa);
    incDecOdd(aa);
    printList(aa);

    list<int> bb = {2, 3, 8, 4, 5};
    printList(bb);
    deleteFirstEvenBeforeOdd(bb);
    printList(bb); // expected {3,8,4,5}
}
