/******************************************************************************
 
Katrina Merca - km11104

1. Given text file. Write program in C++ to process the file line by line, 
which prints the first line containing two equal adjacent digits. 
Example (with // to denote newline).
Example 1: “a12//world is fine//c3//d789//3x abc”, answer: no such line.
Example 2: “a12//world is fine//c33!//d7899y//3x abc”, answer: “c33!”.

*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream f("text.txt", ios::in);
    string s, answerLine = "";

    if (f.is_open()) { // basic validation
        while (getline(f, s)) {
            if (answerLine != "") break; // breaks the while loop if there is already result

            for (int i = 0; i < s.length(); ++i) {
                if (isdigit(s[i]) && isdigit(s[i+1]) && (s[i] == s[i+1])) {
                    answerLine = s;
                    cout << "Answer line: " << answerLine << endl;
                    break; // to break internal for loop
                }
            }

        }
        if (answerLine == "") cout << "No such line" << endl;
        
    } else cout << "Opening failed" << endl;
    
    f.close();
}