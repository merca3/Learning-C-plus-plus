#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int aa[5] = {1, 8, 4, 6, 5};
    char s[] = "Hello";

    fstream fb("intout.bin", ios::out | ios::binary);

    for (int i = 0; i < 5; ++i)
    {
        fb.write((char *)&aa[i], 4); // 20 bytes, 5 numbers x 4 bytes
    }
    fb.write(s, 5);

    // fb.read((char*)&a, 4);

    fb.close();
}