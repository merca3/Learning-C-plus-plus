// Implement data sorting by Bubble sort. Sort the data in ascending order.
// Determine a running time dependence on the input size when data is randomly distributed. 
// Use 3 small input sizes (20-150) and 3 large input sizes (>10 000); with the same data, size run at least 10 tests.

#include <iostream>
#include <cstring>
#include <cmath>
#include <chrono>
using namespace std;

// Assigning different sizes for arrays, 3 for small and 3 for large
int sizeS1 = 20;
int sizeS2 = 70;
int sizeS3 = 150;

int sizeL1 = 10000;
int sizeL2 = 30000;
int sizeL3 = 70000;

// Function to fill in passed array with random numbers of different (also passed) amount of digits
void createArray (int array[], int digitAmount, int size) {
    int x = pow(10, digitAmount);

    for (int i = 0; i < size; i++){
        array[i] = rand() % x;
    }
}

// Function for Bubble sort
void bubbleSort (int array[], int size) {
    while (size > 0) {
        for (int i = 0; i < size-1; i++) {
            if (array[i] > array [i+1]) {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
        size--;
    }

}

// Print the array
void printArray (int array[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

void bubbleSortTimingBySize (int size, int digitAmount) {
    // Create and fill in array of size   
    int originalArray[size];
    createArray(originalArray, digitAmount, size);
    cout << "Size of original array: " << size << endl;
    cout << "Unsorted original array:" << endl; 
    printArray(originalArray, size);
    
    // Create array to copy into values from original array, so it's always unsorted in the beginning of the loop
    int arrayToSort[size];
    cout << "Execution time for Bubble sorting of array was: " << endl;
    for (int i = 0; i < 10; i++) { // repeat time testing for 10 times
        memcpy(arrayToSort, originalArray, size*sizeof(int)); // copies values without changing original array
        auto start = chrono::high_resolution_clock::now(); // start the timer
        bubbleSort(arrayToSort, size);
        auto stop = chrono::high_resolution_clock::now();  // stop the timer straight after sorting
        auto executionTime = chrono::duration_cast<chrono::nanoseconds>(stop - start);
        cout << i+1 << ". " << executionTime.count() << " nanoseconds" << endl;
        
    }
    cout << "Bubble sorted array:" << endl;
    printArray(arrayToSort, size);
    cout << endl;
}

int main() {
    int digitAmount;
    cout << "Enter amount of max digits: "; 
    cin >> digitAmount;
    cout << endl;
    
    bubbleSortTimingBySize(sizeS1, digitAmount);
    bubbleSortTimingBySize(sizeS2, digitAmount);
    bubbleSortTimingBySize(sizeS3, digitAmount);
    // For very large arrays
    // bubbleSortTimingBySize(sizeL1, digitAmount);
    // bubbleSortTimingBySize(sizeL2, digitAmount);
    // bubbleSortTimingBySize(sizeL3, digitAmount);
}




