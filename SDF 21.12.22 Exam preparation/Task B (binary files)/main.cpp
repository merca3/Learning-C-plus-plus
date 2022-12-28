/******************************************************************************

*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

void writeIntoFile5()
{
    int aa[5] = {4, 8, 5, 6, 3};

    fstream fa("numbers-b1.bin", ios::out | ios::binary);

    for (int i = 0; i < 5; ++i)
    {
        fa.write((char *)&aa[i], 4);
    }
    fa.close();
}
void writeIntoFile6()
{
    int aa[6] = {4, 8, 5, 6, 3, 7};

    fstream fa("numbers-b2.bin", ios::out | ios::binary);

    for (int i = 0; i < 6; ++i)
    {
        fa.write((char *)&aa[i], 4);
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

void findSumOfMiddleElements(const char *fname)
{
    fstream f(fname, ios::in | ios::binary);

    f.seekg(0, ios::end);
    int fsize = f.tellg() / 4;

    if (fsize == 0)
    {
        cout << "Empty file" << endl;
    }
    else if (fsize % 2 != 0)
    { // sum equals to value of one middle element
        int pos = fsize / 2 * 4;
        f.seekg(pos);
        int n;
        f.read((char *)&n, 4);
        cout << "ODD: " << n << endl;
    }
    else
    { // sum equals to value of two middle elements
        int pos = (fsize / 2 - 1) * 4;
        int n, m;
        f.seekg(pos);
        f.read((char *)&n, 4);
        f.seekg(pos + 4);
        f.read((char *)&m, 4);
        cout << "EVEN: " << n << " and " << m << endl;
        cout << "SUM: " << n + m << endl;
    }

    f.close();
}

// remove one element if odd amount of those, or 2 elements if even
void printWithoutMiddleElement(const char *fname)
{
    fstream f(fname, ios::in | ios::binary);

    f.seekg(0, ios::end);
    int fsize = f.tellg() / 4;

    if (fsize == 0)
    {
        cout << "Empty file" << endl;
    }
    else if (fsize % 2 != 0)
    {
        int pos = fsize / 2 * 4 + 4;
        f.seekg(0);
        int n;
        f.read((char *)&n, 4);
        cout << "PRINT WITHOUT MIDDLE: ";
        while (f)
        {
            if (f.tellg() != pos)
                cout << n << " ";
            f.read((char *)&n, 4);
        }
        cout << endl;
    }
    else
    {
        int pos = (fsize / 2 - 1) * 4;
        f.seekg(0);
        int n;
        f.read((char *)&n, 4);
        cout << "PRINT WITHOUT MIDDLE: ";
        while (f)
        {
            if (f.tellg() != pos && f.tellg() != pos + 4)
                cout << n << " ";
            f.read((char *)&n, 4);
        }
        cout << endl;
    }

    f.close();
}

int main()
{
    writeIntoFile5();
    writeIntoFile6();

    print("numbers-b1.bin");
    findSumOfMiddleElements("numbers-b1.bin");
    printWithoutMiddleElement("numbers-b1.bin");

    cout << "------------------------------------------" << endl;

    print("numbers-b2.bin");
    findSumOfMiddleElements("numbers-b2.bin");
    printWithoutMiddleElement("numbers-b2.bin");
}
