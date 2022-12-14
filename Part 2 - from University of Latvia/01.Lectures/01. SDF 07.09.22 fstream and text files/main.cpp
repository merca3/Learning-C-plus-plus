#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // writing INTO a file example
    fstream f1;
    f1.open("out.txt", ios::out);

    if (f1.is_open())
    {
        cout << "Successfully opened" << endl;
        f1 << "Hello, " << endl;
        f1 << "World!" << endl;
        f1.close();
    }
    else
        cout << "Opening failed" << endl;

    // writing FROM a file example

    fstream f2;
    f2.open("out.txt", ios::in);
    int linenum = 0;

    if (f2.is_open())
    {
        string s;
        while (getline(f2, s))
        {
            ++linenum;
            cout << linenum << ". " << s << endl;
        }
        f2.close();
    }
    else
        cout << "Opening failed" << endl;
}
