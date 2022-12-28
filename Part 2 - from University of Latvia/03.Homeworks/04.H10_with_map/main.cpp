/******************************************************************************

Create program in C++ using STD map. For details see Lab requirements.

H10. Read text from two given text files. Text in both given file contains identified words.
One line in file is one word in format
<integer ID> <Word max 30 characters>
Merge both files in third file. Print data in third file in descending order by ID value.
The same ID may not appear twice in third file. If two words have the same ID, concatenate them in third file.

TEST:       INPUT (text1.txt file)          INPUT (text2.txt file)      OUTPUT (result.txt file or console)
---------------------------------------------------------------------------------------------------------------------
1           No text1.txt file               Empty text2.txt file        in console:
                                                                        "There is an issue with reading from file or writing into one"
---------------------------------------------------------------------------------------------------------------------
2           Empty text1.txt file            No text2.txt file           in console:
                                                                        "There is an issue with reading from file or writing into one"
---------------------------------------------------------------------------------------------------------------------
3           1 Yellow                        Empty text2.txt file        in console:
            3 Red                                                       "File text2.txt is empty"
            5 White                                                     "Please add data in the file"
            7 Green
            9 Orange
            10 Black
            11 Blue
            12 Purple
            13 Pink
---------------------------------------------------------------------------------------------------------------------
4           Empty text1.txt file            1 Apple                     in console:
                                            2 Banana                    "File text1.txt is empty"
                                            3 Cherry                    "Please add data in the file"
                                            4 Pear
                                            5 Strawberry
                                            6 Kivi
                                            7 Watermelon
                                            8 Orange
---------------------------------------------------------------------------------------------------------------------
5           1 Yellow                        1 Apple                     13 Pink
            3 Red                           2 Banana                    12 Purple
            5 White                         3 Cherry                    11 Blue
            7 Green                         4 Pear                      10 Black
            9 Orange                        5 Strawberry                9 Orange
            10 Black                        6 Kivi                      8 Orange
            11 Blue                         7 Watermelon                7 GreenWatermelon
            12 Purple                       8 Orange                    6 Kivi
            13 Pink                                                     5 WhiteStrawberry
                                                                        4 Pear
                                                                        3 RedCherry
                                                                        2 Banana
                                                                        1 YellowApple

********************************************************************************************************************/

#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main()
{
    map<int, string, greater<int>> texts; // greater<int> as additional parameter sorts map by descending order
    fstream text1("text1.txt", ios::in);
    fstream text2("text2.txt", ios::in);
    fstream result("result.txt", ios::out);

    string id1, id2, word1, word2;

    if (text1.is_open() && text2.is_open() && result.is_open())
    {
        // reading from first text1 file
        while (text1)
        {
            getline(text1, id1, ' '); // reads first part of line into id1

            if (id1.empty())
            { // validation in case of empty file
                cout << "File text1.txt is empty" << endl;
                cout << "Please add data in the file" << endl;
                return 0;
            }

            text1 >> word1;           // reads second part of line into word1
            texts[stoi(id1)] = word1; // stoi(str) converts id1 string to integer
        };

        // reading from second text2 file
        while (text2)
        {
            if (text2.eof())
                break;                // this break is needed so it doesn't read last line twice...
            getline(text2, id2, ' '); // same with id2 and word2 as in text1

            if (id2.empty())
            {
                cout << "File text2.txt is empty" << endl;
                cout << "Please add data in the file" << endl;
                return 0;
            }

            text2 >> word2;
            texts[stoi(id2)] += word2; // concatination of string
        };

        // printing into result.txt file
        for (auto &elem : texts)
        {
            result << elem.first << ' ' << elem.second << endl;
        }
    }
    else
    {
        // in case if there is no files with names text1.txt and text2.txt or some issue with reading/writing
        cout << "There is an issue with reading from file or writing into one" << endl;
        return 0;
    }

    // closing all streams
    text1.close();
    text2.close();
    result.close();
}
