#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// instead of reading from file, will read from vector
vector<int> inputVector{87, 32, 19, 27, 7, 28, 99, 46};
queue<int> inputQueue;

// let's assume the full queue consists of 10 elements
int fullQueueSize = 10;

void displayQueue()
{
    queue queueToDisplay = inputQueue;
    if (queueToDisplay.empty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Existing queue is: ";
        while (!queueToDisplay.empty())
        {
            cout << queueToDisplay.front() << " ";
            queueToDisplay.pop();
        };
    };
    cout << endl;
};

void printOperationsList()
{
    cout << "----------------------------" << endl;
    cout << "Choose one of the following options:" << endl;
    cout << "1 - enqueue/add element" << endl;
    cout << "2 - dequeue/delete element" << endl;
    cout << "3 - check if empty" << endl;
    cout << "4 - check if full" << endl;
    cout << "5 - print a queue" << endl;
    cout << "6 - clear a queue" << endl;
    cout << "7 - show the size of a queue" << endl;
    cout << "----------------------------" << endl;
    cout << "Enter 0 to quit" << endl;
    cout << endl;
};

void chooseOperation(int operation)
{
    switch (operation)
    {
    case 1:
    {
        if (inputQueue.size() == fullQueueSize)
        {
            cout << "The queue is already full!" << endl;
            cout << "Clear the queue or delete an element before adding a new one" << endl;
        }
        else
        {
            cout << "Enter the element which to add: ";
            int newElement;
            cin >> newElement;
            cout << endl;
            inputQueue.push(newElement);
        };
    };
    break;
    case 2:
        inputQueue.pop();
        break;
    case 3:
    {
        if (inputQueue.empty())
        {
            cout << "Queue is empty" << endl;
        }
        else
            cout << "Queue is NOT empty" << endl;
    };
    break;
    case 4:
    {
        int newSize = inputQueue.size();
        if (newSize == fullQueueSize)
        {
            cout << "Queue is full" << endl;
        }
        else
            cout << "Queue is NOT full" << endl;
    };
    break;
    case 5:
        displayQueue();
        break;
    case 6:
        while (!inputQueue.empty())
        {
            inputQueue.pop();
        };
        break;
    case 7:
        cout << "The size of the queue is: " << inputQueue.size() << endl;
        break;
    default:
        cout << "Invalid input: please enter a number from 1 to 7!" << endl;
        break;
    };
    return;
};

int main()
{
    cout << "The input queue is: {";
    for (auto elem : inputVector)
    {
        cout << elem << ' ';
        inputQueue.push(elem);
    }
    cout << "}" << endl;

    int operation;
    do
    {
        printOperationsList();
        cout << "Chosen operation: ";
        cin >> operation;
        chooseOperation(operation);

    } while (operation != 0);
    return 0;
};
