#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>

bool lastdigitless(int i, int k)
{
    return i % 10 < k % 10;
};

bool isOdd(int i)
{
    return i % 2 != 0;
};

struct elem
{
    int num;
    elem *next;
};

using namespace std;
int main()
{
    // ------- With deque -------

    deque<int> aa{12, 8, 5, 14, 7, 3};

    // Regular sorting
    // sort(aa.begin(), aa.end());

    // Sort all except first and last elements
    // sort(aa.begin()+1, aa.end()-1);

    // Sort by last digit
    // sort(aa.begin(), aa.end(), lastdigitless);

    // Sort by odd/even
    // partition(aa.begin(), aa.end(), isOdd);
    // stable_partition(aa.begin(), aa.end(), isOdd);

    for (auto a : aa)
        cout << a << " ";
    cout << endl;

    // ------- With vector -------

    vector<int> aaa = {12, 8, 3};      // 12 8 3
    aaa.push_back(7);                  // 12 8 3 7
    aaa.insert(aaa.begin(), 5);        // 5 12 8 3 7
    aaa.erase(aaa.begin() + 1);        // 5 8 3 7
    remove(aaa.begin(), aaa.end(), 8); // 5 3 7 7 !!!
    aaa.pop_back();                    // 5 3 7

    for (auto a : aaa)
        cout << a << " ";
    cout << endl;

    vector<int> v1 = {1, 5, 8};
    vector<int> v2 = {2, 3, 7, 9};
    vector<int> vMerged(7);
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vMerged.begin());

    for (auto a : v1)
        cout << a << " ";
    cout << endl;
    for (auto a : v2)
        cout << a << " ";
    cout << endl;
    for (auto a : vMerged)
        cout << a << " ";
    cout << endl;

    // ------- Chained structures -------

    int bb[] = {1, 8, 4, 6, 5};
    elem *first = NULL, *last = NULL;

    // creation
    for (int i = 0; i < 5; ++i)
    {
        elem *p = new elem;
        p->num = bb[i];
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

    // printing
    elem *p = first;
    while (p != NULL)
    {
        cout << p->num << " ";
        p = p->next;
    }

    // delete all
    while (first != NULL)
    {
        p = first->next;
        delete first;
        first = p;
    }
}
