#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool freqDesc(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

bool freqAsc(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}

int dv(int a, int b)
{
    if (b == 0)
        throw "Division by 0";
    else
        return a / b;
}
int formula(int a, int b)
{
    return dv(10, (a + dv(5, b)));
}

int main()
{
    list<string> aa = {"if", "you", "add", "new", "items", "to", "a", "list", "the",
                       "new", "items", "will", "be", "placed", "at", "the", "end", "of", "the", "list"};

    map<string, int> st;
    for (auto &a : aa)
    {
        st[a]++;
    };

    vector<pair<string, int>> st2;

    for (auto &p : st)
    {
        cout << p.first << " : " << p.second << endl;
        st2.push_back(p);
    };
    cout << "-------------------------------------" << endl;

    sort(st2.begin(), st2.end(), freqDesc);
    for (auto &p : st2)
    {
        cout << p.first << " : " << p.second << " ";
    }
    cout << endl;
    cout << "-------------------------------------" << endl;

    sort(st2.begin(), st2.end(), freqAsc);
    for (auto &p : st2)
    {
        cout << p.first << " : " << p.second << " ";
    }
    cout << endl;

    try
    {
        cout << formula(1, 5) << endl;  // 5
        cout << formula(0, 1) << endl;  // 2
        cout << formula(1, 0) << endl;  // Division by 0, block execution ends here
        cout << formula(5, -1) << endl; // Division by 0
        cout << formula(1, 2) << endl;  // 3
    }
    catch (const char *e)
    {
        cout << e << endl;
    }
    catch (int e)
    {
        cout << "Error code " << e << endl;
    }
    catch (...)
    {
        cout << "Default error" << endl;
    }
}

void fromTeacher()
{
    // no map
    list<string> aa = {"if", "you", "add", "new", "items", "to",
                       "a", "list", "the", "new", "items", "will", "be", "placed",
                       "at", "the", "end", "of", "the", "list"};
    list<pair<string, int>> st;
    for (auto &a : aa)
    {
        bool found = false;
        for (auto i = st.begin(); i != st.end(); ++i)
        {
            if (i->first == a)
            {
                i->second++;
                found = true;
                break;
            }
        }
        if (found == false)
        {
            st.push_back(pair<string, int>(a, 1));
        }
    }
    for (auto &s : st)
    {
        cout << s.first << " " << s.second << endl;
    }
}
