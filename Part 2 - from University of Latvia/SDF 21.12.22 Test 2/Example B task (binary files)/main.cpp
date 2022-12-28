/******************************************************************************

B. Given binary file of int values (exactly 4 bytes per number). Write function in C++ to process the file
(only constant amount of auxiliary memory allowed).
B1[6]. Function countSum2Plus which calculates the sum of the second and the second last element. E.g., {4,8,5,6,3}→14
B2[9]. Function deletLast2Plus which writes all elements from given file to another file, except the second and the second last.
E.g., {4,8,5,6,3}→{4,5,3}

*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

void writeIntoFile()
{
    int aa[5] = {4, 8, 5, 6, 3};

    fstream fa("numbers.bin", ios::out | ios::binary);

    for (int i = 0; i < 5; ++i)
    {
        fa.write((char *)&aa[i], 4); // 20 bytes, 5 numbers x 4 bytes
    }
    fa.close();
}

void print(const char *fname)
{
    cout << "FILE: ";
    fstream f(fname, ios::in | ios::binary);
    int n;
    f.read((char *)&n, 4);
    while (f)
    {
        cout << n << " ";
        f.read((char *)&n, 4);
    }
    cout << endl;
    f.close();
}

void countSum2Plus()
{
    int a;
    fstream fb("numbers.bin", ios::in | ios::binary);
    fb.seekg(0, ios::end);
    int sum = 0;
    if (fb.tellg() >= 8)
    { // amount of numbers/bytes
        fb.seekg(4);
        fb.read((char *)&a, 4);
        sum += a;
        fb.seekg(-8, ios::end);
        fb.read((char *)&a, 4);
        sum += a;
    };

    // fb.read((char*)&a, sizeof(a));
    // while (fb) {
    //     cout << a << endl;
    //     fb.read((char*)&a, sizeof(a));
    // }

    cout << sum << endl;
    fb.close();
}

void deletLast2Plus(const char *fname, const char *fname2)
{
    fstream f(fname, ios::in | ios::binary);
    fstream f2(fname2, ios::out | ios::binary);

    f.seekg(0, ios::end);
    int fsize = f.tellg() / 4;
    int n;
    f.seekg(0);
    f.read((char *)&n, 4);
    int pos = 0;
    while (f)
    {
        if (pos != 1 and pos != fsize - 2)
            f2.write((char *)&n, 4);

        f.read((char *)&n, 4);
        ++pos;
    }

    f.close();
    f2.close();
}

int main()
{
    // writeIntoFile();

    // countSum2Plus();
    print("numbers.bin");
    deletLast2Plus("numbers.bin", "results.bin");
    print("results.bin");

    deletLast2Plus("results.bin", "results2.bin");
    print("results2.bin");

    deletLast2Plus("results2.bin", "results3.bin");
    print("results3.bin");
}