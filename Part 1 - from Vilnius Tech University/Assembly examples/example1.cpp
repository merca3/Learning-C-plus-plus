#include <iostream>
using namespace std;

int main()
{
    int a = 20;

    __asm {
        mov eax, a; // 
        imul eax, 2; // multiplication of content of register eax by 20
                     // and to put the value again in eax
        mov rez, eax;         // assignment of the value of registar eax for variable rez
        }

    cout << rez << endl;
}
