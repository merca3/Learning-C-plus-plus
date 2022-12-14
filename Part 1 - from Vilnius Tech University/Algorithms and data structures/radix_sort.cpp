#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;

// Assigning 3 different sizes for arrays
int size1 = 20;
int size2 = 70;
int size3 = 150;

// Function to fill in passed array with random numbers of different (also passed) amount of digits
void createSmallArray(int array[], int digitAmount, int size)
{

    int x = pow(10, digitAmount);

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % x;
    }
}

// Finding the biggest element of the array
int getMax(int array[], int arraySize)
{
    int max = array[0];
    for (int i = 1; i < arraySize; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place)
{
    const int max = 10;
    int output[size];
    int count[max];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    // Calculate count of elements
    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    // Calculate cumulative count
    for (int i = 1; i < max; i++)
        count[i] += count[i - 1];

    // Place the elements in sorted order
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

// Function for Radix sort
void radixSort(int array[], int size)
{

    // Get maximum element
    int max = getMax(array, size);

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}

// Print the array
void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int digitAmount;
    cout << "Enter amount of max digits: ";
    cin >> digitAmount;
    cout << endl;

    // Create and fill in first array of size1
    int a1[size1];
    createSmallArray(a1, digitAmount, size1);

    cout << "Size of the array a1: " << size1 << endl;
    cout << "Unsorted array a1:" << endl;
    printArray(a1, size1);
    cout << "Radix sorted array a1:" << endl;
    auto start1 = chrono::high_resolution_clock::now(); // start the timer
    radixSort(a1, size1);
    auto stop1 = chrono::high_resolution_clock::now(); // stop the timer straight after sorting
    auto executionTime1 = chrono::duration_cast<chrono::nanoseconds>(stop1 - start1);
    printArray(a1, size1);
    cout << "Execution time for Radix sorting of a1 was: " << executionTime1.count() << endl;
    cout << endl;

    // Create and fill in second array of size2
    int a2[size2];
    createSmallArray(a2, digitAmount, size2);

    cout << "Size of the array a2: " << size2 << endl;
    cout << "Unsorted array a2:" << endl;
    printArray(a2, size2);
    cout << "Radix sorted array a2:" << endl;
    auto start2 = chrono::high_resolution_clock::now(); // start the timer
    radixSort(a2, size2);
    auto stop2 = chrono::high_resolution_clock::now(); // stop the timer straight after sorting
    auto executionTime2 = chrono::duration_cast<chrono::nanoseconds>(stop2 - start2);
    printArray(a2, size2);
    cout << "Execution time for Radix sorting of a2 was: " << executionTime2.count() << endl;
    cout << endl;

    // Create and fill in third array of size3
    int a3[size3];
    createSmallArray(a3, digitAmount, size3);

    cout << "Size of the array a3: " << size3 << endl;
    cout << "Unsorted array a3:" << endl;
    printArray(a3, size3);
    cout << "Radix sorted array a3:" << endl;
    auto start3 = chrono::high_resolution_clock::now(); // start the timer
    radixSort(a3, size3);
    auto stop3 = chrono::high_resolution_clock::now(); // stop the timer straight after sorting
    auto executionTime3 = chrono::duration_cast<chrono::nanoseconds>(stop3 - start3);
    printArray(a3, size3);
    cout << "Execution time for Radix sorting of a3 was: " << executionTime3.count() << endl;
    cout << endl;
}
