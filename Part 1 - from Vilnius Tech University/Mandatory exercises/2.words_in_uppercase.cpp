/******************************************************************************

Read a sequence of words from cin and store the values a vector.
After you’ve read all the words, process the vector and change each word to uppercase.
Print the transformed elements, eight words to a line.
(Hint: use <cctype> library to convert symbols to uppercase)

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    vector<string> randomWords;
    string word;
    cout << "Enter a sequence of 8 words: " << endl;
    for (int i = 0; i < 8; ++i)
    {
        cin >> word;
        randomWords.push_back(word);
    }

    cout << "You've entered those words: ";
    for (string el : randomWords)
    {
        cout << el << " ";
    }
    cout << endl;

    cout << "Entered those words in uppercase: ";
    for (string &el : randomWords)
    {
        for (char &letter : el)
        {
            letter = toupper(letter);
        }
        cout << el << " ";
    }

    return 0;
}
