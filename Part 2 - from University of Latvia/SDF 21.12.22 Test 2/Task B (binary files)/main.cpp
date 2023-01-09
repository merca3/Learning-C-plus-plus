/******************************************************************************

B. Given binary file of int values (exactly 4 bytes per number).
Write function in C++ to process the file (only constant amount of auxiliary memory allowed).

B1[10]. Function countLast23 which calculates, whether the third last element is bigger than the second last element.
E.g., {4,8,5,6,3}→no; {4,8,55,6,3}→yes.

B2[16]. Function deleteLast23, which writes all elements from given file to another file, except the third last and the second last.
E.g., {4,8,5,6,3}→{4,8,3}.


*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

void writeIntoFile(const char *fname)
{
    int aa[5] = {4, 8, 5, 6, 3};

    fstream f(fname, ios::out | ios::binary);

    for (int i = 0; i < 5; ++i)
    {
        f.write((char *)&aa[i], 4);
    }
    f.close();
}

void print(const char *fname)
{
    cout << "Print from file '" << fname << "': ";
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

void countLast23(const char *fname)
{
    int thirdLast, secondLast;
    fstream f(fname, ios::in | ios::binary); // reading from file, which name was passed

    f.seekg(-12, ios::end);        // finding 3rd last element
    f.read((char *)&thirdLast, 4); // reading the value of it into variable

    f.seekg(-8, ios::end); // finding 2nd last element
    f.read((char *)&secondLast, 4);

    if (thirdLast > secondLast)
        cout << "Yes: " << thirdLast << " is bigger than " << secondLast << endl;
    else
        cout << "No: " << thirdLast << " is NOT bigger than " << secondLast << endl;

    f.close();
}

void deleteLast23(const char *fname, const char *fname2)
{
    fstream f(fname, ios::in | ios::binary);
    fstream f2(fname2, ios::out | ios::binary);

    f.seekg(0, ios::end);      // going to last position
    int fsize = f.tellg() / 4; // finding size

    int n;
    f.seekg(0); // going back to first position
    f.read((char *)&n, 4);
    int pos = 0;
    while (f)
    {
        if (pos != fsize - 2 and pos != fsize - 3) // comparing with third and second last
            f2.write((char *)&n, 4);

        f.read((char *)&n, 4);
        ++pos;
    }

    f.close();
    f2.close();
}

int main()
{
    writeIntoFile("numbers.bin");

    cout << "For B1 task:" << endl
         << endl;
    print("numbers.bin");
    countLast23("numbers.bin");
    cout << endl;

    cout << "-----------------------------" << endl
         << endl;
    cout << "For B2 task:" << endl
         << endl;
    print("numbers.bin");
    deleteLast23("numbers.bin", "results.bin");
    print("results.bin");
}
