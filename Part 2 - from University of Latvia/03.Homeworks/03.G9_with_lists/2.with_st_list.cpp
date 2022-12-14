/******************************************************************************

Create two programs in C++ to process sequences of values in two ways:
  1) implementing it through a linked list, using dynamic data structures,
  2) using STL::list.
In both implementations, a specific function to process values should be created and presented in action
(showing both initial and resulting values). In the case of linked-list, also auxiliary functions should
be created and allocated memory for the structure should be freed.

G9. Create function to check - does list contains at least two elements with equal values.

Test 1. Input: 1,2,3,4,5,3,0.   Output:
                                Entered values in STL::list:
                                1 2 3 4 5 3
                                There are at least two elements with value 3

Test 2. Input: 1,2,3,4,5,3,2,0. Output:
                                Entered values in STL::list:
                                1 2 3 4 5 3 2
                                There are at least two elements with value 2
                                There are at least two elements with value 3

Test 3. Input: 1,2,3,4,5,6,0.   Output:
                                Entered values in STL::list:
                                1 2 3 4 5 6
                                There are no repeated values in *** list

Test 4. Input: 2,2,2,2,3,3,3,0. Output:
                                Entered values in STL::list:
                                2 2 2 2 3 3 3
                                There are at least two elements with value 2
                                There are at least two elements with value 3

Test 5. Input: 0.               Output:
                                Entered values in STL::list:
                                *** List is empty ***

                                There are no repeated values in STL::list

*******************************************************************************/
#include <iostream>
#include <list>

using namespace std;

void printList(list<int> &aa)
{
    if (aa.size() == 0)
    {
        cout << "*** List is empty ***" << endl;
        return;
    }
    auto i = aa.begin();
    while (i != aa.end())
    {
        cout << *i << " ";
        i++;
    }
    cout << endl;
};

void printResults(list<int> &aa)
{
    if (aa.size() == 0)
    {
        cout << "There are no repeated values in STL::list" << endl;
        return;
    }
    auto i = aa.begin();
    while (i != aa.end())
    {
        cout << "There are at least two elements with value " << *i << endl;
        i++;
    }
    cout << endl;
};

int main()
{
    cout << "With STL::list" << endl;
    cout << "--------------------------------------------------------" << endl;

    list<int> aa = {};             // this list stores entered values
    list<int> repeatedValues = {}; // this list stores repeated values
    int inputNum;

    cout << "Enter list elements for linked list (or 0 to exit): " << endl;
    do
    {
        cin >> inputNum;
        if (inputNum != 0)
        {
            aa.push_back(inputNum);
        }
    } while (inputNum != 0);

    cout << "Entered values in STL::list:" << endl;
    printList(aa);

    list<int>::iterator i;
    for (i = aa.begin(); i != aa.end(); i++)
    {
        list<int>::iterator j = i;

        // increasing second iterator j before the nested loop, so it's next value after i
        for (++j; j != aa.end(); j++)
        {
            if (*j == *i)
            {
                repeatedValues.push_back(*i);
            }
        }
    }
    cout << endl;

    repeatedValues.unique(); // removes all duplicate consecutive elements from the list

    printResults(repeatedValues);

    cout << endl;
    cout << " - - - - - - - - - - Have a nice day! - - - - - - - - - - " << endl;
}
