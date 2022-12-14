#include <iostream>
using namespace std;
void print(int *arr, int len)
{
    for (int i = 0; i < len; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void push_back(int *&arr, int &len, int val)
{
    if (len == 0)
    {
        arr = new int[1];
        arr[0] = val;
    }
    else
    {
        int *tmp = new int[len + 1];
        for (int i = 0; i < len; ++i)
            tmp[i] = arr[i];
        tmp[len] = val;
        delete arr;
        arr = tmp;
    }
    ++len;
}

void insert(int *&arr, int &len, int k, int val)
{
    if (len == 0)
    {
        arr = new int[1];
        arr[0] = val;
    }
    else
    {
        int *tmp = new int[len + 1];
        for (int i = 0; i < k; ++i)
            tmp[i] = arr[i];
        tmp[k] = val;
        for (int i = k + 1; i < len; ++i)
            tmp[i] = arr[i - 1];
        delete arr;
        arr = tmp;
    }
    ++len;
}

void erase(int *&arr, int &len, int k)
{
    if (len == 1)
    {
        delete[] arr;
    }
    else
    {
        int *tmp = new int[len - 1];
        for (int i = 0; i < k; ++i)
            tmp[i] = arr[i];
        for (int i = k + 1; i < len; ++i)
            tmp[i - 1] = arr[i];
        delete arr;
        arr = tmp;
    }
    --len;
}

int &at(int *arr, int k)
{
    return arr[k];
}

int main()
{
    int *aa;
    int len = 0;
    push_back(aa, len, 1);
    push_back(aa, len, 8);
    push_back(aa, len, 4);
    push_back(aa, len, 6);
    push_back(aa, len, 5);
    print(aa, len);
    erase(aa, len, 0);
    erase(aa, len, 2);
    print(aa, len);
    insert(aa, len, 2, 99);
    print(aa, len);
    cout << at(aa, 2) << endl;
    at(aa, 2) = 100;
    print(aa, len);
    delete[] aa;
}
/*
1 8 4 6 5
8 4 5
8 4 99 5
99
8 4 100 5
*/
