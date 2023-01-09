/******************************************************************************

3. Write C++ program to process sequence of integer values of type list<int>: 
increase all elements by 1 those equal either to the second or to the second last element (except themselves). 
E.g., {1,3,3,3,4,1,4}→{2,3,4,4,4,1,4}.

*******************************************************************************/
#include <iostream>
#include <list>

using namespace std;

void printList(list <int> &a) {
    auto i = a.begin();
    while (i != a.end()) {
        cout << *i << " ";
        i++;
    }
    cout << endl;
};

void incIfEqToSecOrSecLast(list<int> &a) {
    int counter = 1;
    int listSize = a.size();
    int second, secondLast;

    // first going through list to find values of second and second last elements
    auto i = a.begin();
    while (i != a.end()) {
        if (counter == 2) second = *i;
        if (counter == listSize - 1) secondLast = *i;
        i++;
        counter++;
    }
    cout << "Second element: "<< second  << endl;
    cout << "Second last element:  " << secondLast << endl;
    
    // now increasing the values if passing condition of the task
    counter = 1;
    i = a.begin();
    while (i!=a.end()) {
        if (counter != 2 && counter != listSize - 1) {  // didn't put everything into one if to logic is separated
            if (*i == second || *i == secondLast) {     // otherwise can be difficult to follow up with conditions
                *i+=1;
            };
        };
        
        i++;
        counter++;
    }
}

int main()
{
    list<int> a = {1, 3, 3, 3, 4, 1, 4};
    cout << "Initial list: ";
    printList(a);
    cout << "----------------------------" << endl;
    incIfEqToSecOrSecLast(a);
    cout << "----------------------------" << endl;
    cout << "Changed list: ";
    printList(a);
}
