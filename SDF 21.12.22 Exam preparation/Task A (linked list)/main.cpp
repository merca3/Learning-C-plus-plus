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

void findMiddleElement(elem *first)
{
    int cnt = 0;
    elem *p = first;
    while (p != NULL)
    {
        ++cnt;
        p = p->next;
    }
    cout << "Size of linked list: " << cnt << endl;

    if (cnt % 2 != 0)
    {
        int pos = cnt / 2;
        p = first;
        int i = 0;
        while (p != NULL)
        {
            if (i == pos)
            {
                cout << "Middle element: " << p->num << " ";
                break;
            }
            i++;
            p = p->next;
        }
        cout << endl;
    }
    else
    {
        int pos = cnt / 2;
        p = first;
        int i = 0;
        while (p != NULL)
        {
            if (i == pos - 1)
            {
                cout << "Middle elements: " << p->num << " and " << p->next->num << " ";
                break;
            }
            i++;
            p = p->next;
        }
        cout << endl;
    }
}

int main()
{
    elem *first = NULL, *last = NULL;
    push_back(first, last, 4);
    push_back(first, last, 8);
    push_back(first, last, 7);
    push_back(first, last, 6);
    push_back(first, last, 3);
    printLinkedList(first);
    findMiddleElement(first);
    deleteLinkedList(first);

    cout << "---------------------------------" << endl;

    push_back(first, last, 4);
    push_back(first, last, 8);
    push_back(first, last, 7);
    push_back(first, last, 6);
    push_back(first, last, 1);
    push_back(first, last, 3);
    printLinkedList(first);
    findMiddleElement(first);
    deleteLinkedList(first);
}
