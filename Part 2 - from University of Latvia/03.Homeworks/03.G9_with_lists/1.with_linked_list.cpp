/******************************************************************************

Create two programs in C++ to process sequences of values in two ways:
  1) implementing it through a linked list, using dynamic data structures,
  2) using STL::list.
In both implementations, a specific function to process values should be created and presented in action
(showing both initial and resulting values). In the case of linked-list, also auxiliary functions should
be created and allocated memory for the structure should be freed.

G9. Create function to check - does list contains at least two elements with equal values.

Test 1. Input: 1,2,3,4,5,3,0.   Output:
                                Entered values in linked list:
                                1 2 3 4 5 3
                                There are at least two elements with value 3

Test 2. Input: 1,2,3,4,5,3,2,0. Output:
                                Entered values in linked list:
                                1 2 3 4 5 3 2
                                There are at least two elements with value 2
                                There are at least two elements with value 3

Test 3. Input: 1,2,3,4,5,6,0.   Output:
                                Entered values in linked list:
                                1 2 3 4 5 6
                                There are no repeated values in linked list

Test 4. Input: 2,2,2,2,3,3,3,0. Output:
                                Entered values in linked list:
                                2 2 2 2 3 3 3
                                There are at least two elements with value 2
                                There are at least two elements with value 3

Test 5. Input: 0.               Output:
                                Entered values in linked list:
                                *** List is empty ***

                                There are no repeated values in linked list

*******************************************************************************/
#include <iostream>

using namespace std;

// code for push_back, print and delete_list functions are copied from 16.11.2022 lecture code example
// was writing together with a teacher

struct elem
{
    int num;
    elem *next;
};

void push_back(elem *&first, elem *&last, int val)
{
    elem *p = new elem;
    p->num = val;
    p->next = NULL;
    if (first == NULL)
    {
        first = p;
        last = p;
    }
    else
    {
        last->next = p;
        last = p;
    }
}

void printLinkedList(elem *first)
{
    elem *p = first;
    if (p == NULL)
    {
        cout << "*** List is empty ***" << endl;
        return;
    }
    while (p != NULL)
    {
        cout << p->num << " ";
        p = p->next;
    }
    cout << endl;
}

void deleteLinkedList(elem *&first)
{
    elem *p = first;
    while (first != NULL)
    {
        p = first->next;
        delete first;
        first = p;
    }
}

void printResults(elem *first)
{
    elem *p = first;
    if (p == NULL)
    {
        cout << "There are no repeated values in linked list" << endl;
        return;
    }
    while (p != NULL)
    {
        elem *r = p->next;

        while (r != NULL)
        {
            if (r->num == p->num)
            { // should remove repeated values
                p = first->next;
                delete first;
                first = p;
            }
            r = r->next;
        }
        cout << "There are at least two elements with value " << p->num << endl;
        p = first->next; // clears up the list
        delete first;
        first = p;
    }
    cout << endl;
}

int main()
{
    cout << "With linked list" << endl;
    cout << "--------------------------------------------------------" << endl;

    elem *first = NULL, *last = NULL;
    int inputNum;

    cout << "Enter list elements for linked list (or 0 to exit): " << endl;
    do
    {
        cin >> inputNum;
        if (inputNum != 0)
        {
            push_back(first, last, inputNum); // adding value/element into linked list
        }
    } while (inputNum != 0);

    cout << "Entered values in linked list:" << endl;
    printLinkedList(first);

    elem *p = first;
    elem *resF = NULL, *resL = NULL; // linked list that will store repeated values
    int checkedValue;
    while (p != NULL)
    {
        checkedValue = p->num;
        elem *nextEl = p->next;

        while (nextEl != NULL)
        {
            if (nextEl->num == checkedValue)
            {
                push_back(resF, resL, checkedValue);
            }
            nextEl = nextEl->next;
        }

        p = p->next;
    }
    cout << endl;

    printResults(resF); // both prints results and deletes result list
    deleteLinkedList(first);

    cout << endl;
    cout << " - - - - - - - - - - Have a nice day! - - - - - - - - - - " << endl;
}
