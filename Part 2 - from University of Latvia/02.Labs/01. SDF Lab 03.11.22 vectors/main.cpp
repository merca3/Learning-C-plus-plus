#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v(4, 100); // can use with list

    v.push_back(25);
    v.push_back(13);

    vector<int>::iterator x = v.begin() + 3; // + 3 doesn't work with list
    // neeed this x++ to get it working

    x = v.insert(x, 15);

    v[5] = 7; // doesn't work with list

    v.erase(v.begin());

    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << ' ';
    }
    cout << endl;
}
