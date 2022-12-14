#include <iostream>
#include <vector>
#include "two_day_package.h"
#include "overnight_package.h"

using namespace std;

double calculateAllCost(const vector<Package *> &packages)
{
    double sum{0.0};
    for (auto *package : packages)
        sum += package->calculateCost();
    return sum;
}

void printPackagesInfo(const vector<Package *> &packages)
{
    for (auto *package : packages)
        package->printAllInfo();
}

int main()
{
    Package p1{
        "Bugs Bunny", "Baker street 21", "Dublin", "GA", "184234",
        "Donald Duck", "Flower street 1", "Dublin", "GA", "184236",
        2, 10};
    Two_Day_Package p2{
        "Bugs Bunny", "Baker street 21", "Dublin", "GA", "184234",
        "Mickey Mouse", "Oak street 125-1", "Dublin", "GA", "184231",
        3, 15, 10.25};
    Overnight_Package p3{
        "Bugs Bunny", "Baker street 21", "Dublin", "GA", "184234",
        "Minney Mouse", "Oak street 125-2", "Dublin", "GA", "184239",
        2, 15, 10.5};
    vector<Package *> packages;
    packages.push_back(&p1);
    packages.push_back(&p2);
    packages.push_back(&p3);

    printPackagesInfo(packages);
    cout << "Cost of all packages: " << calculateAllCost(packages) << "$" << endl;
}
