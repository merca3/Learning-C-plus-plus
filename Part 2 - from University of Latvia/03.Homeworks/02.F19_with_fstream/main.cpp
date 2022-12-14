/********************************************************************************************************************

Create program in C++ to process text files. Reading from files should be carried out line per line.
It is no allowed to store copy of the contents of file in the memory. For details see Lab requirements.

F19. Read text from given text file. Print into another text file frequency table of all letters (case sensitive)
from text in given text file. Write into output file how many times each letter is used in given text file.

TEST:       INPUT (From.txt file)           OUTPUT (To.txt file)            OUTPUT (Console)
---------------------------------------------------------------------------------------------------------------------
1           No From.txt file                -                               There is an issue with reading from file
---------------------------------------------------------------------------------------------------------------------
2           Empty From.txt file             -                               There are no letters in the file
---------------------------------------------------------------------------------------------------------------------
3           Hello World!                    Frequency of letter l: 3        -
                                            Frequency of letter o: 2
                                            Frequency of letter r: 1
                                            Frequency of letter e: 1
                                            Frequency of letter d: 1
                                            Frequency of letter W: 1
                                            Frequency of letter H: 1
---------------------------------------------------------------------------------------------------------------------
4           P@ssword123                     Frequency of letter s: 2        -
                                            Frequency of letter w: 1
                                            Frequency of letter r: 1
                                            Frequency of letter o: 1
                                            Frequency of letter d: 1
                                            Frequency of letter P: 1
---------------------------------------------------------------------------------------------------------------------
5           !@£$%^;-+1234567890             -                               There are no letters in the file

********************************************************************************************************************/
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    fstream readFrom, readTo;
    string readText;
    int max, letter;
    int frequency[123] = {0}; // will contain frequency of symbol with numeric code from ASCII table, max we need is 122 (last letter)
    bool areLetters = false;

    // Reading from From.txt file
    readFrom.open("From.txt");
    if (readFrom.is_open())
    {
        while (readFrom)
        {
            for (int i = 0; i < readText.length(); ++i)
            {
                frequency[(unsigned char)readText[i]]++; // counts frequency of every character
            }
            getline(readFrom, readText); // reads from file into readText
        };
    }
    else
    {
        cout << "There is an issue with reading from file" << endl; // in case if there is no file with name From.txt
        return 0;
    }
    readFrom.close();

    // Writing to To.txt file
    readTo.open("To.txt", ios::out); // optional ios::out added to clear the file before writing to it
    for (int i = 0; i < 52; ++i)
    { // so as not to repeat the cycle more than the amount of letters (small + capital)
        for (int j = 0; j < 123; ++j)
        { // 123 is frequency array size
            if ((j > 64 and j < 91) or (j > 96 and j < 123))
            { // count only letters, which are in these ASCII character code amplitudes
                if (frequency[j] > 0)
                {
                    max = frequency[j];
                    for (int k = 0; k < 123; ++k)
                    { // compare every element with max to find the maximum frequency
                        if ((k > 64 and k < 91) or (k > 96 and k < 123))
                        {
                            if (max <= frequency[k])
                            {
                                max = frequency[k];
                                letter = k;
                            }
                        }
                    }
                    readTo << "Frequency of letter " << (char)letter << ": " << max << endl;
                    frequency[letter] = 0;
                    areLetters = true;
                }
            }
        }
    }
    readTo.close();

    if (!areLetters)
        cout << "There are no letters in the file" << endl;
    return 0;
}