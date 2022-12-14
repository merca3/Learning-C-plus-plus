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

void print(elem *first)
{
    elem *p = first;
    while (p != NULL)
    {
        cout << p->num << " ";
        p = p->next;
    }
    cout << endl;
}

void delete_list(elem *&first)
{
    elem *p = first;
    while (first != NULL)
    {
        p = first->next;
        delete first;
        first = p;
    }
}

int main()
{
    // int aa[] = {1,8,4,6,5};
    elem *first = NULL, *last = NULL;

    // for (int i=0;i<5;++i) {
    //     push_back(first, last, aa[i]);
    // }

    // adding value into linked list
    push_back(first, last, 1);
    push_back(first, last, 8);
    push_back(first, last, 4);
    push_back(first, last, 6);
    push_back(first, last, 5);
    print(first);

    int k = 99;
    int pos = 4; // works both with first or any other number
    elem *p = first;
    elem *prev = NULL;
    // find element 4
    while (p && p->num != pos)
    {
        prev = p;
        p = p->next;
    }
    if (p != NULL)
    {
        cout << p->num << endl;

        elem *x = new elem; // creating new element, which will be added to the list
        x->num = k;
        x->next = p;

        if (prev)
        {
            cout << prev->num << endl;
            prev->next = x;
        }
        else
        {
            cout << "No previous" << endl;
            first = x;
        }
    }
    else
        cout << "Not found" << endl;

    print(first);
    delete_list(first);
}
