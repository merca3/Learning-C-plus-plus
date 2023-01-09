/******************************************************************************

A. Write C++ function (only function not the whole program) to process one-way linked list of int.
Already created non-empty linked list is supplied as pointer to the first element.
A1[10]. Function increaseFirstEvenBeforeOdd, which increases by 1 the first even number directly followed by an odd number.
E.g., {2,3,8,4,5}→{3,3,8,4,5}; {1,3,5,9}→{1,3,5,9} (nothing increased, only odd numbers).

A2[16]. Function deleteSecondLastIfBiggerThanLast, which removes from the list the second last element with condition that
it is bigger than the last one. E.g., {8,4}→{4}; {2,3,8,4,5}→{2,3,8,4,5} (nothing deleted); {2,4,8,6,5}→{2,4,8, 5}.


*******************************************************************************/
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

void increaseFirstEvenBeforeOdd(elem *first)
{
    elem *p = first;
    while (p != NULL)
    {
        if (p->num % 2 == 0 && p->next->num % 2 != 0)
        {
            p->num++;
            break;
        }
        p = p->next;
    }
}

void deleteSecondLastIfBiggerThanLast(elem *&first)
{
    if (first == NULL || first->next == NULL)
        return;
    elem *p = first;

    int cnt = 0;
    while (p != NULL)
    {
        ++cnt;
        p = p->next;
    }
    cout << "Size of linked list: " << cnt << endl;

    p = first;

    if (p->num > p->next->num && cnt == 2)
    {
        first = first->next;
        delete p;
    }
    else
    {
        while (p != NULL)
        {
            elem *c = p->next;
            elem *n = c->next;

            if (n->next == NULL && c->num > n->num)
            {
                p->next = n;
                delete c;
                break;
            }

            p = c;
            c = n;
            n = n->next;
            p = p->next;
        }
    }
}

int main()
{
    int preGivenListNumbers[] = {2, 3, 8, 4, 5}; // values to be added to the list
    elem *first = NULL, *last = NULL;

    // creation of the linked list
    for (int i = 0; i < 5; ++i)
    {
        push_back(first, last, preGivenListNumbers[i]);
    }

    printLinkedList(first);
    increaseFirstEvenBeforeOdd(first);
    printLinkedList(first);
    deleteLinkedList(first);

    cout << "--------------------------" << endl;

    // int preGivenListNumbers2[] = {1, 3, 5, 9}; // values to be added to the list
    // for (int i = 0; i < 4; ++i) {
    //     push_back(first, last, preGivenListNumbers2[i]);
    // }

    // printLinkedList(first);
    // increaseFirstEvenBeforeOdd(first);
    // printLinkedList(first);
    // deleteLinkedList(first);

    // cout << "--------------------------" << endl;

    // int preGivenListNumbers3[] = {8,4};
    // for (int i = 0; i < 2; ++i) {
    //     push_back(first, last, preGivenListNumbers3[i]);
    // }

    // printLinkedList(first);
    // deleteSecondLastIfBiggerThanLast(first);
    // printLinkedList(first);
    // deleteLinkedList(first);

    cout << "--------------------------" << endl;

    int preGivenListNumbers4[] = {2, 4, 8, 6, 5}; // values to be added to the list
    for (int i = 0; i < 5; ++i)
    {
        push_back(first, last, preGivenListNumbers4[i]);
    }

    printLinkedList(first);
    deleteSecondLastIfBiggerThanLast(first);
    printLinkedList(first);
    deleteLinkedList(first);
}
