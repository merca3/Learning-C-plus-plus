/******************************************************************************

B. Write C++ program to process sequence of integer values of type list<int>.
B1[10]. Program increaseFirstTwoAdjacentEqual, which increases by 1 first two adjacent equal elements.
E.g., {1,3,3,3,4,1,4}→{1,4,4,3,4,1,4}; {1,1,2,2,3,3,4,4}→{2,2,2,2,3,3,4,4}; {1,2,3,4,5}→{1,2,3,4,5} (nothing increased).
B2[16]. Program deleteFirstTwoAdjacentEqual, which removes from the list the first two adjacent equal elements.
E.g. {1,3,3,3,4,1,4}→{1,3,4,1,4}; {1,1,2,2,3,3,4,4}→{2,2,3,3,4,4}; {1,2,3,4,5}→{1,2,3,4,5} (nothing deleted).

*******************************************************************************/
#include <iostream>
#include <list>

using namespace std;

void printList(list<int> &aa)
{
    auto i = aa.begin();
    while (i != aa.end())
    {
        cout << *i << " "; // prints out the value of item
        i++;               // increases iterator
    }
    cout << endl;
};

void increaseFirstTwoAdjacentEqual(list<int> &aa)
{
    auto i = aa.begin();
    while (i != aa.end())
    {
        auto k = i;
        k++; // points to next element
        if (*i == *k and k != aa.end())
        {            // checks if existing and next item have the same value
            *i += 1; // increases the value
            *k += 1;
            break; // breaks the loop, as there is no requirement to continue
        };
        i++;
    }
};

void deleteFirstTwoAdjacentEqual(list<int> &aa)
{
    auto i = aa.begin();
    while (i != aa.end())
    {
        auto k = i;
        k++;
        if (*i == *k and k != aa.end())
        {
            aa.erase(i); // deletes both i and k items
            aa.erase(k);
            break; // breaks the loop, as there is no requirement to continue
        };
        i++;
    }
}

int main()
{
    list<int> b11 = {1, 3, 3, 3, 4, 1, 4};
    cout << "Original list: ";
    printList(b11);
    cout << "After increaseFirstTwoAdjacentEqual function: ";
    increaseFirstTwoAdjacentEqual(b11);
    printList(b11); // expected {1,4,4,3,4,1,4}
    cout << "After deleteFirstTwoAdjacentEqual function: ";
    deleteFirstTwoAdjacentEqual(b11);
    printList(b11); // expected {1,3,4,1,4}
    cout << "--------------------------------------------------------------" << endl;

    list<int> b12 = {1, 1, 2, 2, 3, 3, 4, 4};
    cout << "Original list: ";
    printList(b12);
    cout << "After increaseFirstTwoAdjacentEqual function: ";
    increaseFirstTwoAdjacentEqual(b12);
    printList(b12); // expected {2,2,2,2,3,3,4,4}
    cout << "After deleteFirstTwoAdjacentEqual function: ";
    deleteFirstTwoAdjacentEqual(b12);
    printList(b12); // expected {2,2,3,3,4,4}
    cout << "--------------------------------------------------------------" << endl;

    list<int> b13 = {1, 2, 3, 4, 5};
    cout << "Original list: ";
    printList(b13);
    cout << "After increaseFirstTwoAdjacentEqual function: ";
    increaseFirstTwoAdjacentEqual(b13);
    printList(b13); // expected {1,2,3,4,5}
    cout << "After deleteFirstTwoAdjacentEqual function: ";
    deleteFirstTwoAdjacentEqual(b13);
    printList(b13); // expected {1,2,3,4,5}
    cout << "--------------------------------------------------------------" << endl;
}
