#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // char nn[3][15]={"Ann", "Peter", "Liz"};
    // int aa[3]={19, 20, 18};

    // Writing into binary files

    // fstream f("students.bin", ios::out | ios::binary);
    // f.write(nn[0], 12);
    // f.write((char*)&aa[0], 4);

    // f.write(nn[1], 12);
    // f.write((char*)&aa[1], 4);

    // f.write(nn[2], 12);
    // f.write((char*)&aa[2], 4);

    // f.close();  // 16x3=48 bytes for the file

    // --------------------------------------------------
    // Reading from binary file

    char n[12];
    int a;

    fstream f2("students.bin", ios::in | ios::binary);
    f2.read(n, 12);
    f2.read((char *)&a, 4);

    // while (f.eof()==false);
    while (f2)
    {
        cout << n << " " << a << endl;
        f2.read(n, 12);
        f2.read((char *)&a, 4);
    }

    f2.close();

    // --------------------------------------------------
    // Jumping to specific position/address

    fstream f3("students.bin", ios::in | ios::binary);
    f3.seekg(0, ios::end);
    cout << f3.tellg() << endl;
    f3.seekg(16);
    f3.read(n, 12);
    f3.read((char *)&a, 4);
    cout << n << " " << a << endl;
    cout << f3.tellg() << endl; // 5
    f3.seekg(-32, ios::cur);    // 6
    cout << f3.tellg() << endl; // 7
    f3.seekg(-16, ios::end);    // 8
    f3.read(n, 12);
    f3.read((char *)&a, 4);
    cout << n << " " << a << endl;

    f3.close();
}