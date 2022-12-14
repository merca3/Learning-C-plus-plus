// Example of the loop
// f(x) = \sum_{i=0}^{x} (2 \cdot i - (3 - i)^2), where x is integer

#include <iostream>

int main()
{
    int x = 4; // Number of the loops
    x = x + 1;
    int rez = 0, rez1 = 0, rez2 = 0, rez3 = 0, rez4 = 0; // Rezult of the function evaluation
    __asm {
        mov eax, 70; // Result of the function evaluation
        mov ecx, 0; // Number of iteration, 0 is initial value
        mov ebx, 20;
        cdq;
        idiv x;
        mov rez, eax; // The quotient is put in eax register
        mov rez1, edx;                                   // remainder is put in edx
        // ---------------------------------------------
        xor eax, eax; // Clearing eax register
        xor ecx, ecx; // Clearing ecx register for iterations counting
        xor ebx, ebx;
        xor edx, edx;

    loop_beginning:
        mov ebx, ecx;
        mov eax, ecx;
        imul ebx, 2;                                     // (2 * i)
        //-------------------
        sub eax, 3; // (i - 3)
        imul eax, -1; // (3 - i)
        imul eax, eax; // (3 - i)^2
        add edx, ebx;
        sub edx, eax;

        inc ecx;
        cmp ecx, x;
        
        je loop_end; // Finishing of the loop
        jmp loop_beginning; // Go to to the beginnging of the loop
        
    loop_end:                                        // End of the loop
        mov rez1, ecx;
        mov rez2, eax; 
        mov rez3, ebx;
    }
    std::printf("\nNumber of iterations %d ", x - 1);
    std::printf("\nResult of the calculations rez =  %d ", rez);
    std::printf("\nNumber of iterations in ecx register ecx rez1 = %d ", rez1);
    std::printf("\nResult of the calculations eax (3 - i)^2: rez2 = %d ", rez2);
    std::printf("\nResult of the calculations ebx (2 * i):  rez3 = %d ", rez3);
}
