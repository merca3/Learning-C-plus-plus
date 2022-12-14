/******************************************************************************

A. Given text file. Write program in C++ to process the file line by line.
A1[10]. Program lineCount2Plus, which calculates amount of lines containing at least 2 digits.
Example (with // to denote newline). File: “a12//world is fine//c3//d789//3x abc”, answer 2.

A2[16]. Function printLongestLineOfMostDigits, prints the longest line out of those with the biggest amount of digits.
Example #1 (with // to denote newline). File: “a12//b123//c3 hello world//d789xy//e345z”, answer “d789xy” (Comment: this is the longest line containing 3 digits, not the longest line in general).

*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fin("text.txt", ios::in);
    string stringLine;
    int digitAmount;
    int lineAmount = 0;

    // for A2
    string longestLine;
    int maxDigitAmount = 0;

    if (fin.is_open())
    {
        while (getline(fin, stringLine))
        {
            digitAmount = 0; // sets amount to 0 in the beginning of every line
            for (int i = 0; i < stringLine.length(); ++i)
            {
                if (isdigit(stringLine[i])) // checks if character is a digit
                    digitAmount++;
            }

            if (digitAmount >= 2)
            {
                lineAmount++; // counts lines which have at least 2 digits
            }

            // For A2
            // Checks both amount of digits and line length
            if (digitAmount >= maxDigitAmount && stringLine.length() > longestLine.length())
            {
                maxDigitAmount = digitAmount;
                longestLine = stringLine; // assigns the longest line value of read line
                // if there are multiple lines, which have same amount of digits and
                // character, the first one will be chosen as the longest one
            }
        }

        // basic validation
        if (lineAmount > 0)
        {
            cout << "There are " << lineAmount << " lines which have at least 2 digits" << endl;
            // for A2
            cout << "The longest line out of those with the biggest amount of digits is: " << longestLine << endl;
        }
        else
            cout << "No such lines" << endl;

        fin.close();
    }
    else
        cout << "Opening failed" << endl;
}
