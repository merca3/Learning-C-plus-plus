#include <iostream> // pre-processor command
#include <vector>
using namespace std;
// always to be used so we can avoid std::cout etc.

struct Employee
{                      // structure - record
    char firstInitial; // string
    char lastInitial;
    int employeeNumber; // number
    double salary;      // number with commas
    void printInfo()
    {
        cout << lastInitial << ", " << firstInitial << " numbered "
             << employeeNumber << " earning " << salary << endl;
    }
};

void printInfo(const Employee &e)
{
    // same stuff with e.firstInitial etc.
}

int main()
{
    cout << "Hello World \n"; // or use << endl
    cout << "Hello Again" << endl;
    printf("abc\n");

    Employee emp01{'A', 'B', 100, 10'000.5};

    int i{5}; // int i = 5 traditional way
    cout << emp01.salary << " | " << i << endl;

    vector<Employee> empList;
    empList.push_back(emp01);
    empList.push_back({'B', 'B', 101, 10'000});

    cout << empList[1].employeeNumber << endl;

    for (auto elem : empList)
    { // forEach loop
        elem.printInfo();
    }

    return 0;
}
