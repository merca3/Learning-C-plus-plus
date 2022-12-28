// C. Write C++ function (only function not the whole program) to process one-way linked list of int.
// Already created non-empty linked list is supplied as pointer to the first element.

// C1[5]. Function incDecOdd, which increases by 1 negative odd numbers, but decreases by 1 positive odd numbers.
// E.g., {-2,3,-7,-4,5}→{-2,2,-6,-4,4}

// C2[9]. Function deleteFirstEvenBeforeOdd, which removes from the list the first even number directly followed by an odd number.
// E.g. {2,3,8,4,5}→{3,8,4,5}; {2,4,8,6,5}→{2,4,8,5}; {2,4,8,6,-2}→{2,4,8,6,-2} (nothing deleted, only even numbers);
// {1,3,5,9}→{1,3,5,9} (nothing deleted, only odd numbers)

#include <iostream>
using namespace std;

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

void incDecOdd(elem *first)
{
    elem *p = first;
    while (p != NULL)
    {
        if (p->num % 2 != 0)
        {
            if (p->num < 0)
                p->num++;
            else
                p->num--;
        }
        p = p->next;
    }
}

void deleteFirstEvenBeforeOdd(elem *&first)
{ // & needed if reference can change
    if (first == NULL || first->next == NULL)
        return;
    elem *p = first;
    if (p->num % 2 == 0 && p->next->num % 2 != 0)
    {
        first = first->next;
        delete p;
    }
    else
    {
        elem *c = p->next;
        elem *n = c->next;
        while (n != NULL)
        {
            if (c->num % 2 == 0 && n->num % 2 != 0)
            {
                p->next = n;
                delete c;
                break;
            }
            p = c;
            c = n;
            n = n->next;
        }
    }
}

int main()
{
    elem *first = NULL, *last = NULL;
    push_back(first, last, -2);
    push_back(first, last, 3);
    push_back(first, last, -7);
    push_back(first, last, -4);
    push_back(first, last, 5);
    printLinkedList(first);
    incDecOdd(first);
    printLinkedList(first);
    deleteLinkedList(first);

    push_back(first, last, 2);
    push_back(first, last, 3);
    push_back(first, last, 8);
    push_back(first, last, 4);
    push_back(first, last, 5);
    printLinkedList(first);
    deleteFirstEvenBeforeOdd(first);
    printLinkedList(first);
    deleteLinkedList(first);

    push_back(first, last, 2);
    push_back(first, last, 4);
    push_back(first, last, 8);
    push_back(first, last, 6);
    push_back(first, last, 5);
    printLinkedList(first);
    deleteFirstEvenBeforeOdd(first);
    printLinkedList(first);
    deleteLinkedList(first);
}
