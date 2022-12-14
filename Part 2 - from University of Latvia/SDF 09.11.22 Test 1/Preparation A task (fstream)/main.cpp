/******************************************************************************

A[10]. Given text file. Write program in C++ to process the file line by line. It’s allowed to use C++-
style character strings.
Function lastLineNumWithMoreDigits, which calculates number of the last specific line (numbering starts
with 0) one to have more digits than in previous line. Example #1 (with // to denote newline). File:
“a12//b123//c3//d789//e345”, answer 3 (Comment: line “d789”). Example #2 (with // to denote newline).
File: “a12//b23//c3”, answer -1 (Comment: No such lines).

*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fin("text.txt", ios::in);
    string s;
    int digitAmount = -1;
    int prevDigitAmount = -1;
    int lineAnswer = -1;
    int lineNumber = 0;

    if (fin.is_open())
    {
        while (getline(fin, s))
        {
            // cout << s << endl;

            if (digitAmount != -1)
            { // checking first line
                prevDigitAmount = digitAmount;
            }

            digitAmount = 0;
            for (int i = 0; i < s.length(); ++i)
            {
                if (isdigit(s[i]))
                    digitAmount++;
            }

            if (digitAmount > prevDigitAmount && prevDigitAmount != -1)
            {
                lineAnswer = lineNumber;
            }

            // cout << "Digit amount: " << digitAmount << endl;
            // cout << "Line number: " << lineNumber << endl;

            lineNumber++;
        }
        if (lineAnswer >= 0)
        {
            cout << "Answer line: " << lineAnswer << endl;
        }
        else
            cout << "No such line" << endl;

        fin.close();
    }
    else
        cout << "Opening failed" << endl;
}