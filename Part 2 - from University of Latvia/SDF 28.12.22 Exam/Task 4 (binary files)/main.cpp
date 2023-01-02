/******************************************************************************

Katrina Merca - km11104

4. Given binary file of int values (exactly 4 bytes per number). 
Write C++ program to process the file (duplicate of the file in the memory not allowed), 
which calculates the number of elements in the file, ones equal either to the second or to the second last element. 
E.g., {1,3,3,3,4,1,4}→5

*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

void writeIntoFile() {
    int aa[7]={1, 3, 3, 3, 4, 1, 4};
    
    fstream f("numbers.bin", ios::out|ios::binary);
    
    if(f.is_open()) { // basic validation for streams
        for (int i = 0; i < 7; ++i) {
            f.write((char*)&aa[i], 4);
        }
    } else cout << "Writing into bin file failed" << endl;
    
    f.close();
}

void printBinaryFileContent(const char *fname) {
    cout << "File content: ";
    fstream f(fname, ios::in|ios::binary);
    
    if (f.is_open()) {
        int n;
        f.read((char*)&n, 4);
        while (f) {
            cout << n << " ";
            f.read((char*)&n, 4);
        }
        cout << endl;
    } else cout << "Reading from bin file failed" << endl;
    
    f.close();
}

void calcNumberOfElements(const char *fname) {
    fstream f(fname, ios::in|ios::binary);
    
    if(f.is_open()) {
        int second, secondLast;
    
        f.seekg(0, ios::end);
        int fsize = f.tellg() / 4;
        
        if (fsize == 0) cout << "Empty bin file" << endl;
        
        if (fsize >= 2) { 
            // finding value of second element
            f.seekg(4);
            f.read((char*)&second, 4);
            // finding value of second last element
            f.seekg(-8, ios::end);
            f.read((char*)&secondLast, 4);
        };
    
    
        int amount = 0;
        int n;
        f.seekg(0);
        f.read((char*)&n, 4);
        
        // actual counting of elements
        while (f) {
            if (n == second || n == secondLast) amount++;
            f.read((char*)&n, 4);
        }
        
        cout << "Amount of elements equal either to the second or to the second last element: " << amount << endl;
        
    } else cout << "Reading from bin file failed" << endl;

    f.close();
}

int main()
{
    writeIntoFile(); // needed to create bin file to read from
    printBinaryFileContent("numbers.bin");
    calcNumberOfElements("numbers.bin");
}

