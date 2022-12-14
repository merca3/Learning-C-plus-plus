/******************************************************************************

B. Given text file. Write program in C++ to process the file line by line.
B1[5]. Function countExtraAdjacentSpaces, which counts excessive spaces
(any sequence of spaces of length n contains n-1 excessive spaces).
E.g. (* denotes space), “alpha***beta**gamma” → 3

Function removeExtraAdjacentSpaces, which rewrites the text of f to another
file the way all extra adjacent spaces are removed (any sequence of spaces is replaced by one space).
E.g. (* denotes space) “*alpha*beta***gamma*******delta” → “*alpha*beta*gamma*delta”

*******************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fin("text.txt", ios::in);
    string s;
    int count = 0;

    if (fin.is_open())
    {
        while (getline(fin, s))
        {

            cout << "Original text:" << endl;
            cout << s << endl;

            string t;
            for (int i = 0; i < s.length(); ++i)
            {
                if (s[i] == '*' and s[i + 1] == '*')
                    count++;
                else
                    t += s[i];
            }

            cout << "Cleared text:" << endl;
            cout << t << endl;
        }
        cout << "Symbols removed: " << count << endl;
        fin.close();
    }
    else
        cout << "Opening failed" << endl;
}